#include "qtweetstatuslist.h"

QTweetStatusList::QTweetStatusList() : QTweetElementList(), QList<QTweetStatus>() {
}

QTweetStatusList::QTweetStatusList(const QTweetStatusList& other) : QTweetElementList(other), QList<QTweetStatus>(other) {
}

const QTweetElement& QTweetStatusList::atIndex(int i) const {
    return at(i);
}

//const QTweetStatus& QTweetStatusList::atIndex(int i) const {
//    return at(i);
//}

int QTweetStatusList::countElements() const {
    return count();
}

void QTweetStatusList::insertElement(int i, const QTweetElement& value) {
    const QTweetStatus& status = static_cast<const QTweetStatus&>(value);
    insertElement(i, status);
}

void QTweetStatusList::insertElement(int i, const QTweetStatus& value) {
    insert(i, value);
}
