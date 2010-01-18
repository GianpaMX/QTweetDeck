#ifndef QTWEETSTATUS_H
#define QTWEETSTATUS_H

#include <QtGlobal>
#include <QString>

#include "QTweetCore_global.h"

class QTweetUser;

class QTWEETCORESHARED_EXPORT QTweetStatus {
    public:
        explicit QTweetStatus();

        void setText(const QString &value);
        QString text() const;

    private:
        QString created_at;
        quint64 id;
        QString statustext;
        QString source;
        bool truncated;
        quint64 in_reply_to_status_id;
        quint64 in_reply_to_user_id;
        bool favorited;
        QString in_reply_to_screen_name;
        QTweetUser* user;
};

#endif // QTWEETSTATUS_H
