#include "puntos.h"

puntos::puntos()
{

}

puntos::puntos(int x,int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
}

QRectF puntos::boundingRect() const
{
    return QRectF(posx,posy,2*radio, 2*radio);
}

void puntos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/Imagen/pergamino.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
