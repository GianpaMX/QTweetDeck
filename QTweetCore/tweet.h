#ifndef TWEET_H
#define TWEET_H

#include <QString>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "user.h"

class QTWEETCORESHARED_EXPORT QTweet::Tweet {
  public:
  virtual qulonglong statusid() const = 0;
  virtual User user() const = 0;
  virtual QString text() const = 0;
  virtual QDateTime datetime() const = 0;
  virtual QString source() const = 0;
};

#endif // TWEET_H
