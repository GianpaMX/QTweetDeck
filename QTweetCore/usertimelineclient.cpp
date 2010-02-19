#include "usertimelineclient.h"

using namespace QTweet;

UserTimeLineClient::UserTimeLineClient(const User &user, QObject *parent) : AbstractUpdatableClient(parent) {
  this->user = user;
}
UserTimeLineClient::UserTimeLineClient(const QString &screen_name, QObject *parent) : AbstractUpdatableClient(parent) {
  this->user.setScreenName(screen_name);
}
UserTimeLineClient::UserTimeLineClient(qulonglong id, QObject *parent) : AbstractUpdatableClient(parent) {
  this->user.setUserId(id);
}

Reply *UserTimeLineClient::requestDefaultData() {
  if(user.userid())
    return requestUserTimeLine(user.userid());
  return requestUserTimeLine(user.screenname());
}
