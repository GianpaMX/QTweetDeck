#include "qtweetstatuslist.h"

QTweetStatusList::QTweetStatusList() : QList<QTweetStatus>() {
}

QTweetStatusList::QTweetStatusList(const QList<QTweetStatus> &other) : QList<QTweetStatus>(other) {
}

void QTweetStatusList::prependReverse(const QTweetStatusList& list) {
    for(int i=list.count()-1;i>=0;i--) {
        insert(0, list.at(i));
    }
}
