#include "ship.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "laser.h"
#include "badie.h"
#include <stdlib.h>
#include <QThread>

Ship::Ship(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    //Tạo hình cho Player
    setPixmap(QPixmap(":/images/player0909.png"));
    setScale(2.5);
    shipsounds = new QMediaPlayer();
    //Nhạc cho cái phi thuyền nhưng ồn quá tụi em đã bỏ ra
    shipsounds->setMedia(QUrl(":/sound/Laser1.mp3"));
}

void Ship::keyPressEvent(QKeyEvent *event)
{
    //Bắt sự kiện từ bàn phím để di chuyển
    if (event->key() == Qt::Key_Left)
    {
        if(pos().x() > 0)
        {
            setPos(x()-20,y());
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if(pos().x() < 1450)
        {
            setPos(x()+20, y());
        }
    }
    else if (event->key() == Qt::Key_Up)
    {
        if(pos().y() > 0)
        {
            setPos(x(),y()-20);
        }
    }
    else if (event->key() == Qt::Key_Down)
    {
        if(pos().y() < 820)
        {
            setPos(x(),y()+20);
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
       //Set điểm bắn ra của viên đạn
       int posrng = rand() % 2;

       Laser * laser = new Laser();
       if(posrng == 1)
       {
           //Lượt đạn bên phải

            laser->setPos(this->x() + 130,this->y());
       }
       else
       {
           //Lượt đạn bên trái
           laser->setPos(this->x() + 10,this->y());
       }
       scene()->addItem(laser);

       //
       if(shipsounds->state() == QMediaPlayer::PlayingState)
       {
           shipsounds->setPosition(0);
       }
       else if(shipsounds->state() == QMediaPlayer::StoppedState)
       {
           shipsounds->play();
       }
    }
}

void Ship::spawn()
{
    //Khởi tạo Enemy
    Badie * enemy = new Badie();
    scene()->addItem(enemy);

}
