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
Reply* Client::requestUserTimeLine(const User &user) {
  StatusList *statuses = new StatusList;
  Reply *r = new Reply(*statuses);
  QMap<QByteArray, QByteArray> parameters;
  parameters.insert("user_id", QString::number(user.userid()).toAscii());

  int i = request("http://twitter.com/statuses/user_timeline.xml");

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
