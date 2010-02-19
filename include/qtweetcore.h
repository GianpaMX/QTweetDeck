#ifndef QTWEETCORE_H
#define QTWEETCORE_H

#include <QDateTime>
#include <QString>
#include <QMap>

namespace QTweet {
  class Creatable;

  class AbstractClient;
  class Client;
  class User;
  class Status;
  class StatusList;
  class Reply;

  class Tweet;
  class Tweets;

  class OAuth;

  class DataArrived;
  class Updatable;
  class AbstractUpdatableClient;
  class PublicTimeLineClient;
  class UserTimeLineClient;

  class Cache;

  QDateTime fromStringDateTime(const QString& string);
}

#endif // QTWEETCORE_H
