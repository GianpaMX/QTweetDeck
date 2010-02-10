#include "statuslist.h"

using namespace QTweet;

StatusList::StatusList() : QList<QTweet::Status>() {
}

StatusList::StatusList(const StatusList & other) : QList<QTweet::Status>(other) {
}
