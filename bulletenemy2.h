#ifndef BULLETENEMY2_H
#define BULLETENEMY2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class BulletEnemy2 :  public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BulletEnemy2(QGraphicsItem * parent=0);
    
signals:
    
public slots:
    void move();
};

#endif // BULLETENEMY2_H
