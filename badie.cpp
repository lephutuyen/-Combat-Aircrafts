#include "badie.h"
#include <QTimer>
#include <QList>
#include <stdlib.h>
#include "ship.h"
#include "game.h"
#include "laser.h"
#include <Qstring>
#include <typeinfo>

extern Game * game;

Badie::Badie(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    //Tạo ra 2 badie, chọn ngẫu nhiên 1 trong 2 để xuất hiện vào khung hình
    int random = (rand() % 1450);
    int rngSprite = rand() % 2;
    QString tmp;

    if(rngSprite == 0)
    {
        tmp = ":/images/covid.png";
        setScale(0.3);
    }
    else
    {
        tmp = ":/images/covid1.png";
        setScale(0.2);
    }

    setPos(random,-100);
    setPixmap(QPixmap(tmp));

    //connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Badie::move()
{
    setPos(x(),y()+10);

        //Tích hợp danh sách các đối tượng va chạm
        QList <QGraphicsItem *> collidingItemsList = collidingItems();

        //Kiểm tra va chạm với Ship
        for(int i = 0; i < collidingItemsList.size(); i++)
        {
            //Phát âm khi va chạm, nhưng vì nhạc nền ồn quá nên tụi em ko đưa vào
            if((typeid(*collidingItemsList.at(i)) == typeid(Laser)) || (typeid(*collidingItemsList.at(i)) == typeid(Ship)))
            {
                if(explosion->state() == QMediaPlayer::PlayingState)
                {
                    explosion->setPosition(0);
                }
                else if(explosion->state() == QMediaPlayer::StoppedState)
                {
                    explosion->play();
                }
            }

            if(typeid(*collidingItemsList.at(i)) == typeid(Ship))
            {
                //Giảm máu
                game->health->decrease();

                //Xóa khỏi màn hình badie sau khi va chạm
                scene()->removeItem(this);

                //Xóa khỏi bộ nhớ
                delete this;
                return;
            }
        }

    //Khi nó di chuyển khỏi khung hình thì xóa
    if(pos().y() > 950)
    {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
