#ifndef VERTICE_H
#define VERTICE_H
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

class Vertice : public QGraphicsItem
{
public:
    Vertice(QString nom);
    QString nombre;
    int size;
    int color;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

};

#endif // VERTICE_H
