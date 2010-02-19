#include <QDebug>

#include "qtweetcore.h"
#include "cache.h"

#include "qtweetdeck.h"
#include "usertimelineclient.h"
#include "tweetsmodel.h"

QTweetDeck::QTweetDeck(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("QTweetDeck");

  QTweet::Cache::Initialize("cached.data.sqlite3");

  table = new QTableView();

  client = new QTweet::UserTimeLineClient("ohbill");
  model = new QTweet::TweetsModel(client, table);

  table->setModel(model);

  table->show();
}

QTweetDeck::~QTweetDeck() {
  delete model;
  delete client;
  delete table;

  QTweet::Cache::Finalize();
}
