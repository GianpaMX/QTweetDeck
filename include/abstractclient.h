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

    void requestProfileImages(Tweets *tweets);
  signals:
    void errorReplyed(int i, const QString &error);
    void imageLoaded(const QString &url);
  protected slots:
    virtual void processReply(int i, Tweets *tweets) = 0;
    virtual void notAuthorized(int i) = 0;
  protected:
    virtual int request(const QString & url, QOAuth::ParamMap map = QOAuth::ParamMap());
    virtual QString requestURL(const QString & url);
  private slots:
    void replyed(int i);
    void replyed(const QString &url);
    void slotError(QNetworkReply::NetworkError error);
  private:
    Q_DISABLE_COPY(AbstractClient)

    static QNetworkAccessManager* networkManager;

    QPointer<QSignalMapper> requestMapper;
    int requestCounter;

    OAuth auth;

    Tweets *tweets;
};

#endif // ABSTRACTCLIENT_H
