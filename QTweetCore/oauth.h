#ifndef OAUTH_H
#define OAUTH_H

#include <QtOAuth>
#include <QByteArray>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

class QTWEETCORESHARED_EXPORT QTweet::OAuth {
  public:
    OAuth();

    static void setConsumer(const QByteArray &key, const QByteArray &secret);
  protected:
    static QOAuth::Interface *qoauth;
    static QByteArray consumer_key;
    static QByteArray consumer_secret;

    QByteArray token;
    QByteArray token_secret;
};

#endif // OAUTH_H
