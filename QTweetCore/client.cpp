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
  return request_and_map("http://twitter.com/statuses/public_timeline.xml");
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
  return request_and_map("http://twitter.com/statuses/user_timeline.xml", parameters);
}

Reply* Client::requestStatus(qulonglong status_id) {
  return request_and_map( QString("http://twitter.com/statuses/show/%1.xml").arg(QString::number(status_id)) );
}

void Client::processReply(int i, Tweets *tweets) {
  Reply *r = replys.value(i);
  r->setData(tweets);
}

void Client::notAuthorized(int i) {
  Reply *r = replys.value(i);
  r->setPrivateWeets(true);
}

Reply* Client::requestUser(qulonglong user_id)  {
  QOAuth::ParamMap parameters;
  parameters.insert("user_id", QString::number(user_id).toAscii());
  return requestUser(parameters);
}

Reply* Client::requestUser(const QString &screen_name) {
  QOAuth::ParamMap parameters;
  parameters.insert("screen_name", screen_name.toAscii());
  return requestUser(parameters);
}

Reply* Client::requestUser(QOAuth::ParamMap parameters) {
  return request_and_map("http://twitter.com/users/show.xml", parameters);
}

Reply* Client::request_and_map(const QString &url, QOAuth::ParamMap parameters) {
  Tweets *statuses = createEmptyData();
  Reply *r = new Reply(statuses);

  int i = request(url, parameters);
  replys.insert(i, r);

  return r;
}

Reply* Client::requestUserFriends(qulonglong user_id) {
  QOAuth::ParamMap parameters;
  parameters.insert("user_id", QString::number(user_id).toAscii());
  return requestUserFriends(parameters);
}

Reply* Client::requestUserFriends(const QString &screen_name) {
  QOAuth::ParamMap parameters;
  parameters.insert("screen_name", screen_name.toAscii());
  return requestUserFriends(parameters);
}

Reply* Client::requestUserFriends(QOAuth::ParamMap parameters) {
  return request_and_map("http://twitter.com/statuses/friends.xml", parameters);
}

Reply* Client::requestUserFollowers(qulonglong user_id) {
  QOAuth::ParamMap parameters;
  parameters.insert("user_id", QString::number(user_id).toAscii());
  return requestUserFollowers(parameters);
}

Reply* Client::requestUserFollowers(const QString &screen_name) {
  QOAuth::ParamMap parameters;
  parameters.insert("screen_name", screen_name.toAscii());
  return requestUserFollowers(parameters);
}

Reply* Client::requestUserFollowers(QOAuth::ParamMap parameters) {
  return request_and_map("http://twitter.com/statuses/followers.xml", parameters);
}

Tweets* Client::createEmptyData() const {
  return new StatusList;
}
