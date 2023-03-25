#include "godfather.h"
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QRect>
#include "qgraphicsitem.h"
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "bulletboss.h"
#include "Game.h"

extern Game * game;
Godfather::Godfather(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
//    int random_number = rand() % 500;
//    setPos(740,random_number);
    setPos(740,250);
//     QPixmap frame1("D://CTU//4_HK1//DH_MayTinh//data//bullet enemy game character//PNG//frame1.png");
//     QPixmap frame2("D://CTU//4_HK1//DH_MayTinh//data//bullet enemy game character//PNG//frame2.png");

//    setPixmap(QPixmap("D://CTU//4_HK1//DH_MayTinh//data//Enemy//Enemy//Godfather ATTACK.png"));
//    setPixmap(frame1.scaled(80, 40));
//    setTransformOriginPoint(50,50);
//    setRotation(-180);
//    position=width(); //vi tri doi tuong
//    positionH=height()/2;
//    x = positionH;
    flag = 0;
     hinh=1;
     hp = 3;
//    timerId=startTimer(100);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer,SIGNAL(timeout()),this,SLOT(draw()));

    // start the timer
    timer->start(50);
    QTimer * timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(attack()));
    // start the timer
    timer2->start(1000);
}
//void Godfather::timerEvent(QTimerEvent *)
//{
////    position-=1;
////    if(position == 0) position=width()/2;

////    if(positionH == x-10)
////        flag =1;
////    if(positionH == x){
////        flag =0;
////    }
////    flag ? positionH++: positionH--;


//    hinh+=1;
//    if(hinh==5) hinh=0;
////    repaint();
//}

//void Godfather::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);
//    painter.setPen(QPen(Qt::red, 5, Qt::SolidLine));
//    drawMegaman(painter);
//}

//void Godfather::drawMegaman(QPainter &painter)
//{
////    QPixmap spritesheet("D://CTU//4_HK1//DH_MayTinh//data//Megaman.png"); //load anh len
////    double wHinh=spritesheet.width()/10; //do rong cua anh nho
////    double hHinh=spritesheet.height(); //do cao cua anh nho

////    QPixmap spritesheet("D://CTU//4_HK1//DH_MayTinh//data//Custom Edited - Mario Customs - Stingby Paper Mario N64-Style1.png");
//    QPixmap spritesheet("D://CTU//4_HK1//DH_MayTinh//data//Enemy//Enemy//Godfather ATTACK.png");
//    double wHinh=spritesheet.width()/5; //do rong cua anh nho
//    double hHinh=spritesheet.height(); //do cao cua anh nho

//    int r=5;
//    //Tao mot cua so co toa do va kich thuoc phu hop voi tung anh nho
//    QRect displayWindow(wHinh*hinh, 0, wHinh, hHinh);
//    //Cua so hien thi tai vi tri position,
//    //co the thay doi cach chay nhanh hay cham bang cach tang hay giam bien r;
//    QRect pos(position*r, positionH*r, wHinh, hHinh);

//    //ve hinh ra voi vi tri cua so da qui dinh
//    painter.drawPixmap(pos, spritesheet, displayWindow);
////    setPixmap(painter);
////    return pixmap;
//}

//QPixmap Godfather::draw(){

//    QPixmap frame1("D://CTU//4_HK1//DH_MayTinh//data//bullet enemy game character//PNG//frame1.png");
//    QPixmap frame2("D://CTU//4_HK1//DH_MayTinh//data//bullet enemy game character//PNG//frame2.png");
//}

void Godfather::draw(){
    QPixmap frame1(":/images/Enemy/GodfatherFrame1.png");
    QPixmap frame2(":/images/Enemy/GodfatherFrame2.png");
    QPixmap frame3(":/images/Enemy/GodfatherFrame3.png");
    QPixmap frame4(":/images/Enemy/GodfatherFrame4.png");
    QPixmap frame5(":/images/Enemy/GodfatherFrame5.png");
    switch (hinh)
    {
    case 1:
        setPixmap(frame1);
        hinh=2;
        break;
    case 2:
        setPixmap(frame2);
        hinh=3;
        break;
    case 3:
        setPixmap(frame3);
        hinh=4;
        break;
    case 4:
        setPixmap(frame4);
        hinh=5;
        break;
    case 5:
        setPixmap(frame5);
        hinh=1;
        break;
    default:
        break;
    }
}

void Godfather::move(){

    // move enemy down

    if(x()>600)
        setPos(x()-7,y());
    if(y() <= 10)
        flag =0;
    if(y()>=500)
        flag = 1;
    if (!flag)
        setPos(x(), y()+7);
    if (flag)
        setPos(x(), y()-7);



    // destroy enemy when it goes out of the screen
    if (pos().x() + 100 < 0){
        //decrease the health
        game->health->decrease();

        if(game->health->getHealth()<0) //Game Over
          {
//            game->close();
          }

        scene()->removeItem(this);
        delete this;
    }
}
void Godfather:: attack(){
    BulletBoss * bulletBoss = new BulletBoss();
    bulletBoss->setPos(x(), y());
    scene()->addItem(bulletBoss);
}

int Godfather:: getHp(){
    return hp;
}
void Godfather:: decreaseHp(){
    hp--;

}
