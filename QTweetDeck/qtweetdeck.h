#ifndef QTWEETDECK_H
#define QTWEETDECK_H

#include <QtGui/QMainWindow>
#include <QTableView>

#include "qtweetcore.h"
#include "qtweetgui.h"

class QTweetDeck : public QMainWindow {
  Q_OBJECT
  public:
    QTweetDeck(QWidget *parent = 0);
    ~QTweetDeck();
  private:
    QTweet::AbstractUpdatableClient *client;
    QTweet::TweetsModel *model;

    QTableView *table;
};

#endif // QTWEETDECK_H
