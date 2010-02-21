#include <QtXml>
#include <QtSql>
#include <QDebug>
#include "abstractclient.h"
#include "tweets.h"
#include "cache.h"

using namespace QTweet;

QNetworkAccessManager* AbstractClient::networkManager = new QNetworkAccessManager;

AbstractClient::AbstractClient(QObject *parent) : QObject(parent) {
  requestMapper = new QSignalMapper();
  requestCounter = 0;
  connect(requestMapper, SIGNAL(mapped(int)), this, SLOT(replyed(int)));
  connect(requestMapper, SIGNAL(mapped(QString)), this, SLOT(replyed(QString)));
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
  } else {
    QDomElement parent_element;
    parent_element = root.tagName() == "statuses" ? root.firstChildElement("status") :
                     root.tagName() == "status" ? root :
                     root.tagName() == "users" ? root.firstChildElement("user") :
                     root.tagName() ==  "user" ? root :
                     QDomElement();
    while (!parent_element.isNull()) {
      QDomElement child_element = root.tagName() == "statuses" || root.tagName() == "status" ? parent_element.firstChildElement("user") :
                                 root.tagName() == "users" || root.tagName() ==  "user" ? parent_element.firstChildElement("status") :
                                 QDomElement();

      Status status;
      User & user = status;

      QDomElement &status_element = root.tagName() == "statuses" || root.tagName() == "status" ? parent_element : child_element;
      QDomElement &user_element = root.tagName() == "statuses" || root.tagName() == "status" ? child_element : parent_element;


      status.readDomElement(status_element);
      user.readDomElement(user_element);

      if( Cache::isEnabled() ) {
        Cache &cache = Cache::Data();
        if (cache.error().type() == QSqlError::NoError) {
          cache << status;
          if( status.inreplytouser() != 0 && (status.inreplytouser()->userid() != 0 || status.inreplytoscreenname() != "") ) {
            cache >> *status.inreplytouser();
          }
          if( status.inreplytostatus() != 0 ) {
            cache >> *status.inreplytostatus();
          }
        } else
          qDebug() << "Cache ERROR";
      }

      statuses->appendTweet(status);

      QString nextSiblingElement = root.tagName() == "statuses" || root.tagName() == "status" ? "status" :
                                 root.tagName() == "users" || root.tagName() ==  "user" ? "user" :
                                 QString();
      parent_element = parent_element.nextSiblingElement(nextSiblingElement);
    }
  }

  processReply(i, statuses);

  reply->deleteLater();
}

int AbstractClient::request(const QString & url, QOAuth::ParamMap map) {
  QString requestUrl = auth.requestUrl(url, map);

  uint request_id = requestCounter++;

//  qDebug() << requestUrl;

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
