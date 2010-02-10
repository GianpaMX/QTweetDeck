#include <QFile>
#include <QMessageBox>
#include <QByteArray>
#include <QInputDialog>
#include <QDebug>

#include "qtweetdeck.h"

QTweetDeck::QTweetDeck(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("QTweetDeck");

    QByteArray key, secret;
    QFile file;
    file.setFileName("../qtweet_private/consumer.key");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        key = file.readLine();
        file.close();
    }

    file.setFileName("../qtweet_private/consumer.secret");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        secret = file.readLine();
        file.close();
    }

//    QTweetCore::setConsumer(key, secret);
//    QTweetCore::setRequestTimeout( 10000 );
}

QTweetDeck::~QTweetDeck() {
}
