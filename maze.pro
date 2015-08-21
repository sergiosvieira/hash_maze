#-------------------------------------------------
#
# Project created by QtCreator 2015-08-21T11:58:39
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = maze
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mazecanvas.cpp

HEADERS  += mainwindow.h \
    mazecanvas.h \
    maze.h

FORMS    += mainwindow.ui
