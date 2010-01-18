#include <QDebug>
#include <QMap>
#include <QDate>
#include <QTime>

#include "qtweetcore.h"
#include "qtweetuser.h"
#include "qtweetstatus.h"

QTweetStatus::QTweetStatus() {
    in_reply_to_status = 0;
    in_reply_to_user = 0;
    _user = 0;
}
QTweetStatus::QTweetStatus(const QTweetStatus& other) {
    in_reply_to_status = 0;
    in_reply_to_user = 0;
    _user = 0;

    *this = other;
}

QTweetStatus::~QTweetStatus() {
    if(in_reply_to_status)delete in_reply_to_status;
    if(in_reply_to_user) delete in_reply_to_user;
    if(_user) delete _user;
}

void QTweetStatus::setText(const QString &value) {
    _text = value;
}

QString QTweetStatus::text() const {
    return _text;
}

void QTweetStatus::setCreatedAt(const QDateTime& value) {
    created_at = value;
}

void QTweetStatus::setCreatedAt(const QString& value) {
    setCreatedAt(QTweetCore::fromStringDateTime(value));
}

QDateTime QTweetStatus::createdAt() const {
    return created_at;
}

void QTweetStatus::setId(quint64 value) {
    _id = value;
}

quint64 QTweetStatus::id() const {
    return _id;
}

void QTweetStatus::setSource(const QString& value) {
    _source = value;
}

QString QTweetStatus::source() const {
    return _source;
}

void QTweetStatus::setTruncated(bool value) {
    _truncated = value;
}

bool QTweetStatus::truncated() const {
    return _truncated;
}

void QTweetStatus::setInReplayToStatus(QTweetStatus* value) {
    if(in_reply_to_status) delete in_reply_to_status;
    in_reply_to_status = 0;
    if(value) {
        in_reply_to_status = new QTweetStatus;
        *in_reply_to_status = *value;
    }
}

void QTweetStatus::setInReplayToStatus(quint64 value) {
    if(!in_reply_to_status) in_reply_to_status = new QTweetStatus;
    in_reply_to_status->setId(value);
}

QTweetStatus* QTweetStatus::inReplayToStatus() const {
    return in_reply_to_status;
}

void QTweetStatus::setInReplayToUser(QTweetUser* value) {
    if(in_reply_to_user) delete in_reply_to_user;
    in_reply_to_user = 0;
    if(value) {
        in_reply_to_user = new QTweetUser;
        *in_reply_to_user = *value;
    }
}

void QTweetStatus::setInReplayToUser(quint64 /*value*/) {
//    if(!in_reply_to_user) in_reply_to_user = new QTweetUser;
//    in_reply_to_user->setId(value);
}

QTweetUser* QTweetStatus::inReplayToUser() const {
    return in_reply_to_user;
}

void QTweetStatus::setFavorited(bool value) {
    _favorited = value;
}

bool QTweetStatus::favorited() const {
    return _favorited;
}

void QTweetStatus::setInReplayToScreenName(const QString& value) {
    in_reply_to_screen_name = value;
}

QString QTweetStatus::inReplayToScreenName() const {
    return in_reply_to_screen_name;
}

void QTweetStatus::setUser(QTweetUser* value) {
    if(_user) delete _user;
    _user = 0;
    if(value) {
        _user = new QTweetUser;
        *_user = *value;
    }
}

void QTweetStatus::setUser(quint64 /*value*/) {
//    if(!_user) _user = new QTweetUser;
//    _user->setId(value);
}

QTweetUser* QTweetStatus::user() const {
    return _user;
}

QTweetStatus& QTweetStatus::operator=(const QTweetStatus& other) {
    if( this != &other ) {
        setInReplayToStatus(other.in_reply_to_status);
        setInReplayToUser(other.in_reply_to_user);
        setUser(other._user);

        created_at = other.createdAt();
        _id = other._id;
        _text = other._text;
        _source = other._source;
        _truncated = other._truncated;
        _favorited = other._favorited;
        in_reply_to_screen_name = other.in_reply_to_screen_name;
    }
    return *this;
}
