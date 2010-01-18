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

    columns = new QTweetColumns;
    columns->setBackgroundRole(QPalette::Dark);

    setCentralWidget(columns);

    c = 0;

    QByteArray key, secret;
    QFile file;
    file.setFileName("../qtweet_private/consumer.key");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        key = file.readLine();
    file.close();

    file.setFileName("../qtweet_private/consumer.secret");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        secret = file.readLine();
    file.close();

    QTweetCore::setConsumer(key, secret);
    QTweetCore::setRequestTimeout( 10000 );

    connect(QTweetCore::Client(), SIGNAL(publicTimeLine(QTweetStatusList,QString)), this, SLOT(loadStatusList(QTweetStatusList,QString)));
    QTweetCore::Client()->requestPublicTimeLine();

}

QTweetDeck::~QTweetDeck() {
    if(c) delete c;
    delete columns;

    QTweetCore::term();
}

void QTweetDeck::loadStatusList(const QTweetStatusList &list, const QString& error) {
    if(!error.isEmpty()) {
        QMessageBox::critical(this, "QTweetDeck", error);
        return;
    }

    c = new QTweetColumn(list, "Public Time Line");
    columns->addColumn(c);
}
