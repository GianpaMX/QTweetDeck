#ifndef USER_H
#define USER_H

#include <QtGlobal>
#include <QtXml>
#include <QString>
#include <QByteArray>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

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

    QString profileimageurl() const;
    void setProfileImageUrl(const QString &value);

    QByteArray profileimagebytearray() const;
    void setProfileImageByteArray(const QByteArray &value);

    User &operator=(const User &other);
  private:
    qulonglong user_id;
    QString user_name;
    QString user_screen_name;
    QString user_profile_image_url;
    QByteArray user_profile_image_bytearray;
};

#endif // USER_H
