#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "enemy2.h"
#include "Game.h"
#include <typeinfo>
#include "godfather.h"
#include "boom.h"
#include "stdio.h"
#include "malphite.h"
#include "star.h"
#include "explosion.h"
extern Game * game; // there is an external global object called game



Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw the bullet (a rectangle)
    setPixmap(QPixmap(":/images/Bullet4.png"));
    setTransformOriginPoint(45,55);
    setRotation(90);

    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));    // start the timer
    timer->start(50);
}




void Bullet::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            Boom  *boom = new Boom();
            boom->setPos(x()+50, y());
            scene()->addItem(boom);
            // increase the score
            game->score->increase();

            int random_number = rand() % 10;
            if(random_number == 1){
                Star * star = new Star();
                star->setPos(x()+30, y()-40);
                scene()->addItem(star);
            }

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;



            // return (all code below refers to a non existint bullet)
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Enemy2)){
            game->score->decreaseHpEnemy2();
            if(game->score->getHpEnemy2() == 0){
                game->score->fullHpEnemy2();
                Boom  *boom = new Boom();
                boom->setPos(x()+50, y());
                scene()->addItem(boom);
                // increase the score
                game->score->increase();
                int random_number = rand() % 3;
                if(random_number == 1){
                    Star * star = new Star();
                    star->setPos(x()+30, y()-40);
                    scene()->addItem(star);
                }
                // remove them from the scene (still on the heap)
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                // delete them from the heap to save memory
                delete colliding_items[i];
                delete this;

                // return (all code below refers to a non existint bullet)
                return;
            }
            scene()->removeItem(this);
            delete this;
            return;
        }

        if (typeid(*(colliding_items[i])) == typeid(Godfather)){
            game->score->decreaseHpBoss();
            if(game->score->getHpBoss() == 0){
                Explosion * explosion = new Explosion();
                explosion->setPos(x(), y()-20);
                scene()->addItem(explosion);



                // remove them from the scene (still on the heap)
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);

                // delete them from the heap to save memory
                delete colliding_items[i];
                delete this;


                // return (all code below refers to a non existint bullet)
                return;

            }
                scene()->removeItem(this);
                delete this;
                return;

        }
        if (typeid(*(colliding_items[i])) == typeid(Malphite)){
                // remove them from the scene (still on the heap)
//                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                // delete them from the heap to save memory
//                delete colliding_items[i];
                delete this;


                // return (all code below refers to a non existint bullet)
                return;

        }

    }

    // if there was no collision with an Enemy, move the bullet forward
    setPos(x()+10,y());
    // if the bullet is off the screen, destroy it
    if (pos().x() > 800){
        scene()->removeItem(this);
        delete this;
    }
}
