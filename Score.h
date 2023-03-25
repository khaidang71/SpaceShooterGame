#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void increase();
    int getScore();
    int getHpBoss();
    void decreaseHpBoss();
    void decreaseHpEnemy2();
    int getHpEnemy2();
    void fullHpEnemy2();
private:
    int score;
    int hpBoss;
    int hpEnemy2;
};

#endif // SCORE_H
