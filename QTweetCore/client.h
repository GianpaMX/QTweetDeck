#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "abstractclient.h"

class QTWEETCORESHARED_EXPORT QTweet::Client : public virtual QTweet::AbstractClient {
  Q_OBJECT
  public:
    explicit Client(QObject *parent = 0);
  signals:
  public slots:
};

#endif // CLIENT_H
