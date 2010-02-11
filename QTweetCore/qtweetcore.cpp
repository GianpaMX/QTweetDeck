#include <cstdio>
#include "qtweetcore.h"

QDateTime QTweet::fromStringDateTime(const QString& string) {
  // this was taken from: Choqok, the KDE micro-blogging client
  // http://choqok.sourcearchive.com/documentation/0.6.1-0ubuntu3/backend_8cpp-source.html

  char s[10];
  int year, day, hours, minutes, seconds;
  QMap<QString, int> monthes;

  monthes.insert("Jan", 1);
  monthes.insert("Feb", 2);
  monthes.insert("Mar", 3);

  monthes.insert("Apr", 4);
  monthes.insert("May", 5);
  monthes.insert("Jun", 6);

  monthes.insert("Jul", 7);
  monthes.insert("Ago", 8);
  monthes.insert("Sep", 9);

  monthes.insert("Oct", 10);
  monthes.insert("Nov", 11);
  monthes.insert("Dec", 12);

  sscanf( qPrintable( string ), "%*s %s %d %d:%d:%d %*s %d", s, &day, &hours, &minutes, &seconds, &year );
  QString s2(s);

  int month = s2=="Jan"?1:
    s2=="Feb"?2:
    s2=="Mar"?3:
    s2=="Apr"?4:
    s2=="May"?5:
    s2=="Jun"?6:
    s2=="Jul"?7:
    s2=="Ago"?8:
    s2=="Sep"?9:
    s2=="Oct"?10:
    s2=="Nov"?11:12;

  QDateTime recognized = QDateTime(QDate(year, month, day), QTime(hours, minutes, seconds));

  recognized.setTimeSpec( Qt::UTC );
  return recognized.toLocalTime();
}
