#include "qtweetcore.h"
#include "qtweetpublictimelinemodel.h"

QTweetPublicTimeLineModel::QTweetPublicTimeLineModel(QObject *parent) :QTweetStatusListModel(parent) {
    client = new QTweetStatusesClient("http://twitter.com/statuses/public_timeline.xml");

    connect(client, SIGNAL(readyStatusList(QTweetStatusList,QString)), this, SLOT(addStatusList(QTweetStatusList,QString)));

    client->requestList();
    client->setRefresh(10);
}

QTweetPublicTimeLineModel::~QTweetPublicTimeLineModel() {
    if(client) delete client;
}
