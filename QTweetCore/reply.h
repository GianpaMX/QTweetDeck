#ifndef REPLY_H
#define REPLY_H

#include <QObject>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "dataarrived.h"
#include "tweets.h"

class QTWEETCORESHARED_EXPORT QTweet::Reply : public QObject, public QTweet::DataArrived {
  Q_OBJECT
  public:
    explicit Reply(Tweets * value, QObject *parent = 0);
    ~Reply();

    Tweets* data();
    void setData(Tweets *value);

    bool privateTweets() const;
    void setPrivateWeets(bool value);
  signals:
    void dataReady();
    void newDataArrived(Tweets *tweets);
  private:
    Q_DISABLE_COPY(Reply)
    Tweets * reply_data;
    bool private_tweets;
};

#endif // REPLY_H
