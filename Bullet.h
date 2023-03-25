#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <boom.h>
//class Bullet: public QObject,public QGraphicsRectItem{
//    Q_OBJECT
//public:
//    Bullet(QGraphicsItem * parent=0);
//public slots:
//    void move();
//};


class Bullet: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);
    Boom *boom;
public slots:
    void move();
};

#endif // BULLET_H
