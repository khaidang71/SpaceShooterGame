#include "boom.h"
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

Boom::Boom(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
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


void Boom::draw(){
    QPixmap frame1(":/images/Boom/BOOMFrame1.png");
    QPixmap frame2(":/images/Boom/BOOMFrame2.png");
    QPixmap frame3(":/images/Boom/BOOMFrame3.png");
    QPixmap frame4(":/images/Boom/BOOMFrame4.png");
    QPixmap frame5(":/images/Boom/BOOMFrame5.png");
    switch (hinh)
    {
    case 1:
        setPixmap(frame1.scaled(70,70));
        hinh=2;
        break;
    case 2:
        setPixmap(frame2.scaled(70,70));
        hinh=3;
        break;
    case 3:
        setPixmap(frame3.scaled(70,70));
        hinh=4;
        break;
    case 4:
        setPixmap(frame4.scaled(70,70));
        hinh=5;
        break;
    case 5:
        setPixmap(frame5.scaled(70,70));
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
