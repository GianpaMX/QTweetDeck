# -------------------------------------------------
# Project created by QtCreator 2010-01-15T05:22:31
# -------------------------------------------------
TEMPLATE = lib
DESTDIR = ../lib
OBJECTS_DIR = ../tmp
INCLUDEPATH += ../include
TARGET = QTweetCore
DEFINES += QTWEETCORE_LIBRARY
SOURCES += client.cpp \
    abstractclient.cpp \
    user.cpp \
    status.cpp \
    statuslist.cpp \
    qtweetcore.cpp \
    reply.cpp \
    oauth.cpp \
    abstractupdatableclient.cpp \
    publictimelineclient.cpp \
    cache.cpp \
    usertimelineclient.cpp \
    image.cpp
HEADERS += QTweetCore_global.h \
    client.h \
    abstractclient.h \
    qtweetcore.h \
    user.h \
    status.h \
    statuslist.h \
    reply.h \
    tweet.h \
    tweets.h \
    oauth.h \
    updatable.h \
    abstractupdatableclient.h \
    creatable.h \
    dataarrived.h \
    publictimelineclient.h \
    cache.h \
    usertimelineclient.h \
    image.h
QT += network \
    xml \
    sql
QT -= gui
CONFIG += oauth
RESOURCES += 
