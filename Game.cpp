#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include "godfather.h"

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600
//    scene->setSceneRect(0,0,1600,1200);
    QImage img(":/images/bg.jpg");
    QImage img2 = img.scaled(800, 600, Qt::KeepAspectRatio);
//    QImage img2 = img.scaled(1600, 1200, Qt::KeepAspectRatio);
    setBackgroundBrush(QBrush(img2));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
//    setFixedSize(1600,1200);
    // create the player
    player = new Player();
    player->setPos(-50,200); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);


    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1500);
    QTimer * timer2 = new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(spawn2()));
    timer2->start(4000);
    QTimer * timerb = new QTimer();
    QObject::connect(timerb,SIGNAL(timeout()),player,SLOT(spawnb()));
    timerb->start(20);
    QTimer * timerEnemy2 = new QTimer();
    QObject::connect(timerEnemy2,SIGNAL(timeout()),player,SLOT(spawnEnemy2()));
    timerEnemy2->start(3000);

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/SkyFire.mp3"));
//    music->play();

    show();

    delete parent;
}


