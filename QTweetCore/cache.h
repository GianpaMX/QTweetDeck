#ifndef CACHE_H
#define CACHE_H

#include <QtSql>
#include <QString>

#include "qtweetcore.h"
#include "QTweetCore_global.h"

class QTWEETCORESHARED_EXPORT QTweet::Cache {
  public:
    QSqlError error() const;

    static void Initialize(const QString &cache_name = ":memory:");
    static Cache &Data();
    static void Finalize();

    static bool isEnabled();

    Cache &operator<<(const Status &status);
    Cache &operator>>(Status &status);

    Cache &operator<<(const User &user);
    Cache &operator>>(User &user);
  private:
    Cache(const QString &cache_name);
    Cache(const Cache &other);
    ~Cache();

    QSqlError cache_error;
    QSqlError initDb(const QString &cache_name);
    QSqlDatabase db;

    static Cache *instance;
};

#endif // CACHE_H
