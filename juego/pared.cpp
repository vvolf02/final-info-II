#include "pared.h"

pared::pared()
{

}

pared::pared(int x, int y, int w, int h, int i)
    : QGraphicsRectItem(x, y, w, h), id(i)
{
    this->posx=x;
    this->posy=y;
    this->h=h;
    this->w=w;
    this->id=i;
    currentTexture=QPixmap(":/Imagen/muro.jpg");
    setBrush(QBrush(currentTexture));
}

QRectF pared::boundingRect() const
{
    return QRectF(posx,posy,w,h);
}

int pared::getId() const
{
    return id;
}

void pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(), currentTexture, currentTexture.rect());
}

void pared::setTexture(const QString& texturePath)
{
    currentTexture=QPixmap(texturePath);
    setBrush(QBrush(currentTexture));
    update();
}
