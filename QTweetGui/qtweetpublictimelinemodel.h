#ifndef QTWEETPUBLICTIMELINEMODEL_H
#define QTWEETPUBLICTIMELINEMODEL_H

#include <QPointer>

#include "qtweetstatuslistmodel.h"
#include "qtweetstatusesclient.h"

#include "QTweetGui_global.h"

class QTWEETGUISHARED_EXPORT QTweetPublicTimeLineModel : public QTweetStatusListModel {
    Q_OBJECT
    public:
        explicit QTweetPublicTimeLineModel(QObject *parent = 0);
        explicit QTweetPublicTimeLineModel(const QTweetStatusList &statuslist, QObject *parent = 0);
        ~QTweetPublicTimeLineModel();
    private:
        QPointer<QTweetStatusesClient> client;
};

#endif // QTWEETPUBLICTIMELINEMODEL_H
