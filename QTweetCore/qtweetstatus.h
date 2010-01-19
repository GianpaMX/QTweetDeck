#ifndef QTWEETSTATUS_H
#define QTWEETSTATUS_H

#include <QtGlobal>
#include <QtXml>
#include <QString>
#include <QDateTime>

#include "qtweetelement.h"

#include "QTweetCore_global.h"

class QTweetUser;

class QTWEETCORESHARED_EXPORT QTweetStatus : public QTweetElement {
    public:
        explicit QTweetStatus(quint64 id = 0);
        QTweetStatus(const QTweetStatus& other);
        virtual ~QTweetStatus();

        virtual void updateFromDomElement(const QDomElement& domelement);

        void setCreatedAt(const QDateTime& value);
        void setCreatedAt(const QString& value);
        QDateTime createdAt() const;

        void setText(const QString& value);
        QString text() const;

        void setSource(const QString& value);
        QString source() const;

        void setTruncated(bool value);
        bool truncated() const;

        void setInReplayToStatus(QTweetStatus* value);
        void setInReplayToStatus(quint64 value);
        QTweetStatus* inReplayToStatus() const;

        void setInReplayToUser(QTweetUser* value);
        void setInReplayToUser(quint64 value);
        QTweetUser* inReplayToUser() const;

        void setFavorited(bool value);
        bool favorited() const;

        void setInReplayToScreenName(const QString& value);
        QString inReplayToScreenName() const;

        void setUser(QTweetUser* value);
        void setUser(quint64 value);
        QTweetUser* user() const;

        virtual QTweetStatus& operator=(const QTweetStatus& other);

    private:
        QDateTime created_at;
        QString _text;
        QString _source;
        bool _truncated;
        QTweetStatus* in_reply_to_status;
        QTweetUser* in_reply_to_user;
        bool _favorited;
        QString in_reply_to_screen_name;
        QTweetUser* _user;
};

#endif // QTWEETSTATUS_H
