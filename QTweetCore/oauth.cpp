#include "oauth.h"

using namespace QTweet;

QOAuth::Interface *OAuth::qoauth = 0;
int OAuth::instancesCounter = 0;

OAuth::OAuth() {
  if( OAuth::instancesCounter == 0 ) {
    OAuth::qoauth = new QOAuth::Interface;

    OAuth::qoauth->setConsumerKey(OAuth::consumer_key);
    OAuth::qoauth->setConsumerSecret(OAuth::consumer_secret);
  }
  OAuth::instancesCounter++;

  token = "";
  token_secret = "";
}

OAuth::~OAuth() {
  OAuth::instancesCounter--;

  if(OAuth::instancesCounter == 0)
    delete OAuth::qoauth;
}

QString OAuth::requestUrl(const QString &url, QOAuth::ParamMap map) const {
  QString urlCopy = url;
  QByteArray content;

  content = OAuth::qoauth->createParametersString(urlCopy, QOAuth::GET, token, token_secret, QOAuth::HMAC_SHA1, map, QOAuth::ParseForInlineQuery);
  return urlCopy.append(content);
}
