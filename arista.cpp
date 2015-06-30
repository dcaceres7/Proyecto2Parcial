#include "arista.h"
#include <QPainter>

Arista::Arista(Vertice* origen, Vertice* destino, int v)
{
    this->origen = origen;
    this->destino = destino;
    valor = v;
}

QRectF Arista::boundingRect() const
{
    return QRectF(origen->pos(),destino->pos());
}

void Arista::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawLine(origen->x()+(origen->size/2),origen->y()+(origen->size/2) ,destino->x()+(destino->size/2), destino->y()+(destino->size/2));
    painter->drawText(((origen->x()+destino->x())/2)+(origen->size/2),((origen->y()+destino->y())/2)+(origen->size/2),QString::number(valor));
}
