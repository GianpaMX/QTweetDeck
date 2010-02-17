#ifndef CREATABLE_H
#define CREATABLE_H


#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "tweets.h"

class QTWEETCORESHARED_EXPORT QTweet::Creatable {
  public:
    virtual Tweets* createEmptyData() const = 0;
};


#endif // CREATABLE_H
