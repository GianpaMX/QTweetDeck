#include <QByteArray>

#include "qtweetclient.h"
#include "qtweetstatus.h"

QTweetClient::QTweetClient(QObject * parent) : QThread(parent) {
    manager = new QNetworkAccessManager(this);
    secs = 0;
    connect(this, SIGNAL(beforeRequest()), this, SLOT(requestList()));
}
QTweetClient::QTweetClient(unsigned long refreshevery, QObject * parent) : QThread(parent) {
    manager = new QNetworkAccessManager(this);
    secs = refreshevery;
    connect(this, SIGNAL(beginRequest()), this, SLOT(requestList()));
}

QTweetClient::~QTweetClient() {
    secs = 0;
    wait();
    
    if(reply) delete reply;
    if(manager) delete manager;
}

void QTweetClient::run() {
    while(secs) {
        sleep(secs);
        if(secs) emit beforeRequest();
    }
}

void QTweetClient::setRefresh(unsigned long refreshevery) {
    secs = refreshevery;
    start();
}
