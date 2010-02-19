#include <QDebug>

#include "tweetsmodel.h"
#include "tweets.h"
#include "tweet.h"
#include "abstractupdatableclient.h"

using namespace QTweet;

QStringList TweetsModel::header_data = QStringList() << "tweet";

TweetsModel::TweetsModel(AbstractUpdatableClient *client, QObject *parent) : QAbstractTableModel(parent) {
  this->client = client;
  tweets = this->client->createEmptyData();

  connect(client, SIGNAL(newDataArrived(Tweets*)), this, SLOT(prependData(Tweets*)));
  client->start();
}

TweetsModel::~TweetsModel() {
  client->stop();
  delete tweets;
}

int TweetsModel::rowCount(const QModelIndex & /*parent*/) const {
  return tweets->countAll();
}
int TweetsModel::columnCount(const QModelIndex & /*parent*/) const {
  return TweetsModel::header_data.count();
}
QVariant TweetsModel::data(const QModelIndex &index, int role) const {
  if(!index.isValid())
    return QVariant();

  if(index.row() >= tweets->countAll())
    return QVariant();

  if(index.column() >= TweetsModel::header_data.count())
    return QVariant();

  if(role == Qt::DisplayRole) {
    switch(index.column()) {
    case 0:
      return tweets->tweetAt(index.row()).user().screenname() + ":" + tweets->tweetAt(index.row()).text()
          + "\nat " + tweets->tweetAt(index.row()).datetime().toString("dd/MM/yy hh:mm:ss");
    default: return QVariant();
    }
  } else if(role == Qt::DecorationRole) {

  }

  return QVariant();
}

void TweetsModel::appendData(Tweets *new_data) {
  int position = tweets->countAll();
  int rows = new_data->countAll() - tweets->containsTweets(*new_data);

  beginInsertRows(QModelIndex(), position, position+rows-1);
  tweets->appendTweets(*new_data);
  endInsertRows();
}

void TweetsModel::prependData(Tweets *new_data) {
  int position = 0;
  int rows = new_data->countAll() - tweets->containsTweets(*new_data);

  beginInsertRows(QModelIndex(), position, position+rows-1);
  tweets->prependTweets(*new_data);
  endInsertRows();

  qDebug() << tweets->countAll();
}
