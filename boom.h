#ifndef BOOM_H
#define BOOM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QObject>

class Boom : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Boom(QGraphicsItem *parent = 0);
    int hinh;
    
signals:
    
public slots:
    void draw();
//    void move();
private:
    QMediaPlayer * boomsound;
};

#endif // BOOM_H
