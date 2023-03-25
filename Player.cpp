#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include "enemy2.h"
#include "Game.h"
#include "godfather.h"
#include "malphite.h"
#include "QTimer"
#include "star.h"
extern Game * game; // there is an external global object called game
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/laser4.wav"));
    b = 0;
    hinh=1;
    //set graphic
//    setPixmap(QPixmap(":/images/player_red.png"));
    setTransformOriginPoint(60,50);
    setRotation(90);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(draw()));

    // start the timer
    timer->start(50);
}

void Player::keyPressEvent(QKeyEvent *event){

    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > -50)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + 100 < 640)
            setPos(x(),y()+10);
    }
    else if (event->key() == Qt::Key_Up){
        if (pos().y() + 100 > 100)
            setPos(x(),y()-10);
    }
    // shoot with the spacebar
    if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+15,y()+5);
        scene()->addItem(bullet);

        //play bulletsound
        if(bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }

    }
}

void Player::spawn(){
    // create an enemy


    if(game->score->getScore() < 50) {
        Enemy * enemy = new Enemy();
        scene()->addItem(enemy);
    }


}
void Player::spawnb(){
    if(game->score->getScore() == 50 && b == 0){
        b = 1;
    }
    if(b == 1){
        Godfather * godfather = new Godfather();
        scene()->addItem(godfather);
        b=2;
    }
}

void Player::draw()
{
    QPixmap frame1(":/images/player/nplayer-0.png");
    QPixmap frame2(":/images/player/nplayer-1.png");
    switch (hinh)
    {
    case 1:
        setPixmap(frame1);
        hinh=2;
        break;
    case 2:
        setPixmap(frame2);
        hinh=1;
        break;
    default:
        break;
    }
}

void Player::spawnStar()
{
    Star * star = new Star();
    scene()->addItem(star);
}
void Player::spawnEnemy2(){
    if(game->score->getScore() >10 && game->score->getScore() < 50 ){
        Enemy2 * enemy2 = new Enemy2();
        scene()->addItem(enemy2);
    }
}

void Player::spawn2(){
    if(game->score->getScore() < 50) {
        Malphite * malphite = new Malphite();
        scene()->addItem(malphite);
    }
}

