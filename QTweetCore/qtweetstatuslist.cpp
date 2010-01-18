#include "qtweetstatuslist.h"

QTweetStatusList::QTweetStatusList() : QList<QTweetStatus>() {
}

QTweetStatusList::QTweetStatusList(const QList<QTweetStatus> &other) : QList<QTweetStatus>(other) {
}
