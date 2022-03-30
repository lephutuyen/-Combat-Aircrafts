#include <Qtimer>
#include "game.h"
#include "badie.h"
#include <QMediaPlayer>
#include <QImage>
#include "ui.h"

Game::Game(QWidget *parent)
{

    //Khởi tạo khung hình
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1600,1000);
    setBackgroundBrush(QBrush(QImage(":/images/bgingame.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1600,1000);

    //Khởi tạo Player
    myShip = new Ship();
    myShip->setPos(800,810);
    myShip->setFlag(QGraphicsItem::ItemIsFocusable);
    myShip->setFocus();
    scene->addItem(myShip);

    //
    button = new UI();
    button->setPos(x() +10,10);
    scene->addItem(button);

    //hiển thị score và health
    score = new Score();
    score->setPos(x() + 1400,y());
    scene->addItem(score);

    health = new Healthbar();
    health->setPos(x() + 1200,y());
    scene->addItem(health);

    //Tạo mới mấy con covid
    QTimer * myTimer = new QTimer();
    QObject::connect(myTimer, SIGNAL(timeout()),myShip,SLOT(spawn()));
    myTimer->start(3000);

    //Nhạc nền
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/sound.mp3"));
    music->play();

    show();
}
