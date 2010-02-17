#ifndef PUBLICTIMELINECLIENT_H
#define PUBLICTIMELINECLIENT_H

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "abstractupdatableclient.h"
#include "reply.h"

class QTWEETCORESHARED_EXPORT QTweet::PublicTimeLineClient : public QTweet::AbstractUpdatableClient {
  Q_OBJECT
  public:
    explicit PublicTimeLineClient(QObject *parent = 0);
  signals:
  public slots:
  protected:
    virtual Reply *requestDefaultData();
};

#endif // PUBLICTIMELINECLIENT_H
