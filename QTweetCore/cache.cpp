#include <QDebug>
#include "cache.h"
#include "status.h"

using namespace QTweet;

Cache *Cache::instance = 0;

Cache::Cache(const QString &cache_name) {
  db = QSqlDatabase::addDatabase("QSQLITE");
  cache_error = initDb(cache_name);
}
Cache::Cache(const Cache &/*other*/) {
}
Cache::~Cache() {
  if( db.isOpen() )
    db.close();
}

void Cache::Initialize(const QString &cache_name) {
  if(Cache::instance != 0 ) return;

  Cache::instance = new Cache(cache_name);
}
void Cache::Finalize() {
  if(Cache::instance == 0 ) return;

  delete Cache::instance;
  Cache::instance = 0;
}

bool Cache::isEnabled() {
  return Cache::instance != 0;
}


QSqlError Cache::error() const {
  return cache_error;
}

QSqlError Cache::initDb(const QString &cache_name) {
  db.setDatabaseName(cache_name);

  if ( !db.open() )
    return db.lastError();

  QStringList tables = db.tables();
  if(tables.contains("image", Qt::CaseInsensitive) && tables.contains("user", Qt::CaseInsensitive) && tables.contains("status", Qt::CaseInsensitive))
    return QSqlError();

  QSqlQuery q;
  if(!q.exec(QLatin1String("CREATE TABLE image(url TEXT NOT NULL, bytes BLOB)")))
    return q.lastError();
  if(!q.exec(QLatin1String("CREATE TABLE user(id INTEGER PRIMARY KEY NOT NULL, name TEXT, screen_name TEXT NOT NULL, profile_image_url TEXT)")))
    return q.lastError();
  if(!q.exec(QLatin1String("CREATE TABLE status(id INTEGER PRIMARY KEY NOT NULL, create_at TEXT, text TEXT, source TEXT, in_reply_to_status_id INTEGER, in_reply_to_user_id INTEGER, in_reply_to_screen_name TEXT)")))
    return q.lastError();

  return QSqlError();
}

Cache &Cache::Data() {
  return *instance;
}

bool Cache::Exists(const Status &status) {
  QSqlQuery q;
  if(q.prepare(QLatin1String("SELECT * FROM status WHERE id = ?"))) {
    q.addBindValue(status.statusid());
    q.exec();
    return q.next() == true;
  }

  return false;
}
bool Cache::Exists(const User &user) {
  QSqlQuery q;
  if(q.prepare(QLatin1String("SELECT * FROM user WHERE id = ?"))) {
    q.addBindValue(user.userid());
    q.exec();
    return q.next() == true;
  }

  return false;
}
bool Cache::Exists(const Image &image) {
  QSqlQuery q;
  if(q.prepare(QLatin1String("SELECT * FROM image WHERE url = ?"))) {
    q.addBindValue(image.url());
    q.exec();
    return q.next() == true;
  }

  return false;
}

Cache &Cache::operator<<(const Status &status) {
  if(status.statusid() != 0 ) {
    QSqlQuery q;

    if( Exists(status) ) {
      if(q.prepare(QLatin1String("DELETE FROM FROM status WHERE id = ?"))) {
        q.addBindValue(status.statusid());
        q.exec();
      }
    }

    if(q.prepare(QLatin1String("INSERT INTO status(id, create_at, text, source, in_reply_to_status_id, in_reply_to_user_id, in_reply_to_screen_name) values(?, ?, ?, ?, ?, ?, ?)"))) {
      q.addBindValue(status.statusid());
      q.addBindValue(status.createat());
      q.addBindValue(status.text());
      q.addBindValue(status.source());
      q.addBindValue((status.inreplytostatus()!=0)?status.inreplytostatus()->statusid():0);
      q.addBindValue((status.inreplytouser()!=0)?status.inreplytouser()->userid():0);
      q.addBindValue((status.inreplytouser()!=0)?status.inreplytouser()->screenname():QString());
      q.exec();
    }
  }

  *this << static_cast<const User &>(status);

  return *this;
}

Cache &Cache::operator>>(Status &status) {
  if(status.statusid() != 0) {
    QSqlQuery q;
    if(q.prepare(QLatin1String("SELECT create_at, text, source, in_reply_to_status_id, in_reply_to_user_id, in_reply_to_screen_name FROM status WHERE id = ?"))) {
      q.addBindValue(status.statusid());
      q.exec();
      while (q.next()) {
        status.setCreateAt(q.value(0).toDateTime());
        status.setText(q.value(1).toString());
        status.setSource(q.value(2).toString());

        Status in_reply_to_status;
        in_reply_to_status.setStatusId(q.value(3).toULongLong());
        status.setInReplyToStatus(&in_reply_to_status);
        *this >> *status.inreplytostatus();

        User in_reply_to_user;
        in_reply_to_user.setUserId(q.value(4).toULongLong());
        in_reply_to_user.setScreenName(q.value(5).toString());
        status.setInReplyToUser(&in_reply_to_user);
        *this >> *status.inreplytouser();
      }
    }
  }
  *this >> static_cast<User &>(status);
  return *this;
}

Cache &Cache::operator<<(const User &user) {
  if(user.userid() != 0 ) {
    QSqlQuery q;

    if(Exists(user)) {
      if(q.prepare(QLatin1String("DELETE FROM FROM user WHERE id = ?"))) {
        q.addBindValue(user.userid());
        q.exec();
      }
    }

    if(q.prepare(QLatin1String("INSERT INTO user(id, name, screen_name, profile_image_url) values(?, ?, ?, ?)"))) {
      q.addBindValue(user.userid());
      q.addBindValue(user.name());
      q.addBindValue(user.screenname());
      q.addBindValue(user.profileImage().url());
      q.exec();
    }
  }
  return *this;
}

Cache &Cache::operator>>(User &user) {
  if(user.userid() != 0 || user.screenname() != "") {
    QSqlQuery q;
    if(q.prepare(QLatin1String("SELECT id, name, screen_name, profile_image_url FROM user WHERE id = ? OR screen_name = ?"))) {
      q.addBindValue(user.userid());
      q.addBindValue(user.screenname());
      q.exec();
      while (q.next()) {
        user.setUserId(q.value(0).toULongLong());
        user.setName(q.value(1).toString());
        user.setScreenName(q.value(2).toString());
        user.setProfileImage(Image(q.value(3).toString()));
      }
    }
  }
  return *this;
}


Cache &Cache::operator<<(const Image &image) {
  if(image.url() != "" ) {
    QSqlQuery q;

    if(Exists(image)) {
      if(q.prepare(QLatin1String("DELETE FROM image WHERE url = ?"))) {
        q.addBindValue(image.url());
        if(!q.exec()) qDebug() << q.lastError().text();
      } else
        qWarning() << q.lastError().text();
    }

    if(q.prepare(QLatin1String("INSERT INTO image(url, bytes) values(?, ?)"))) {
      q.addBindValue(image.url());
      q.addBindValue(image.bytes());
      if(!q.exec()) qDebug() << q.lastError().text();
    }
  }
  return *this;
}

Cache &Cache::operator>>(Image &image) {
  if(image.url() != "") {
    QSqlQuery q;
    if(q.prepare(QLatin1String("SELECT bytes FROM image WHERE url = ?"))) {
      q.addBindValue(image.url());
      q.exec();
      while (q.next()) {
        image.setBytes(q.value(0).toByteArray());
      }
    }
  }
  return *this;
}
