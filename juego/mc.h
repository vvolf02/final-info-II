#ifndef MC_H
#define MC_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class mc: public QGraphicsItem
{
    int posx, posy, radio, vel=3;
public:
    mc();
    mc(int x, int y, int r);
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void MoverDer();
    void MoverIzq();
    void MoverArriba();
    void MoverAbajo();
    void respawn();

};

#endif // MC_H
