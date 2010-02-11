#include "oauth.h"

using namespace QTweet;

QOAuth::Interface *OAuth::qoauth = new QOAuth::Interface;
QByteArray OAuth::consumer_key;
QByteArray OAuth::consumer_secret;

OAuth::OAuth() {
}

void OAuth::setConsumer(const QByteArray &key, const QByteArray &secret) {
  OAuth::consumer_key = key;
  OAuth::consumer_secret = secret;
}
