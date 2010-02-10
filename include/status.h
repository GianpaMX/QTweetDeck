#ifndef STATUS_H
#define STATUS_H

#include <QtGlobal>
#include <QtXml>
#include <QString>
#include <QDateTime>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "user.h"

class QTWEETCORESHARED_EXPORT QTweet::Status : public QTweet::User {
  public:
    Status();

    void readDomElement(const QDomElement& xmluser);

    qulonglong statusid() const;
    void setStatusId(qulonglong value);

    QDateTime createat() const;
    void setCreateAt(const QDateTime &value);

    QString text() const;
    void setText(const QString &value);

    QString source() const;
    void setSource(const QString &value);
  private:
    qulonglong status_id;
    QDateTime status_created_at;
    QString status_text;
    QString status_source;
};

#endif // STATUS_H
