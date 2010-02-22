#include "status.h"

using namespace QTweet;

Status::Status() : User() {
  status_id = 0;
  status_in_replay_to_status = 0;
  status_in_replay_to_user = 0;
}
Status::Status(const Status &other) : User(other) {
  status_id = 0;
  status_in_replay_to_status = 0;
  status_in_replay_to_user = 0;

  *this = other;
}

Status::~Status() {
  if( status_in_replay_to_status != 0) delete status_in_replay_to_status;
  if( status_in_replay_to_user != 0) delete status_in_replay_to_user;
}

void Status::readDomElement(const QDomElement &xmlstatus) {
  setStatusId(xmlstatus.firstChildElement("id").text().toULongLong());
  setCreateAt(fromStringDateTime(xmlstatus.firstChildElement("created_at").text()));
  setText(xmlstatus.firstChildElement("text").text());
  setSource(xmlstatus.firstChildElement("source").text());

  Status in_reply_to_status;
  in_reply_to_status.setStatusId(xmlstatus.firstChildElement("in_reply_to_status_id").text().toULongLong());
  setInReplyToStatus(&in_reply_to_status);

  User in_reply_to_user;
  in_reply_to_user.setUserId(xmlstatus.firstChildElement("in_reply_to_user_id").text().toULongLong());
  in_reply_to_user.setScreenName(xmlstatus.firstChildElement("in_reply_to_screen_name").text());
  setInReplyToUser(&in_reply_to_user);
}

qulonglong Status::statusid() const {
  return status_id;
}
void Status::setStatusId(qulonglong value) {
  status_id = value;
}

QDateTime Status::createat() const {
  return status_created_at;
}
void Status::setCreateAt(const QDateTime &value) {
  status_created_at = value;
}

QString Status::text() const {
  return status_text;
}
void Status::setText(const QString &value) {
  status_text = value;
}

QString Status::source() const {
  return status_source;
}
void Status::setSource(const QString &value) {
  status_source = value;
}

User Status::user() const {
  return *this;
}
User& Status::userRef() {
  return *this;
}

QDateTime Status::datetime() const {
  return createat();
}

Status* Status::inreplytostatus() const {
  return status_in_replay_to_status;
}
void Status::setInReplyToStatus(Status *value) {
  if( status_in_replay_to_status != 0) delete status_in_replay_to_status;
  status_in_replay_to_status = 0;

  if(value != 0)
    status_in_replay_to_status = new Status(*value);
}

User *Status::inreplytouser() const {
  return status_in_replay_to_user;
}
void Status::setInReplyToUser(const User *value) {
  if( status_in_replay_to_user != 0) delete status_in_replay_to_user;
  status_in_replay_to_user = 0;

  if(value != 0)
    status_in_replay_to_user = new User(*value);
}

QString Status::inreplytoscreenname() const {
  if(status_in_replay_to_user == 0) return QString();
  return status_in_replay_to_user->screenname();
}
void Status::setInReplyToScreenName(const QString &value) {
  if(status_in_replay_to_user == 0) status_in_replay_to_user = new User();

  status_in_replay_to_user->setScreenName(value);
}

Status &Status::operator=(const Status &other) {
  if( this != &other ) {
    status_id = other.status_id;
    status_created_at = other.status_created_at;
    status_text = other.status_text;
    status_source = other.status_source;

    setInReplyToStatus(other.inreplytostatus());
    setInReplyToUser(other.inreplytouser());
  }
  return *this;
}

bool Status::operator==(const Tweet &other) const {
  return statusid() == other.statusid();
}
