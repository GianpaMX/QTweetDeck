#include "qtweetcore.h"
#include "qtweetpublictimelinemodel.h"

QTweetPublicTimeLineModel::QTweetPublicTimeLineModel(QObject *parent) :QTweetStatusListModel(parent) {
    connect(QTweetCore::Client(), SIGNAL(publicTimeLine(QTweetStatusList,QString)), this, SLOT(addStatusList(QTweetStatusList,QString)));
    QTweetCore::Client()->requestPublicTimeLine();
    QTweetCore::Client()->setRefresh(10);
}
