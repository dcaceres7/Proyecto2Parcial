#ifndef ARISTA_H
#define ARISTA_H

#include <sstream>
#include <QString>
#include "Vertice.h"
class Arista : public QGraphicsItem
{
public:
    Vertice* origen;
    Vertice* destino;
    int valor;
    Arista(Vertice* origen, Vertice* destino, int valor);

    QString getPeso();



    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ARISTA_H
