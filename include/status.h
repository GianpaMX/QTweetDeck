#ifndef STATUS_H
#define STATUS_H

#include <QtGlobal>
#include <QtXml>
#include <QString>
#include <QDateTime>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "user.h"
#include "tweet.h"

class QTWEETCORESHARED_EXPORT QTweet::Status : public QTweet::User, public virtual QTweet::Tweet {
  public:
    Status();
    Status(const Status &other);
    virtual ~Status();

    void readDomElement(const QDomElement& xmlstatus);

    qulonglong statusid() const;
    void setStatusId(qulonglong value);

    QDateTime createat() const;
    void setCreateAt(const QDateTime &value);

    User user() const;

    QString text() const;
    void setText(const QString &value);

    QDateTime datetime() const;

    QString source() const;
    void setSource(const QString &value);

    Status* inreplytostatus() const;
    void setInReplyToStatus(Status *value);

    User* inreplytouser() const;
    void setInReplyToUser(const User *value);

    QString inreplytoscreenname() const;
    void setInReplyToScreenName(const QString &value);

    Status &operator=(const Status &other);

    bool operator==(const Tweet &other) const;
  private:
    qulonglong status_id;
    QDateTime status_created_at;
    QString status_text;
    QString status_source;
    Status *status_in_replay_to_status;
    User *status_in_replay_to_user;
};

#endif // STATUS_H
