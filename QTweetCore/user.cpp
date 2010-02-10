#include "user.h"

using namespace QTweet;

User::User() {
}

void User::readDomElement(const QDomElement& xmluser) {
  setUserId(xmluser.firstChildElement("id").text().toULongLong());
  setName(xmluser.firstChildElement("name").text());
  setScreenName(xmluser.firstChildElement("screen_name").text());
  setProfileImageUrl(xmluser.firstChildElement("profile_image_url").text());
}

qulonglong User::userid() const {
  return user_id;
}
void User::setUserId(qulonglong value) {
  user_id = value;
}

QString User::name() const {
  return user_name;
}
void User::setName(const QString &value) {
  user_name = value;
}

QString User::screenname() const {
  return user_screen_name;
}
void User::setScreenName(const QString &value) {
  user_screen_name = value;
}

QString User::profileimageurl() const {
  return user_profile_image_url;
}
void User::setProfileImageUrl(const QString &value) {
  user_profile_image_url = value;
}
