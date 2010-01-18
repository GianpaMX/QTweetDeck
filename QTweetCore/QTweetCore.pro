# -------------------------------------------------
# Project created by QtCreator 2010-01-15T05:22:31
# -------------------------------------------------
TEMPLATE = lib
DESTDIR = ../lib
OBJECTS_DIR = ../tmp
TARGET = QTweetCore
DEFINES += QTWEETCORE_LIBRARY
SOURCES += qtweetcore.cpp \
    qtweetuser.cpp \
    qtweetstatus.cpp \
    qtweetstatuslist.cpp \
    qtweetclient.cpp
HEADERS += qtweetcore.h \
    QTweetCore_global.h \
    qtweetuser.h \
    qtweetstatus.h \
    qtweetstatuslist.h \
    qtweetclient.h
QT += network \
    xml
QT -= gui
CONFIG += oauth
