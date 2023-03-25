#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QObject>

class Explosion : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Explosion(QGraphicsItem *parent = 0);
    int hinh;
signals:
    
public slots:
    void draw();
private:
    QMediaPlayer * boomsound;
};

#endif // EXPLOSION_H
