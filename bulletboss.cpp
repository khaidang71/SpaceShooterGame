#include "bulletboss.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include <typeinfo>
#include "godfather.h"
#include "boom.h"
#include "stdio.h"
#include "malphite.h"
extern Game * game;
BulletBoss::BulletBoss(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // draw the bullet (a rectangle)
//    setPixmap(QPixmap(":/images/Bullet4.png"));
    setTransformOriginPoint(45,55);
//    setRotation(90);
    hinh=1;
    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer,SIGNAL(timeout()),this,SLOT(draw()));
    // start the timer
    timer->start(50);
}

void BulletBoss::draw(){
    QPixmap frame1("D:/CTU/4_HK1/DH_MayTinh/data/bullet enemy game character/PNG/frame1.png");
    QPixmap frame2("D:/CTU/4_HK1/DH_MayTinh/data/bullet enemy game character/PNG/frame2.png");

    switch (hinh)
    {
    case 1:
        setPixmap(frame1.scaled(80,40));
        hinh=2;
        break;
    case 2:
        setPixmap(frame2.scaled(80,40));
        hinh=1;
        break;

    default:
        break;
    }
}

void BulletBoss::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();
//    Boom *boom = new Boom();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            game->player->setOpacity(0);


//            boom->setPos(x()+50, y());
//            scene()->addItem(boom);
            // increase the score
            game->health->decrease();

            // remove them from the scene (still on the heap)
//            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them from the heap to save memory
//            delete colliding_items[i];
            delete this;
            // return (all code below refers to a non existint bullet)
            return;
        }

    }
    game->player->setOpacity(1);

    // if there was no collision with an Enemy, move the bullet forward
    setPos(x()-10,y());
    // if the bullet is off the screen, destroy it
    if (pos().x() + 100 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
