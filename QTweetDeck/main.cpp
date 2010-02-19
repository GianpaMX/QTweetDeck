#include <QtGui/QApplication>
#include "qtweetdeck.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  QTweetDeck w;
  w.show();

  return a.exec();
}
