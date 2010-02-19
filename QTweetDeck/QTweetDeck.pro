# -------------------------------------------------
# Project created by QtCreator 2010-01-15T05:23:50
# -------------------------------------------------
TEMPLATE = app
DESTDIR = ../bin
OBJECTS_DIR = ../tmp
TARGET = QTweetDeck
INCLUDEPATH += ../include
LIBS += -L../lib \
    -lQTweetCore \
    -lQTweetGui
SOURCES += main.cpp \
    qtweetdeck.cpp \
    consumer_key_secret.cpp
HEADERS += qtweetdeck.h
QT += xml \
    network \
    sql
CONFIG += crypto
CONFIG += oauth
RESOURCES += 
