#ifndef QTWEETUSER_H
#define QTWEETUSER_H

#include <QtGlobal>
#include <QString>
#include <QDateTime>

#include "qtweetstatuslist.h"

#include "QTweetCore_global.h"

class QTWEETCORESHARED_EXPORT QTweetUser {
    public:
        explicit QTweetUser();
    public:
        quint64 id;
        QString name;
        QString screen_name;
        QString location;
        QString description;
        QString profile_image_url;
        QString url;
        bool profile_protected;
        uint followers_count;
        uint friends_count;
        QDateTime created_at;
        uint favourites_count;
        int utc_offset;
        QString time_zone;
        QString profile_background_image_url;
        QString profile_background_tile;
        bool notifications;
        bool following;
        bool verified;
        QTweetStatusList status;
};

#endif // QTWEETUSER_H
