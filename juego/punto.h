#ifndef PUNTO_H
#define PUNTO_H
#include <QGraphicsItem>
#include <QPainter>

class punto: public QGraphicsItem
{
    int posx, posy, radio;
public:
    punto();
    punto(int x, int y, int r);
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PUNTO_H
