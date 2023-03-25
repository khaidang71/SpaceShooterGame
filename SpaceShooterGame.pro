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
    Score.cpp \
    godfather.cpp \
    boom.cpp \
    malphite.cpp \
    bulletboss.cpp \
    enemy2.cpp \
    bulletenemy2.cpp \
    star.cpp \
    explosion.cpp

HEADERS  += \
    Bullet.h \
    Enemy.h \
    Game.h \
    Health.h \
    Player.h \
    Score.h \
    godfather.h \
    boom.h \
    malphite.h \
    bulletboss.h \
    enemy2.h \
    bulletenemy2.h \
    star.h \
    explosion.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
