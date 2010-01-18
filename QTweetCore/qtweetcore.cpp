#include "qtweetcore.h"

QOAuth::Interface* QTweetCore::qoauth = 0;
QTweetClient* QTweetCore::client = 0;

QTweetCore::QTweetCore() {
}

void QTweetCore::init(QObject* parent) {
    if(QTweetCore::qoauth == 0) QTweetCore::qoauth = new QOAuth::Interface(parent);
    if(QTweetCore::client == 0) QTweetCore::client = new QTweetClient(parent);
}
void QTweetCore::term() {
    if(QTweetCore::qoauth != 0) delete QTweetCore::qoauth;
    if(QTweetCore::client != 0) delete QTweetCore::client;
}

void QTweetCore::setConsumer(const QByteArray& key, const QByteArray& secret) {
    QTweetCore::qoauth->setConsumerKey(key);
    QTweetCore::qoauth->setConsumerSecret(secret);
}

void QTweetCore::setRequestTimeout(uint requestTimeout) {
    QTweetCore::qoauth->setRequestTimeout(requestTimeout);
}

QTweetClient* QTweetCore::Client() {
    return client;
}
