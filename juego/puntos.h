#ifndef PUNTO_H
#define PUNTO_H
#include <QGraphicsItem>
#include <QPainter>

class puntos: public QGraphicsItem
{
    int posx, posy, radio;
public:
    puntos();
    puntos(int x, int y, int r);
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PUNTO_H
