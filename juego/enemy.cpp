#include "enemy.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QRandomGenerator>
#include <QStyleOption>
#include <QtMath>

using namespace std;
enemy::enemy()
{

}
enemy::enemy(int x, int y, int r)
{
    posx=x;
    posy=y;
    radio=r;
    setPos(posx,posy);
}

QRectF enemy::boundingRect() const
{
    return QRectF(posx,posy,2*radio, 2*radio);
}
void enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::red);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap(":/Imagen/pinkghost.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void enemy::movAzar()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 4);
    int numrandom = dis(gen);
    if(numrandom==1)
    {
        posx+=vel*2;
        setPos(posx,posy);
    }
    else if(numrandom==2)
    {
        posy+=vel*2;
        setPos(posx,posy);
    }
    else if(numrandom==3)
    {
        posx-=vel*2;
        setPos(posx,posy);
    }
    else if(numrandom==4)
    {
        posy-=vel*2;
        setPos(posx,posy);
    }
}
