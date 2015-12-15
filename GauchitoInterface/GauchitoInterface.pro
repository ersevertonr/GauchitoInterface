#-------------------------------------------------
#
# Project created by QtCreator 2015-12-07T09:08:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GauchitoInterface
TEMPLATE = app


SOURCES += main.cpp\
        gauchitointerface.cpp \
    centralmonitoramento.cpp \
    controleacoes.cpp

HEADERS  += gauchitointerface.h \
    centralmonitoramento.h \
    controleacoes.h

FORMS    += gauchitointerface.ui \
    centralmonitoramento.ui \
    controleacoes.ui

RESOURCES += \
    imagens.qrc
