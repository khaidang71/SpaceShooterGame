#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <godfather.h>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    int b;
    int hinh;


public slots:
    void spawn();
    void spawn2();
    void spawnb();
    void spawnEnemy2();
    void draw();
    void spawnStar();
private:
    QMediaPlayer * bulletsound;
};

#endif // PLAYER_H
