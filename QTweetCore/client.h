#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QPointer>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "abstractclient.h"
#include "reply.h"

class QTWEETCORESHARED_EXPORT QTweet::Client : public QTweet::AbstractClient {
  Q_OBJECT
  public:
    explicit Client(QObject *parent = 0);
    virtual ~Client();
  signals:
    void Error(const QString &error);
  public slots:
    Reply* requestPublicTimeLine();

    Reply* requestUserTimeLine(qulonglong user_id);
    Reply* requestUserTimeLine(const QString &screen_name);

    Reply* requestStatus(qulonglong status_id);

    Reply* requestUser(qulonglong user_id);
    Reply* requestUser(const QString &screen_name);

    Reply* requestUserFriends(qulonglong user_id);
    Reply* requestUserFriends(const QString &screen_name);

    Reply* requestUserFollowers(qulonglong user_id);
    Reply* requestUserFollowers(const QString &screen_name);
  protected slots:
    Reply* requestUserTimeLine(QOAuth::ParamMap parameters);
    Reply* requestUser(QOAuth::ParamMap parameters);
    Reply* requestUserFriends(QOAuth::ParamMap parameters);
    Reply* requestUserFollowers(QOAuth::ParamMap parameters);

    Reply* request_and_map(const QString &url, QOAuth::ParamMap parameters = QOAuth::ParamMap());

    virtual void processReply(int i, Tweets & tweets);
    virtual void notAuthorized(int i);
  private:
    QMap< int, QPointer<Reply> > replys;
};

#endif // CLIENT_H
