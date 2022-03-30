#-------------------------------------------------
#
# Project created by QtCreator 2021-12-03T21:32:12
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpaceShipWar
TEMPLATE = app


SOURCES += main.cpp \
    badie.cpp \
    game.cpp \
    laser.cpp \
    score.cpp \
    ship.cpp \
    ui.cpp \
    healthbar.cpp

HEADERS  += \
    badie.h \
    game.h \
    laser.h \
    score.h \
    ship.h \
    ui.h \
    healthbar.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
