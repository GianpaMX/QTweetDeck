#ifndef QTWEETCOLUMNS_H
#define QTWEETCOLUMNS_H

#include <QScrollArea>
#include <QHBoxLayout>
#include <QPointer>

#include "qtweetcolumn.h"

#include "QTweetGui_global.h"

class QTWEETGUISHARED_EXPORT QTweetColumns : public QScrollArea {
    Q_OBJECT
    public:
        explicit QTweetColumns(QWidget * parent = 0);
        ~QTweetColumns();
    public slots:
        void addColumn(QTweetColumn *column);
    private:
        QPointer<QHBoxLayout> layout;
};

#endif // QTWEETCOLUMNS_H
