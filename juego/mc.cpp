#include "mc.h"

mc::mc()
{

}

mc::mc(int x, int y, int r)
{
    posx=x;
    posy=y;
    radio=r;
    setPos(posx,posy);
}

QRectF mc::boundingRect() const
{
    return QRectF(posx,posy,2*radio, 2*radio);
}

void mc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
    //QPixmap pixmap(":/Imagen/pacman.png");
    //painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void mc::MoverDer()
{
    posx+=vel;
    setPos(posx,posy);
}

void mc::MoverIzq()
{
    posx-=vel;
    setPos(posx,posy);
}

void mc::MoverArriba()
{
    posy-=vel;
    setPos(posx,posy);
}

void mc::MoverAbajo()
{
    posy+=vel;
    setPos(posx,posy);
}

void mc::respawn()
{
    posx=13;
    posy=175;
}
