#include "score.h"
#include <QFont>
#include <QDebug>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //Set score = 0
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    //Tăng điểm
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}
