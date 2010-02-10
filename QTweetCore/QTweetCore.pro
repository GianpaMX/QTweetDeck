# -------------------------------------------------
# Project created by QtCreator 2010-01-15T05:22:31
# -------------------------------------------------
TEMPLATE = lib
DESTDIR = ../lib
OBJECTS_DIR = ../tmp
TARGET = QTweetCore
DEFINES += QTWEETCORE_LIBRARY
SOURCES += client.cpp \
    abstractclient.cpp \
    user.cpp \
    status.cpp \
    statuslist.cpp
HEADERS += QTweetCore_global.h \
    client.h \
    abstractclient.h \
    qtweetcore.h \
    user.h \
    status.h \
    statuslist.h
QT += network \
    xml
QT -= gui
CONFIG += oauth
