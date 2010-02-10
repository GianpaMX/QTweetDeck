#ifndef USER_H
#define USER_H

#include <QtGlobal>
#include <QtXml>
#include <QString>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

class QTWEETCORESHARED_EXPORT QTweet::User {
  public:
    User();

    void readDomElement(const QDomElement& xmluser);

    qulonglong userid() const;
    void setUserId(qulonglong value);

    QString name() const;
    void setName(const QString &value);

    QString screenname() const;
    void setScreenName(const QString &value);

    QString profileimageurl() const;
    void setProfileImageUrl(const QString &value);
  private:
    qulonglong user_id;
    QString user_name;
    QString user_screen_name;
    QString user_profile_image_url;
};

#endif // USER_H
