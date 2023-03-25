#ifndef BULLETBOSS_H
#define BULLETBOSS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class BulletBoss: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BulletBoss(QGraphicsItem * parent=0);
    int hinh;
signals:
    
public slots:
    void move();
    void draw();
};

#endif // BULLETBOSS_H
