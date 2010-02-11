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

  QDateTime fromStringDateTime(const QString& string);

}

#endif // QTWEETCORE_H
