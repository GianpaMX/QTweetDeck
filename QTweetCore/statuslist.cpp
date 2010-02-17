#include "statuslist.h"

using namespace QTweet;

StatusList::StatusList() : QList<Status>() {
}

StatusList::StatusList(const StatusList & other) : QList<Status>(other) {
}

int StatusList::countAll() const {
  return count();
}
const Tweet & StatusList::tweetAt(int i) const {
  return at(i);
}

void StatusList::appendTweet(const Tweet &other) {
  append(dynamic_cast<const Status &>(other));
}

void StatusList::appendTweets(const Tweets &others) {
  append(dynamic_cast<const StatusList &>(others));
}

