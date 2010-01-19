#ifndef QTWEETCLIENT_H
#define QTWEETCLIENT_H

#include <QThread>
#include <QtNetwork>
#include <QObject>
#include <QPointer>

#include "qtweetelementlist.h"

#include "QTweetCore_global.h"

/**
* @brief The QTweetClient class allows to send twitter requests and receive replies
*
* @class QTweetClient qtweetclient.h "QTweetCore/qtweetclient.h"
*/
class QTWEETCORESHARED_EXPORT QTweetClient : public QThread {
    Q_OBJECT
    public:
        explicit QTweetClient(QObject * parent = 0);
    /**
    * @brief Constructs a QTweetClient and set the refreshing time
    *
    * @fn QTweetClient
    * @param refreshevery Time in seconds between requests. if it is zero, refreshing isn't abble
    * @param parent
    */
        explicit QTweetClient(unsigned long refreshevery, QObject * parent = 0);
        virtual ~QTweetClient();

        virtual void run();

        void setRefresh(unsigned long refreshevery);
    signals:
        void beforeRequest();
        void readyList(const QTweetElementList& list, const QString& error);
    public slots:
        virtual void requestList() = 0;
    protected:
        Q_DISABLE_COPY(QTweetClient);

        QPointer<QNetworkAccessManager> manager;
        QPointer<QNetworkReply> reply;
        unsigned long secs;
};

#endif // QTWEETCLIENT_H
