# -------------------------------------------------
# Project created by QtCreator 2010-01-15T09:15:55
# -------------------------------------------------
TEMPLATE = lib
DESTDIR = ../lib
OBJECTS_DIR = ../tmp
TARGET = QTweetGui
INCLUDEPATH += ../include
LIBS += -L../lib \
    -lQTweetCore
DEFINES += QTWEETGUI_LIBRARY
SOURCES += qtweetgui.cpp \
    qtweetcolumns.cpp \
    qtweetcolumn.cpp \
    qtweetcolumntitle.cpp \
    qtweetcolumnbuttons.cpp \
    qtweetstatuslistmodel.cpp \
    qtweetpublictimelinemodel.cpp
HEADERS += qtweetgui.h \
    QTweetGui_global.h \
    qtweetcolumns.h \
    qtweetcolumn.h \
    qtweetcolumntitle.h \
    qtweetcolumnbuttons.h \
    qtweetstatuslistmodel.h \
    qtweetpublictimelinemodel.h
RESOURCES += default_image_profile.qrc
CONFIG += crypto
QT += xml network
