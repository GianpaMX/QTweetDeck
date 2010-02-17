#ifndef ABSTRACTUPDATABLECLIENT_H
#define ABSTRACTUPDATABLECLIENT_H

#include <QPointer>
#include <QTimer>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "updatable.h"

#include "client.h"
#include "reply.h"

class QTWEETCORESHARED_EXPORT QTweet::AbstractUpdatableClient :  public QTweet::Client, public QTweet::Updatable {
  Q_OBJECT
  public:
    explicit AbstractUpdatableClient(QObject *parent = 0);
    virtual ~AbstractUpdatableClient();

    unsigned long getInterval() const;
    void setInterval(unsigned long value);
  signals:
    void newDataArrived(Tweets *tweets);
  public slots:
    void requestNewData();

    void start();
    void stop();
  protected:
    void run();
    virtual Reply *requestDefaultData() = 0;
    unsigned long interval;
    QTimer *timer;
  private:
    Q_DISABLE_COPY(AbstractUpdatableClient)
};

#endif // ABSTRACTUPDATABLECLIENT_H
