#ifndef TWEETS_H
#define TWEETS_H

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "tweet.h"

class QTWEETCORESHARED_EXPORT QTweet::Tweets {
  public:
    virtual int countAll() const = 0;
    virtual const Tweet & tweetAt(int i) const = 0;

    virtual void appendTweet(const Tweet &other) = 0;
    virtual void appendTweets(const Tweets &others) = 0;

    virtual void prependTweet(const Tweet &other) = 0;
    virtual void prependTweets(const Tweets &others) = 0;

    virtual bool containsTweet(const Tweet &other) = 0;
    virtual int containsTweets(const Tweets &others) = 0;
};

#endif // TWEETS_H
