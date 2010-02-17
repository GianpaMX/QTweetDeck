#include <QtXml>
#include <QDebug>
#include "abstractclient.h"
#include "tweets.h"

using namespace QTweet;

QNetworkAccessManager* AbstractClient::networkManager = new QNetworkAccessManager;

AbstractClient::AbstractClient(QObject *parent) : QObject(parent) {
  requestMapper = new QSignalMapper();
  requestCounter = 0;
  connect(requestMapper, SIGNAL(mapped(int)), this, SLOT(replyed(int)));
}

AbstractClient::~AbstractClient() {
  if(requestMapper) delete requestMapper;
}

void AbstractClient::replyed(int i) {
  QPointer<QNetworkReply> reply = static_cast<QNetworkReply*>(requestMapper->mapping(i));
  Tweets *statuses = createEmptyData();
  QDomDocument domDocument;
  QString error;

  if(!domDocument.setContent(reply, true, &error)) {
    qDebug() << "AbstractClient::replyed" << error;

    emit errorReplyed(i, error);
    reply->deleteLater();
    return;
  }
  QDomElement root = domDocument.documentElement();
  if(root.tagName() == "hash") {
    notAuthorized(i);
    emit errorReplyed(i, root.firstChildElement("error").text());
  } else if(root.tagName() == "statuses" || root.tagName() == "status") {
    QDomElement status_element = root.tagName() == "statuses" ? root.firstChildElement("status") : root;
    while (!status_element.isNull()) {
      QDomElement user_element = status_element.firstChildElement("user");

      Status status;
      User & user = status;

      status.readDomElement(status_element);
      user.readDomElement(user_element);

      statuses->appendTweet(status);

      status_element = status_element.nextSiblingElement("status");
    }
  } else if(root.tagName() == "users" || root.tagName() == "user") {
    QDomElement user_element = root.tagName() == "users" ? root.firstChildElement("user") : root;
    while (!user_element.isNull()) {
      QDomElement status_element = user_element.firstChildElement("status");

      Status status;
      User & user = status;

      status.readDomElement(status_element);
      user.readDomElement(user_element);

      statuses->appendTweet(status);

      user_element = user_element.nextSiblingElement("user");
    }
  }

  processReply(i, statuses);

  reply->deleteLater();
}

int AbstractClient::request(const QString & url, QOAuth::ParamMap map) {
  QString requestUrl = auth.requestUrl(url, map);

  uint request_id = requestCounter++;

  qDebug() << requestUrl;

  QNetworkRequest request;
  request.setUrl(QUrl(requestUrl));
  request.setRawHeader("User-Agent", "QTweetDeck");


  QNetworkReply *reply = AbstractClient::networkManager->get(request);
  connect(reply, SIGNAL(finished()), requestMapper, SLOT(map()));
  connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError)));

  requestMapper->setMapping(reply, request_id);

  return request_id;
}

void AbstractClient::slotError(QNetworkReply::NetworkError error) {
  qDebug() << "Error (AbstractClient): " << error;
}
