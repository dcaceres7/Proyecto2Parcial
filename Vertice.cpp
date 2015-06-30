#include "Vertice.h"
//#include "nuevovertice.h"

Vertice::Vertice(QString nom)
{
    nombre = nom;
    setFlag(ItemIsMovable);
    size = 80;
    color = 3;
}

QRectF Vertice::boundingRect() const
{
    return QRectF(0,0,size,size);
}

void Vertice::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::white);

    switch (color) {
    case 1:
        brush.setColor(Qt::red);
        break;
    case 2:
        brush.setColor(Qt::blue);
        break;
    case 3:
        brush.setColor(Qt::cyan);
        break;
    case 4:
        brush.setColor(Qt::green);
        break;
    case 5:
        brush.setColor(Qt::yellow);
        break;
    default:
        brush.setColor(Qt::white);
        break;
    }

    QPainterPath paintpath;
    paintpath.addEllipse(rec);
    painter->fillPath(paintpath,brush);
    painter->drawEllipse(rec);
    painter->drawText(boundingRect(),Qt::AlignCenter,nombre);
}

void Vertice::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
}

void Vertice::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
}

void Vertice::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
}
