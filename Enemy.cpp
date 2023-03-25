#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include "Player.h"
#include <typeinfo>
#include <math.h>
extern Game * game;
Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = rand() % 500;
    setPos(740,random_number);

    // drew the rect
    setPixmap(QPixmap(":/images/enemy.png"));
    setTransformOriginPoint(50,50);
    setRotation(-90);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(40);
}


//Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
//    //set random x position
//    int random_number = rand() % 700;
//    setPos(random_number,0);

//    // drew the rect
//    setRect(0,0,100,100);

//    // make/connect a timer to move() the enemy every so often
//    QTimer * timer = new QTimer(this);
//    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

//    // start the timer
//    timer->start(50);
//}

void Enemy::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();
//    Boom *boom = new Boom();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){

        if (typeid(*(colliding_items[i])) == typeid(Player)){
            Boom  *boom = new Boom();
            boom->setPos(x(), y()+20);
            scene()->addItem(boom);
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
    setPos(x()-7,4 *sin(x())+y());

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
