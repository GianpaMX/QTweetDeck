#ifndef QTWEETCLIENT_H
#define QTWEETCLIENT_H

#include <QThread>
#include <QtNetwork>
#include <QtXml>
#include <QObject>
#include <QPointer>

#include "qtweetstatuslist.h"

#include "QTweetCore_global.h"

class QTWEETCORESHARED_EXPORT QTweetClient : public QThread {
    Q_OBJECT
    public:
        explicit QTweetClient(QObject * parent = 0);
        explicit QTweetClient(unsigned long refreshevery, QObject * parent = 0);
        virtual ~QTweetClient();

        virtual void run();

        void setRefresh(unsigned long refreshevery);
    signals:
        void beginRequest();
        void publicTimeLine(const QTweetStatusList &list, const QString& error);
    public slots:
        void requestPublicTimeLine();
    private slots:
        void replayPublicTimeLine();
    private:
        Q_DISABLE_COPY(QTweetClient);

        void addStatusElement(const QDomElement& status, QTweetStatusList& list);

        QPointer<QNetworkAccessManager> manager;
        QPointer<QNetworkReply> reply;
        unsigned long secs;
};

#endif // QTWEETCLIENT_H
