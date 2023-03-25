#include "explosion.h"
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QRect>
#include "qgraphicsitem.h"
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
//#include "Game.h"
//extern Game * game;
Explosion::Explosion(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    boomsound = new QMediaPlayer();
    boomsound->setMedia(QUrl("qrc:/sounds/Chunky_Explosion.mp3"));
    hinh=1;
//    timerId=startTimer(100);

   // make/connect a timer to move() the enemy every so often
   QTimer * timer = new QTimer();
//   connect(timer,SIGNAL(timeout()),this,SLOT(move()));
   connect(timer,SIGNAL(timeout()),this,SLOT(draw()));
   // start the timer
   timer->start(30);

   //play bulletsound
   if(boomsound->state() == QMediaPlayer::PlayingState){
       boomsound->setPosition(0);
   }
   else if(boomsound->state() == QMediaPlayer::StoppedState){
       boomsound->play();
   }
}

void Explosion::draw()
{
    QPixmap frame1(":/images/Explosion/explosion1.png");
    QPixmap frame2(":/images/Explosion/explosion2.png");
    QPixmap frame3(":/images/Explosion/explosion3.png");
    QPixmap frame4(":/images/Explosion/explosion4.png");
    QPixmap frame5(":/images/Explosion/explosion5.png");
    QPixmap frame6(":/images/Explosion/explosion6.png");
    QPixmap frame7(":/images/Explosion/explosion7.png");
    QPixmap frame8(":/images/Explosion/explosion8.png");
    QPixmap frame9(":/images/Explosion/explosion9.png");
    QPixmap frame10(":/images/Explosion/explosion10.png");
    QPixmap frame11(":/images/Explosion/explosion11.png");
    QPixmap frame12(":/images/Explosion/explosion12.png");
    QPixmap frame13(":/images/Explosion/explosion13.png");
    QPixmap frame14(":/images/Explosion/explosion14.png");
    QPixmap frame15(":/images/Explosion/explosion15.png");
    QPixmap frame16(":/images/Explosion/explosion16.png");


    switch (hinh)
    {
    case 1:
        setPixmap(frame1.scaled(200,200));
        hinh=2;
        break;
    case 2:
        setPixmap(frame2.scaled(200,200));
        hinh=3;
        break;
    case 3:
        setPixmap(frame3.scaled(200,200));
        hinh=4;
        break;
    case 4:
        setPixmap(frame4.scaled(200,200));
        hinh=5;
        break;
    case 5:
        setPixmap(frame5.scaled(200,200));
        hinh=6;
        break;
    case 6:
        setPixmap(frame6.scaled(200,200));
        hinh=7;
        break;
    case 7:
        setPixmap(frame7.scaled(200,200));
        hinh=8;
        break;
    case 8:
        setPixmap(frame8.scaled(200,200));
        hinh=9;
        break;
    case 9:
        setPixmap(frame9.scaled(200,200));
        hinh=10;
        break;
    case 10:
        setPixmap(frame10.scaled(200,200));
        hinh=11;
        break;
    case 11:
        setPixmap(frame11.scaled(200,200));
        hinh=12;
        break;
    case 12:
        setPixmap(frame12.scaled(200,200));
        hinh=13;
        break;
    case 13:
        setPixmap(frame13.scaled(200,200));
        hinh=14;
        break;
    case 14:
        setPixmap(frame14.scaled(200,200));
        hinh=15;
        break;
    case 15:
        setPixmap(frame15.scaled(200,200));
        hinh=16;
        break;
    case 16:
        setPixmap(frame16.scaled(200,200));
        hinh=0;
        break;
    case 0:
        scene()->removeItem(this);
        delete this;
        break;
    default:
        scene()->removeItem(this);
        delete this;
        break;
    }
}
