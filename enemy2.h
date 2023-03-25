#ifndef ENEMY2_H
#define ENEMY2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy2 :  public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy2(QGraphicsItem * parent=0);
    
signals:
    
public slots:
     void move();
     void attack();
};

#endif // ENEMY2_H
