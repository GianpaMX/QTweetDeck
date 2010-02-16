#include <QDebug>

#include "client.h"

using namespace QTweet;

Client::Client(QObject *parent) : AbstractClient(parent) {
}

Client::~Client() {
  QMapIterator< int, QPointer<Reply> > i(replys);
  while (i.hasNext()) {
    i.next();
    if( i.value() ) delete replys[i.key()];
  }
}

Reply* Client::requestPublicTimeLine() {
  StatusList *statuses = new StatusList;
  Reply *r = new Reply(*statuses);
  int i = request("http://twitter.com/statuses/public_timeline.xml");

  replys.insert(i, r);

  return r;
}

Reply* Client::requestUserTimeLine(qulonglong user_id) {
  QOAuth::ParamMap parameters;
  parameters.insert("user_id", QString::number(user_id).toAscii());
  return requestUserTimeLine(parameters);
}

Reply* Client::requestUserTimeLine(const QString &screen_name) {
  QOAuth::ParamMap parameters;
  parameters.insert("screen_name", screen_name.toAscii());
  return requestUserTimeLine(parameters);
}

Reply* Client::requestUserTimeLine(QOAuth::ParamMap parameters) {
  StatusList *statuses = new StatusList;
  Reply *r = new Reply(*statuses);

  int i = request("http://twitter.com/statuses/user_timeline.xml", parameters);

  replys.insert(i, r);

  return r;
}

Reply* Client::requestStatus(qulonglong status_id) {
  StatusList *statuses = new StatusList;
  Reply *r = new Reply(*statuses);

  int i = request( QString("http://twitter.com/statuses/show/%1.xml").arg(QString::number(status_id)) );

  replys.insert(i, r);

  return r;
}

void Client::processReply(int i, Tweets & tweets) {
  Reply *r = replys.value(i);
  r->setData(tweets);
}

void Client::notAuthorized(int i) {
  Reply *r = replys.value(i);
  r->setPrivateWeets(true);
}
