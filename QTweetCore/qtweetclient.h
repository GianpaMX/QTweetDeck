#ifndef QTWEETCLIENT_H
#define QTWEETCLIENT_H

#include <QtNetwork>
#include <QtXml>
#include <QObject>
#include <QPointer>

#include "qtweetstatuslist.h"

#include "QTweetCore_global.h"

class QTWEETCORESHARED_EXPORT QTweetClient : public QObject {
    Q_OBJECT
    public:
        explicit QTweetClient(QObject * parent = 0);
        virtual ~QTweetClient();

    signals:
        void publicTimeLine(const QTweetStatusList &list, const QString& error);
    public slots:
        void requestPublicTimeLine();
    private slots:
        void replayPublicTimeLine();
    private:
        Q_DISABLE_COPY(QTweetClient);

        void addStatusElement(const QDomElement& status, QTweetStatusList& list);

        QNetworkAccessManager *manager;
        QPointer<QNetworkReply> reply;
};

#endif // QTWEETCLIENT_H
