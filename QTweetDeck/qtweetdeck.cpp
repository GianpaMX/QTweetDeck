#include <QMessageBox>
#include <QByteArray>
#include <QInputDialog>
#include <QDebug>

#include "qtweetdeck.h"
#include "qtweetcolumn.h"
#include "qtweetcore.h"

QTweetDeck::QTweetDeck(QWidget *parent) : QMainWindow(parent) {
    QTweetCore::init(this);

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

    QTweetCore::setConsumer(key, secret);
    QTweetCore::setRequestTimeout( 10000 );


    columns = new QTweetColumns;
    columns->setBackgroundRole(QPalette::Dark);
    setCentralWidget(columns);

    model = new QTweetPublicTimeLineModel;
    c = new QTweetColumn(model, "Public Time Line");
    columns->addColumn(c);
}

QTweetDeck::~QTweetDeck() {
    if(c) delete c;
    if(model) delete model;
    if(columns) delete columns;

    QTweetCore::term();
}
