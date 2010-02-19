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
  if(!containsTweet(other))
    append(dynamic_cast<const Status &>(other));
}

void StatusList::appendTweets(const Tweets &others) {
  for(int i=0; i<others.countAll(); i++)
    appendTweet(others.tweetAt(i));
}


void StatusList::prependTweet(const Tweet &other) {
  if(!containsTweet(other))
    prepend(dynamic_cast<const Status &>(other));
}

void StatusList::prependTweets(const Tweets &others) {
  for(int i=others.countAll()-1; i>=0; i--)
    prependTweet(others.tweetAt(i));
}

bool StatusList::containsTweet(const Tweet &other) {
  return contains(dynamic_cast<const Status &>(other));
}

int StatusList::containsTweets(const Tweets &others) {
  int result = 0;
  for(int i=0; i<others.countAll(); i++) {
    if(containsTweet(others.tweetAt(i)))
      result++;
  }
  return result;
}
