#-------------------------------------------------
#
# Project created by QtCreator 2015-06-29T02:04:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto2Parcial
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Sort.cpp \
    arista.cpp \
    Vertice.cpp \
    Grafo.cpp

HEADERS  += mainwindow.h \
    Sort.h \
    arista.h \
    Vertice.h \
    Grafo.h

FORMS    += mainwindow.ui \
    Sort.ui \
    Grafo.ui
