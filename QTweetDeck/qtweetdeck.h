#ifndef QTWEETDECK_H
#define QTWEETDECK_H

#include <QtGui/QMainWindow>

#include "qtweetcore.h"

class QTweetDeck : public QMainWindow {
  Q_OBJECT
  public:
    QTweetDeck(QWidget *parent = 0);
    ~QTweetDeck();
  public slots:
    void printStatusList();
  private:
    QTweet::Reply *r, *r2, *r3, *r4;
    QTweet::Client *c;
};

#endif // QTWEETDECK_H
