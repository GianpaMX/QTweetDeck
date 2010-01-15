#ifndef QTWEETDECK_H
#define QTWEETDECK_H

#include <QtGui/QMainWindow>

class QTweetDeck : public QMainWindow {
    Q_OBJECT
    public:
        QTweetDeck(QWidget *parent = 0);
        ~QTweetDeck();
};

#endif // QTWEETDECK_H
