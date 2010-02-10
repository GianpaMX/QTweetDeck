#ifndef ABSTRACTCLIENT_H
#define ABSTRACTCLIENT_H

#include <QtNetwork>
#include <QObject>
#include <QPointer>
#include <QSignalMapper>
#include <QList>
#include <QMap>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "statuslist.h"

class QTWEETCORESHARED_EXPORT QTweet::AbstractClient : public QObject {
  Q_OBJECT
  public:
      explicit AbstractClient(QObject *parent = 0);
      ~AbstractClient();
  signals:
      void errorReplayed(int i, const QString &error);
  protected slots:
      virtual void processReply(int i, QTweet::StatusList statuses) = 0;
  protected:
    virtual int request(const QString & url, QMap<QByteArray, QByteArray> parameters);
  private slots:
      void replyed(int i);
  private:
      Q_DISABLE_COPY(AbstractClient)

      static QPointer<QNetworkAccessManager> networkManager;
      static QPointer<QSignalMapper> requestMapper;
      static int requestCounter;
};

#endif // ABSTRACTCLIENT_H
