#ifndef MALPHITE_H
#define MALPHITE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Malphite: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Malphite(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // MALPHITE_H
