#include <QDebug>

#include "qtweetdeck.h"
#include "client.h"
#include "tweet.h"
#include "user.h"

QTweetDeck::QTweetDeck(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("QTweetDeck");

  c = new QTweet::Client();
  r = c->requestPublicTimeLine();
  connect(r, SIGNAL(dataReady()), this, SLOT(printStatusList()));

  r2 = c->requestStatus(8977782791LLU);
  connect(r2, SIGNAL(dataReady()), this, SLOT(printStatusList()));
}

QTweetDeck::~QTweetDeck() {
  delete r;
  delete r2;
  delete c;
}

void QTweetDeck::printStatusList() {
  QTweet::Reply *r = static_cast<QTweet::Reply *>(sender());
  qDebug() << "Count: " << r->data().countAll();
  for(int i = 0; i < r->data().countAll(); i++) {
    qDebug() << "tweet (" << r->data().tweetAt(i).statusid() << "): " << r->data().tweetAt(i).user().name() << " " << r->data().tweetAt(i).text();
  }
}
