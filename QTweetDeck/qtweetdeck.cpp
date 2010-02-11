#include <QFile>
#include <QMessageBox>
#include <QByteArray>
#include <QInputDialog>
#include <QDebug>

#include "qtweetdeck.h"
#include "client.h"
#include "tweet.h"
#include "user.h"

QTweetDeck::QTweetDeck(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("QTweetDeck");

  QByteArray key, secret;
  QFile file;
  file.setFileName("../qtweet_private/consumer.key");
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    key = file.readLine();
    file.close();
  }

  file.setFileName("../qtweet_private/consumer.secret");
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    secret = file.readLine();
    file.close();
  }

  QTweet::setConsumer(key, secret);

  QTweet::User u;
  u.setUserId(12065042);
  c = new QTweet::Client();
  r = c->requestUserTimeLine(u);

  connect(r, SIGNAL(dataReady()), this, SLOT(printStatusList()));
}

QTweetDeck::~QTweetDeck() {
  delete r;
  delete c;
}

void QTweetDeck::printStatusList() {
  for(int i = 0; i < r->data().countAll(); i++) {
    qDebug() << "Error:" << r->data().tweetAt(i).user().name() << " " << r->data().tweetAt(i).text();
  }
}
