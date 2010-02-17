#include "abstractupdatableclient.h"

using namespace QTweet;

AbstractUpdatableClient::AbstractUpdatableClient(QObject *parent) : Client(parent) {
  interval = 10000;
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(requestNewData()));
}

AbstractUpdatableClient::~AbstractUpdatableClient() {
}

void AbstractUpdatableClient::requestNewData() {
  Reply *reply = requestDefaultData();
  connect(reply, SIGNAL(newDataArrived(Tweets*)), this, SIGNAL(newDataArrived(Tweets*)));
}

void AbstractUpdatableClient::start() {
  requestNewData();
  timer->start(interval);
}

void AbstractUpdatableClient::stop() {
  timer->stop();
}

unsigned long AbstractUpdatableClient::getInterval() const {
  return interval;
}
void AbstractUpdatableClient::setInterval(unsigned long value) {
  interval = value;
}
