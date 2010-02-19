#ifndef ABSTRACTCLIENT_H
#define ABSTRACTCLIENT_H

#include <QtOAuth>
#include <QtNetwork>
#include <QObject>
#include <QPointer>
#include <QSignalMapper>
#include <QList>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "creatable.h"

#include "statuslist.h"
#include "oauth.h"

class QTWEETCORESHARED_EXPORT QTweet::AbstractClient : public QObject, public QTweet::Creatable {
  Q_OBJECT
  public:
    explicit AbstractClient(QObject *parent = 0);
    virtual ~AbstractClient();
  signals:
    void errorReplyed(int i, const QString &error);
  protected slots:
    virtual void processReply(int i, Tweets *tweets) = 0;
    virtual void notAuthorized(int i) = 0;
  protected:
    virtual int request(const QString & url, QOAuth::ParamMap map = QOAuth::ParamMap());
  private slots:
    void replyed(int i);
    void slotError(QNetworkReply::NetworkError error);
  private:
    Q_DISABLE_COPY(AbstractClient)

    static QNetworkAccessManager* networkManager;

    QPointer<QSignalMapper> requestMapper;
    int requestCounter;

    OAuth auth;
};

#endif // ABSTRACTCLIENT_H
