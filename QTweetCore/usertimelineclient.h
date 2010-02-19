#ifndef USERTIMELINE_H
#define USERTIMELINE_H

#include <QtGlobal>
#include <QString>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "abstractupdatableclient.h"
#include "user.h"

class QTWEETCORESHARED_EXPORT QTweet::UserTimeLineClient : public QTweet::AbstractUpdatableClient {
  Q_OBJECT
  public:
    explicit UserTimeLineClient(const User &user, QObject *parent = 0);
    explicit UserTimeLineClient(const QString &screen_name, QObject *parent = 0);
    explicit UserTimeLineClient(qulonglong id, QObject *parent = 0);
  signals:
  public slots:
  protected:
    virtual Reply *requestDefaultData();
    User user;
};

#endif // USERTIMELINE_H
