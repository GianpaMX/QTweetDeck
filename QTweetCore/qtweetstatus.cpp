#include "qtweetuser.h"
#include "qtweetstatus.h"

QTweetStatus::QTweetStatus() {
}

void QTweetStatus::setText(const QString &value) {
    statustext = value;
}

QString QTweetStatus::text() const {
    return statustext;
}
