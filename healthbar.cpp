#include "healthbar.h"
#include <QFont>
#include <QDebug>
#include <QApplication>

Healthbar::Healthbar(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //Set máu ban đầu = 5
    health = 5;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Healthbar::decrease()
{
    //Trừ máu khi va chạm
    health--;

    //Khi máu về 0 thì quit game
    if(health == 0)
    {
         QApplication::quit();
    }
    setPlainText(QString("Health: ") + QString::number(health));
}

int Healthbar::getHealthbar()
{
    return health;
}
