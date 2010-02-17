#ifndef QTWEETDECK_H
#define QTWEETDECK_H

#include <QtGui/QMainWindow>

#include "qtweetcore.h"

typedef QTweet::Tweets Tweets;

class QTweetDeck : public QMainWindow {
  Q_OBJECT
  public:
    QTweetDeck(QWidget *parent = 0);
    ~QTweetDeck();
  private:
    QTweet::AbstractUpdatableClient *client;

    QTweet::Tweets *data;
  public slots:
    void printNewDataArrived(Tweets *tweets);
};

#endif // QTWEETDECK_H
