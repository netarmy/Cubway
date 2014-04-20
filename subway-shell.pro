#-------------------------------------------------
#
# Project created by QtCreator 2012-12-01T21:27:39
#
#-------------------------------------------------

QT       += core widgets gui
QT      += webkit webkitwidgets

#CONFIG += c++11

TARGET = subway-shell
TEMPLATE = app

DEFINES += SBW_SH_DEBUG

SOURCES += subway/shell/main.cpp\
        subway/shell/View.cpp\
        subway/shell/ModuleLoader.cpp

HEADERS  += subway/shell/View.hpp\
        subway/shell/ModuleLoader.hpp

