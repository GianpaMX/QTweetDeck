TEMPLATE      = subdirs
SUBDIRS       = \
                QTweetCore \
                QTweetGui \
                QTweetDeck

system(cp -v QTweetCore/*.h include/)
system(cp -v QTweetGui/*.h include/)
