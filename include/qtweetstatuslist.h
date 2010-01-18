#ifndef QTWEETSTATUSLIST_H
#define QTWEETSTATUSLIST_H

#include <QList>

#include "qtweetstatus.h"

#include "QTweetCore_global.h"

class QTWEETCORESHARED_EXPORT QTweetStatusList : public QList<QTweetStatus> {
    public:
        QTweetStatusList();
        QTweetStatusList(const QList<QTweetStatus> &other);
};

#endif // QTWEETSTATUSLIST_H
