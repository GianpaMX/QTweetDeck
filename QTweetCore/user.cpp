#include "user.h"

using namespace QTweet;

User::User() {
  user_id = 0;
}
User::User(const User &other) {
  *this = other;
}
User::~User() {
}


void User::readDomElement(const QDomElement& xmluser) {
  setUserId(xmluser.firstChildElement("id").text().toULongLong());
  setName(xmluser.firstChildElement("name").text());
  setScreenName(xmluser.firstChildElement("screen_name").text());
  setProfileImage(Image(xmluser.firstChildElement("profile_image_url").text()));
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

Image User::profileImage() const {
  return user_profile_image;
}
void User::setProfileImage(const Image &value) {
  user_profile_image = value;
}

User &User::operator=(const User &other) {
  if( this != &other ) {
    user_id = other.user_id;
    user_name = other.user_name;
    user_screen_name = other.user_screen_name;
    user_profile_image = other.user_profile_image;
  }
  return *this;
}
