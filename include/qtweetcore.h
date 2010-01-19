#ifndef QTWEETCORE_H
#define QTWEETCORE_H

#include <QtOAuth/QtOAuth>
#include <QByteArray>
#include <QObject>
#include <QDateTime>

#include "QTweetCore_global.h"

class QTWEETCORESHARED_EXPORT QTweetCore {
    public:

        static void init(QObject* parent = 0);
        static void term();

        static void setConsumer(const QByteArray& key, const QByteArray& secret);
        static void setRequestTimeout(uint requestTimeout);

        static QDateTime fromStringDateTime(const QString& string);

    private:
        explicit QTweetCore();
        explicit QTweetCore(const QTweetCore& other);

        static QOAuth::Interface *qoauth;
};

#endif // QTWEETCORE_H
