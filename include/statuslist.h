#ifndef STATUSLIST_H
#define STATUSLIST_H

#include <QList>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "status.h"

class QTWEETCORESHARED_EXPORT QTweet::StatusList : public QList<QTweet::Status> {
  public:
      StatusList();
      StatusList(const StatusList & other);
};

#endif // STATUSLIST_H
