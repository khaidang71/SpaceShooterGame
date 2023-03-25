#ifndef STAR_H
#define STAR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Star :public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Star(QGraphicsItem * parent=0);
signals:
    
public slots:
    void move();
};

#endif // STAR_H
