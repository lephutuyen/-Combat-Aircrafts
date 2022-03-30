#include "laser.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "badie.h"
#include "game.h"
#include <stdlib.h>
#include <QString>
#include <typeinfo>
extern Game * game; //external global veriable

Laser::Laser(QGraphicsItem * parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //Khởi tạo 4 đối tượng đạn, chọn ngẫu nhiên phát ra 1 loại đạn
    QString tmp;
    int rngSprite = rand() % 4;

    if(rngSprite == 0)
    {
        tmp = ":/images/laser1.png";
    }
    else if (rngSprite == 1)
    {
        tmp = ":/images/shot.png";
    }
    else if (rngSprite == 2)
    {
        tmp = ":/images/laser3.png";
    }
    else
    {
        tmp = ":/images/laser4.png";
    }



    setPixmap(QPixmap(tmp));

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(7);
}

void Laser::move()
{
    //Tích hợp danh sách va chạm với viên đạn
    QList <QGraphicsItem *> collidingItemsList = collidingItems();

    //Kiểm tra va chạm với Covid
    for(int i = 0; i < collidingItemsList.size(); i++)
    {
        if(typeid(*collidingItemsList.at(i)) == typeid(Badie))
        {
            //Nếu đạn va chạm với covid thì + 1 Score
            game->score->increase();

            //Xóa khỏi khung hình 2 đối tượng vừa va chạm
            scene()->removeItem(collidingItemsList.at(i));
            scene()->removeItem(this);

            //Xóa cả 2 khỏi bộ nhớ
            delete collidingItemsList.at(i);
            delete this;
            return;
        }
    }

    //Viên đạn di chuyển lên trên
    setPos(x(),y()-3);

    //Xóa viên đạn ra khỏi màn hình nếu đi ra hết khung hình
    if(pos().y() < -30)
    {
        scene()->removeItem(this);
        delete this;
    }
}
