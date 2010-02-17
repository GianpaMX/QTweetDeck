#include <QDebug>

#include "qtweetdeck.h"
#include "publictimelineclient.h"
#include "tweetsmodel.h"

QTweetDeck::QTweetDeck(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("QTweetDeck");

  table = new QTableView();

  client = new QTweet::PublicTimeLineClient;
  model = new QTweet::TweetsModel(client, table);

  table->setModel(model);

  table->show();
}

QTweetDeck::~QTweetDeck() {
  delete model;
  delete client;
  delete table;
}
