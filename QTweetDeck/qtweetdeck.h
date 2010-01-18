#ifndef QTWEETDECK_H
#define QTWEETDECK_H

#include <QtGui/QMainWindow>
#include <QPointer>

#include "qtweetcolumns.h"
#include "qtweetpublictimelinemodel.h"

class QTweetDeck : public QMainWindow {
    Q_OBJECT
    public:
        QTweetDeck(QWidget *parent = 0);
        ~QTweetDeck();
    private:
        QPointer<QTweetColumns> columns;
        QPointer<QTweetColumn> c;
        QPointer<QTweetPublicTimeLineModel> model;
};

#endif // QTWEETDECK_H
