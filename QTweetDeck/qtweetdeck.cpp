#include <QDebug>

#include "qtweetdeck.h"
#include "tweet.h"
#include "tweets.h"
#include "publictimelineclient.h"

QTweetDeck::QTweetDeck(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("QTweetDeck");

  client = new QTweet::PublicTimeLineClient;
  connect(client, SIGNAL(newDataArrived(Tweets*)), this, SLOT(printNewDataArrived(Tweets*)));

  data = client->createEmptyData();

  client->start();
}

QTweetDeck::~QTweetDeck() {
  client->stop();
  delete client;

  for(int i = 0; i < data->countAll(); i++) {
    qDebug() << "tweet (" << data->tweetAt(i).statusid() << "): " << data->tweetAt(i).user().name() << " " << data->tweetAt(i).text();
  }

  delete data;
}

void QTweetDeck::printNewDataArrived(Tweets *tweets) {
  qDebug() << "Count: " << tweets->countAll();
  for(int i = 0; i < tweets->countAll(); i++) {
//    qDebug() << "tweet (" << tweets->tweetAt(i).statusid() << "): " << tweets->tweetAt(i).user().name() << " " << tweets->tweetAt(i).text();
    data->appendTweets(*tweets);
  }
}
