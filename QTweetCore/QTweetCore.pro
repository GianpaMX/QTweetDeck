#-------------------------------------------------
#
# Project created by QtCreator 2010-01-15T05:22:31
#
#-------------------------------------------------

TEMPLATE = lib
DESTDIR = ../lib
OBJECTS_DIR = ../tmp
TARGET = QTweetCore

DEFINES += QTWEETCORE_LIBRARY

SOURCES += qtweetcore.cpp

HEADERS += qtweetcore.h\
        QTweetCore_global.h

QT       += network xml
QT       -= gui
