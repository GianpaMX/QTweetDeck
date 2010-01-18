#include <QByteArray>

#include "qtweetclient.h"
#include "qtweetstatus.h"

QTweetClient::QTweetClient(QObject * parent) : QObject(parent) {
    if(reply) delete reply;
    manager = new QNetworkAccessManager (this);
}

QTweetClient::~QTweetClient() {
    delete manager;
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
        error = "This isn't a statuses replay";
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
    QString text = xmlstatus.firstChildElement("text").text();
    status.setText(text);

    list << status;
}
