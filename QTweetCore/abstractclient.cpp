#include <QtXml>
#include "abstractclient.h"

using namespace QTweet;

QPointer<QNetworkAccessManager> AbstractClient::networkManager = 0;
QPointer<QSignalMapper> AbstractClient::requestMapper = 0;
int AbstractClient::requestCounter = 0;

AbstractClient::AbstractClient(QObject *parent) : QObject(parent) {
  if(!networkManager) networkManager = new QNetworkAccessManager;
  if(!requestMapper) {
      requestMapper = new QSignalMapper;

      connect(requestMapper, SIGNAL(mapped(int)), this, SLOT(replyed(int)));
  }
}

AbstractClient::~AbstractClient() {
  if(networkManager) delete networkManager;
  if(requestMapper) delete requestMapper;
}

void AbstractClient::replyed(int i) {
  QPointer<QNetworkReply> reply = dynamic_cast<QNetworkReply*>(requestMapper->mapping(i));
  StatusList statuses;
  QDomDocument domDocument;
  QString error;
  QString tagname, nexttagname;

  if(!domDocument.setContent(reply, true, &error)) {
      emit errorReplayed(i, error);
      return;
  }
  QDomElement root = domDocument.documentElement();
  if(root.tagName()== "statuses") {
    tagname = "status"; nexttagname = "user";
  } else if(root.tagName() == "users") {
    tagname = "user"; nexttagname = "status";
  }

  QDomElement element = root.firstChildElement(tagname);
  while (!element.isNull()) {
    Status status;
    User & user = status;

    for(int i=0;i<2 && !element.isNull();i++) {
      if(tagname == "user")
        user.readDomElement(element);
      else if(tagname == "status")
        status.readDomElement(element);

      qSwap(tagname, nexttagname);
      element = element.nextSiblingElement(tagname);
    }
    statuses << status;
  }

  processReply(i, statuses);

  reply->deleteLater();
}

int AbstractClient::request(const QString & url, QMap<QByteArray, QByteArray> parameters) {
  uint request_id = AbstractClient::requestCounter++;

  QNetworkRequest request;
  request.setUrl(QUrl(url));
  request.setRawHeader("User-Agent", "QTweetDeck");

  QPointer<QNetworkReply> reply = networkManager->get(request);
  connect(reply, SIGNAL(readyRead()), requestMapper, SLOT(map()));
  requestMapper->setMapping(reply, request_id);

  return request_id;
}
