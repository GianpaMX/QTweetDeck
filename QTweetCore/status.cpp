#include "status.h"

using namespace QTweet;

Status::Status() : User() {
}
Status::Status(const Status &other) : User(other) {
  *this = other;
}

void Status::readDomElement(const QDomElement& xmluser) {
  setStatusId(xmluser.firstChildElement("id").text().toULongLong());
  setCreateAt(fromStringDateTime(xmluser.firstChildElement("created_at").text()));
  setText(xmluser.firstChildElement("text").text());
  setSource(xmluser.firstChildElement("source").text());
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

QDateTime Status::datetime() const {
  return createat();
}

Status &Status::operator=(const Status &other) {
  if( this != &other ) {
    status_id = other.status_id;
    status_created_at = other.status_created_at;
    status_text = other.status_text;
    status_source = other.status_source;
  }
  return *this;
}
