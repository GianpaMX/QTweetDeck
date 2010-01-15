#-------------------------------------------------
#
# Project created by QtCreator 2010-01-15T09:15:55
#
#-------------------------------------------------

TEMPLATE = lib
DESTDIR = ../lib
OBJECTS_DIR = ../tmp
TARGET = QTweetGui

INCLUDEPATH += ../include
LIBS += -L../lib -lQTweetCore

DEFINES += QTWEETGUI_LIBRARY

SOURCES += qtweetgui.cpp

HEADERS += qtweetgui.h\
        QTweetGui_global.h
