#include "reply.h"

using namespace QTweet;

Reply::Reply(Tweets & value, QObject *parent) : QObject(parent), reply_data(&value) {
  private_tweets = false;
}

Reply::~Reply() {
  delete reply_data;
}

Tweets & Reply::data() {
  return *reply_data;
}
void Reply::setData(Tweets & value) {
  delete reply_data;
  reply_data = &value;
  emit dataReady();
}

bool Reply::privateTweets() const {
  return privateTweets();
}
void Reply::setPrivateWeets(bool value) {
  private_tweets = value;
}
