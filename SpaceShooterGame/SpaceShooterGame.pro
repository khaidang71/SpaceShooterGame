#-------------------------------------------------
#
# Project created by QtCreator 2022-10-30T19:00:44
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpaceShooterGame
TEMPLATE = app


SOURCES += main.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    Health.cpp \
    Player.cpp \
    Score.cpp

HEADERS  += \
    Bullet.h \
    Enemy.h \
    Game.h \
    Health.h \
    Player.h \
    Score.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
