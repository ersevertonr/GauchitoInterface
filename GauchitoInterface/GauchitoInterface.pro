#-------------------------------------------------
#
# Project created by QtCreator 2015-12-07T09:08:19
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GauchitoInterface
TEMPLATE = app


SOURCES += main.cpp\
        gauchitointerface.cpp \
    controleacoes.cpp

HEADERS  += gauchitointerface.h \
    controleacoes.h

FORMS    += gauchitointerface.ui \
    controleacoes.ui

QMAKE_CXXFLAGS += -std=gnu++11

RESOURCES += \
    imagens.qrc
