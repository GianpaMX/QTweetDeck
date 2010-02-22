#ifndef IMAGE_H
#define IMAGE_H

#include <QString>
#include <QByteArray>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

class QTWEETCORESHARED_EXPORT QTweet::Image {
  public:
    Image(const QString &url = QString(), const QByteArray &bytes = QByteArray());

    QString url() const;
    void setUrl(const QString &value);

    QByteArray bytes() const;
    void setBytes(const QByteArray &value);
  private:
    QString image_url;
    QByteArray image_bytes;
};

#endif // IMAGE_H
