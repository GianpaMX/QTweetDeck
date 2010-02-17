#include "publictimelineclient.h"

using namespace QTweet;

PublicTimeLineClient::PublicTimeLineClient(QObject *parent) : AbstractUpdatableClient(parent) {
}

Reply *PublicTimeLineClient::requestDefaultData() {
  return requestPublicTimeLine();
}
