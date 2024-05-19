#ifndef PARED_H
#define PARED_H
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPixmap>
#include <QPainter>

class pared: public QGraphicsRectItem
{
    int posx, posy, w, h, id;
    QPixmap currentTexture;
public:
    pared();
    pared(int posx, int posy, int w, int h, int id=0);
    int getId() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void setTexture(const QString& texturePath);
};

#endif // PARED_H
