#ifndef QTWEETSTATUSLIST_H
#define QTWEETSTATUSLIST_H

#include <QList>

#include "qtweetelementlist.h"
#include "qtweetstatus.h"

#include "QTweetCore_global.h"

class QTWEETCORESHARED_EXPORT QTweetStatusList : public QTweetElementList, public QList<QTweetStatus> {
    public:
        QTweetStatusList();
        QTweetStatusList(const QTweetStatusList &other);

        virtual const QTweetElement& atIndex(int i) const;
//        virtual const QTweetStatus& atIndex(int i) const;
        virtual int countElements() const;
        virtual void insertElement(int i, const QTweetElement& value);
        virtual void insertElement(int i, const QTweetStatus& value);
};

#endif // QTWEETSTATUSLIST_H
