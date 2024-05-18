#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class enemy: public QGraphicsItem
{
    int posx, posy, radio, vel=3;
public:
    enemy();
    enemy(int x, int y, int r);
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void movAzar();

private:
    QColor color;
};

#endif // ENEMY_H
