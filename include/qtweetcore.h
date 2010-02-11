#ifndef QTWEETCORE_H
#define QTWEETCORE_H

#include <QDateTime>
#include <QString>
#include <QMap>

namespace QTweet {
  class AbstractClient;
  class Client;
  class User;
  class Status;
  class StatusList;
  class Reply;

  class Tweet;
  class Tweets;

  class OAuth;

  QDateTime fromStringDateTime(const QString& string);
  void setConsumer(const QByteArray &key, const QByteArray &secret);
}

#endif // QTWEETCORE_H
