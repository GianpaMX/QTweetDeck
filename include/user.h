#ifndef USER_H
#define USER_H

#include <QtGlobal>
#include <QtXml>
#include <QString>
#include <QByteArray>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

#include "image.h"

class QTWEETCORESHARED_EXPORT QTweet::User {
  public:
    User();
    User(const User &other);
    virtual ~User();

    void readDomElement(const QDomElement& xmluser);

    qulonglong userid() const;
    void setUserId(qulonglong value);

    QString name() const;
    void setName(const QString &value);

    QString screenname() const;
    void setScreenName(const QString &value);

    Image profileImage() const;
    void setProfileImage(const Image &value);

    User &operator=(const User &other);
  private:
    qulonglong user_id;
    QString user_name;
    QString user_screen_name;
    Image user_profile_image;
};

#endif // USER_H
