#include "statuslist.h"

using namespace QTweet;

StatusList::StatusList() : QList<QTweet::Status>() {
}

StatusList::StatusList(const StatusList & other) : QList<QTweet::Status>(other) {
}

int StatusList::countAll() const {
  return count();
}
const Tweet & StatusList::tweetAt(int i) const {
  return at(i);
}
