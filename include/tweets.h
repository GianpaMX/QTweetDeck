#ifndef TWEETS_H
#define TWEETS_H

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "tweet.h"

class QTWEETCORESHARED_EXPORT QTweet::Tweets {
  public:
    virtual int countAll() const = 0;
    virtual const Tweet & tweetAt(int i) const = 0;
};

#endif // TWEETS_H
