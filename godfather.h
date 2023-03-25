#ifndef GODFATHER_H
#define GODFATHER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>


class Godfather: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Godfather(QGraphicsItem *parent = 0);
//    void timerEvent(QTimerEvent *);
//        void paintEvent(QPaintEvent *);
//    void paintEvent(QPaintEvent *);
//    double timerId;
//    double position; // vi tri hien thi cua so
//    double positionH;
//    QPixmap frame1("D://CTU//4_HK1//DH_MayTinh//data//bullet enemy game character//PNG//frame1.png");
//    QPixmap frame2("D://CTU//4_HK1//DH_MayTinh//data//bullet enemy game character//PNG//frame2.png");
//    double x;
//    double flag;
    int hp;
    int hinh; //vi tri cua anh nho
    int flag;
//    QPixmap spitesheet;

//    void drawMegaman(QPainter& painter);


    int getHp();
    void decreaseHp();
signals:
    
public slots:
        void draw();
        void move();
        void attack();
};

#endif // GODFATHER_H
