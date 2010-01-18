#ifndef QTWEETDECK_H
#define QTWEETDECK_H

#include <QtGui/QMainWindow>

#include "qtweetcolumns.h"
#include "qtweetstatuslist.h"

class QTweetDeck : public QMainWindow {
    Q_OBJECT
    public:
        QTweetDeck(QWidget *parent = 0);
        ~QTweetDeck();
    private slots:
        void loadStatusList(const QTweetStatusList &list, const QString& error);
    private:
        QTweetColumns *columns;
        QTweetColumn *c;
};

#endif // QTWEETDECK_H
