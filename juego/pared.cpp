#include "pared.h"

pared::pared()
{

}

pared::pared(int x, int y, int w, int h)
{
    this->posx=x;
    this->posy=y;
    this->h=h;
    this->w=w;
}

QRectF pared::boundingRect() const
{
    return QRectF(posx,posy,w,h);
}

void pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/Imagen/muro.jpg");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
