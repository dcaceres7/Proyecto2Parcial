#ifndef GRAFO_H
#define GRAFO_H
#include <QWidget>
#include <vector>
#include <iostream>
#include <QGraphicsScene>
#include "Vertice.h"
#include "arista.h"
using namespace std;
namespace Ui {
class Grafo;
}

class Grafo : public QWidget
{
    Q_OBJECT

public:
    bool dirigido;
    vector<Vertice*>* vertices;
    vector<Arista*>* aristas;
    int adyacentes[30][30];
    int camino[30][30];
    int VerticesIntermedias[30][30];
    void inicializar();
    Vertice* obtenerVertice(QString nom);
    void crearArista(QString origen, QString destino, int valor,Arista *ar,bool d);
    int pos(QString nombre);
    QGraphicsScene *qgraphic;
    QString floyd();
    QString Djikstra(int origen);
    explicit Grafo(QWidget *parent = 0);
    ~Grafo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Grafo *ui;
};

#endif // GRAFO_H
