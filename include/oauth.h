#ifndef OAUTH_H
#define OAUTH_H

#include <QtOAuth>
#include <QByteArray>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

class QTWEETCORESHARED_EXPORT QTweet::OAuth {
  public:
    OAuth();
    ~OAuth();

    QString requestUrl(const QString &url, QOAuth::ParamMap map = QOAuth::ParamMap()) const;

    static void setConsumer(const QByteArray &key, const QByteArray &secret);
  protected:
    static QOAuth::Interface *qoauth;
    static QByteArray consumer_key;
    static QByteArray consumer_secret;
    static int instancesCounter;

    QByteArray token;
    QByteArray token_secret;
};

#endif // OAUTH_H
