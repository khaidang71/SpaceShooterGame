#include "malphite.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include "Player.h"
#include "explosion.h"
#include <typeinfo>
extern Game * game;
Malphite::Malphite(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set random x position
    int random_number = rand() % 500;
    setPos(740,random_number);

    // drew the rect
    setPixmap(QPixmap(":/images/Enemy/astroid.png").scaled(60,60));
    setTransformOriginPoint(50,50);
    setRotation(-90);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    // start the timer
    timer->start(80);
}

void Malphite::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();
//    Boom *boom = new Boom();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){

        if (typeid(*(colliding_items[i])) == typeid(Player)){
//            boom->setPos(x()+50, y());
//            scene()->addItem(boom);
            // increase the score

            // remove them from the scene (still on the heap)
            scene()->removeItem(this);
            // delete them from the heap to save memory
            delete this;
            // return (all code below refers to a non existint bullet)
            return;
        }
    }
//        game->player->setOpacity(1);




    // move enemy down
    setPos(x()-7,y());

    // destroy enemy when it goes out of the screen
    if (pos().x() + 100 < 0){
        //decrease the health
//        game->health->decrease();

//        if(game->health->getHealth()<0) //Game Over
//          {
//            game->close();
//          }

        scene()->removeItem(this);
        delete this;
    }
}
