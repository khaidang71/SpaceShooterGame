#include "enemy2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <bulletboss.h>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include "Player.h"
#include <typeinfo>
#include <math.h>
#include "bulletenemy2.h"
extern Game * game;
Enemy2::Enemy2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set random x position
    int random_number = rand() % 500;
    setPos(740,random_number);

    // drew the rect
    setPixmap(QPixmap(":/images/enemy2.png").scaled(80,80));
    setTransformOriginPoint(50,50);
    setRotation(-90);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    // start the timer
    timer->start(100);

    QTimer * timerAttack = new QTimer();
    connect(timerAttack,SIGNAL(timeout()),this,SLOT(attack()));
    // start the timer
    timerAttack->start(2000);
}
void Enemy2::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();
//    Boom *boom = new Boom();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){

        if (typeid(*(colliding_items[i])) == typeid(Player)){
//            boom->setPos(x()+50, y());
//            scene()->addItem(boom);
            // increase the score
            game->health->decrease();
//            if(game->health->getHealth()<=0) //Game Over
//              {
//                game->close();
//              }
            game->player->setOpacity(0);

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




    // move enemy down
    setPos(x()-6,4 *sin(x())+y());

    // destroy enemy when it goes out of the screen
    if (pos().x() + 100 < 0){
        //decrease the health
//        game->health->decrease();

//        if(game->health->getHealth()<=0) //Game Over
//          {
//            game->close();
//          }

        scene()->removeItem(this);
        delete this;
    }
}

void Enemy2::attack()
{
    BulletEnemy2 * bulletenemy2 = new BulletEnemy2();
    bulletenemy2->setPos(x(), y()-30);
    scene()->addItem(bulletenemy2);
}
