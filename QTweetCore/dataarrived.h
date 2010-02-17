#ifndef DATAARRIVED_H
#define DATAARRIVED_H

#include <QString>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "tweets.h"

class QTWEETCORESHARED_EXPORT QTweet::DataArrived {
  public:
    virtual void newDataArrived(Tweets *tweets) = 0;
};

#endif // DATAARRIVED_H
