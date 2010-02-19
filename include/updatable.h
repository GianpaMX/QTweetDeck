#ifndef UPDATABLE_H
#define UPDATABLE_H

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "dataarrived.h"
#include "tweets.h"

class QTWEETCORESHARED_EXPORT QTweet::Updatable : public QTweet::DataArrived {
  public:
    virtual void requestNewData() = 0;
};

#endif // UPDATABLE_H
