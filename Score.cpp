#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 0;
    hpBoss = 20;
    hpEnemy2 = 2;
    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int Score::getScore(){
    return score;
}
void Score::decreaseHpBoss(){
    hpBoss--;

}
void Score::decreaseHpEnemy2(){
    hpEnemy2--;

}
int Score::getHpBoss(){
    int a = hpBoss;
    return a;
}
void Score::fullHpEnemy2(){
    hpEnemy2 =2;
}

int Score::getHpEnemy2(){
    int a = hpEnemy2;
    return a;
}
