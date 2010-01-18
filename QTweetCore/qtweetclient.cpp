#include <QByteArray>

#include "qtweetclient.h"
#include "qtweetstatus.h"

QTweetClient::QTweetClient(QObject * parent) : QThread(parent) {
    manager = new QNetworkAccessManager(this);
    secs = 0;
    connect(this, SIGNAL(beginRequest()), this, SLOT(requestPublicTimeLine()));
}
QTweetClient::QTweetClient(unsigned long refreshevery, QObject * parent) : QThread(parent) {
    manager = new QNetworkAccessManager(this);
    secs = refreshevery;
    connect(this, SIGNAL(beginRequest()), this, SLOT(requestPublicTimeLine()));
}

QTweetClient::~QTweetClient() {
    secs = 0;
    wait();
    
    if(reply) delete reply;
    if(manager) delete manager;
}

void QTweetClient::run() {
    while(secs) {
        sleep(secs);
        if(secs) emit beginRequest();
    }
}

void QTweetClient::setRefresh(unsigned long refreshevery) {
    secs = refreshevery;
    start();
}

void QTweetClient::requestPublicTimeLine() {
    if( reply != 0)
        return;

    QNetworkRequest request;
    request.setUrl(QUrl("http://twitter.com/statuses/public_timeline.xml"));
    request.setRawHeader("User-Agent", "QTweetDeck 0.1");

    reply = manager->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(replayPublicTimeLine()));
}

void QTweetClient::replayPublicTimeLine() {
    QTweetStatusList list;
    QDomDocument domDocument;
    QString error;

    if(!domDocument.setContent(reply, true, &error)) {
        emit publicTimeLine(list, error);
        return;
    }
    QDomElement root = domDocument.documentElement();
    if (root.tagName() != "statuses") {
        error = "This isn't a statuses public time line";
        emit publicTimeLine(list, error);
        return;
    }

    QDomElement status = root.firstChildElement("status");
    while (!status.isNull()) {
        addStatusElement(status, list);
        status = status.nextSiblingElement("status");
    }

    emit publicTimeLine(list, error);

    reply->deleteLater();
}


void QTweetClient::addStatusElement(const QDomElement& xmlstatus, QTweetStatusList& list) {
    QTweetStatus status;
    QString tmp;

    tmp = xmlstatus.firstChildElement("created_at").text();
    status.setCreatedAt(tmp);

    tmp = xmlstatus.firstChildElement("id").text();
    status.setId(tmp.toULongLong());

    tmp = xmlstatus.firstChildElement("text").text();
    status.setText(tmp);

    tmp = xmlstatus.firstChildElement("source").text();
    status.setSource(tmp);

    tmp = xmlstatus.firstChildElement("truncated").text();
    status.setTruncated(tmp == "true");

    tmp = xmlstatus.firstChildElement("in_reply_to_status_id").text();
    status.setInReplayToStatus(tmp.toLongLong());

    tmp = xmlstatus.firstChildElement("in_reply_to_user_id").text();
    status.setInReplayToUser(tmp.toLongLong());

    tmp = xmlstatus.firstChildElement("favorited").text();
    status.setFavorited(tmp == "true");

    tmp = xmlstatus.firstChildElement("in_reply_to_screen_name").text();
    status.setInReplayToScreenName(tmp);

//    tmp = xmlstatus.firstChildElement("user").text();
//    status.setCreatedAt(tmp);

    list << status;
}
