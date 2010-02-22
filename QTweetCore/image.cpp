#include "image.h"

using namespace QTweet;

Image::Image(const QString &url, const QByteArray &bytes) {
  image_url = url;
  image_bytes = bytes;
}

QString Image::url() const {
  return image_url;
}
void Image::setUrl(const QString &value) {
  image_url = value;
}

QByteArray Image::bytes() const {
  return image_bytes;
}
void Image::setBytes(const QByteArray &value) {
  image_bytes = value;
}
