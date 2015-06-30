#include "Grafo.h"
#include "ui_Grafo.h"

Grafo::Grafo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Grafo)
{
    dirigido=false;
    ui->setupUi(this);
    vertices=new vector<Vertice*>();
    aristas=new vector<Arista*>();
    qgraphic=new QGraphicsScene(this);
    ui->graphicsView->setScene(qgraphic);
    inicializar();
}

void Grafo::inicializar(){
    for(int i=0; i<30;i++)
    {
        for(int j=0; j<30; j++)
        {
            adyacentes[i][j] = 100000;
        }
    }
}

Grafo::~Grafo()
{
    delete ui;
}

int Grafo::pos(QString nombre){
    for(int i=0; i<vertices->size(); i++)
    {
        if(vertices->at(i)->nombre == nombre)
            return i;
    }
    return -1;
}

Vertice* Grafo::obtenerVertice(QString nom)
{
    int i;
    for(i = 0; i<vertices->size(); i++)
    {
        if(vertices->at(i)->nombre == nom)
            break;
    }
    return vertices->at(i);
}

void Grafo::crearArista(QString origen, QString destino, int valor,Arista *ar,bool d){
    int orig = pos(origen);
    int dest = pos(destino);
    if(dest != -1 && orig != -1)
    {
        adyacentes[orig][dest] = valor;
        if(d==false)
          adyacentes[dest][orig] = valor;
    }
    aristas->push_back(ar);
}

QString Grafo::floyd()
{
    QString  result;
    for(int i=0; i<vertices->size();i++)
        for(int j=0; j<vertices->size();j++)
        {
            camino[i][j] = adyacentes[i][j];
            VerticesIntermedias[i][j] = -1;
        }

    for(int pivote=0;pivote<vertices->size();pivote++)
    {
        for(int origen=0;origen<vertices->size();origen++)
        {
            for(int destino=0;destino<vertices->size();destino++)
            {
                int OrigenDestino = camino[origen][destino];
                int OrigenPivote = camino[origen][pivote];
                int PivoteDestino = camino[pivote][destino];
                if(OrigenDestino > OrigenPivote+PivoteDestino)
                {
                    camino[origen][destino] = OrigenPivote + PivoteDestino;
                    VerticesIntermedias[origen][destino] = pivote;
                }
            }
        }
    }

    for(int i=0; i<vertices->size(); i++)
    {
        for(int j=0; j<vertices->size(); j++)
        {
            if(camino[i][j] == 100000)
                result = result + "0 ";
            else
                result = result + QString::number(camino[i][j]) + " ";
        }
        result = result + "\n";
    }
    return result;
}

QString Grafo::Djikstra(int origen)
    {
        QString result;
        int distance[5];
        bool visited[5];
        int min;
        int nextNode =0;

        for(int y = 0; y<vertices->size(); y++)
            distance[y] = adyacentes[origen][y];

        distance[origen] = 0;
        visited[origen] = 1;

        for(int i = 0; i<vertices->size(); i++)
        {
            min = 100000;
            for(int j = 0; j<vertices->size(); j++)
            {
                if(min > distance[j] && !visited[j])
                {
                    min = distance[j];
                    nextNode = j;
                }
            }

            visited[nextNode] = 1;

            for(int c = 0; c<vertices->size(); c++)
            {
                if(!visited[c])
                {
                    if(min + adyacentes[nextNode][c] <distance[c])
                    {
                        distance[c] = min + adyacentes[nextNode][c];
                    }
                }
            }
        }

        for(int i = 0; i<vertices->size();i++)
        {
            if(distance[i]==100000)
                result = result + "i" + "\n";
            else
                result = result + QString::number(distance[i]) + "\n";
        }
        return result;
    }

void Grafo::on_pushButton_clicked()
{
    Vertice *v=new Vertice(ui->lineEdit->text());
    qgraphic->addItem(v);
    vertices->push_back(v);
    ui->comboBox->addItem(v->nombre);
    ui->comboBox_2->addItem(v->nombre);
    ui->comboBox_3->addItem(v->nombre);
    ui->lineEdit->clear();
}

void Grafo::on_pushButton_2_clicked()
{
    dirigido=ui->checkBox->isChecked();

    int x=ui->comboBox->currentIndex();
    int y=ui->comboBox_2->currentIndex();
    QString tx=ui->comboBox->currentText();
    QString ty=ui->comboBox_2->currentText();

    Vertice *o=obtenerVertice(tx);
    Vertice *d=obtenerVertice(ty);
    QString val=ui->lineEdit_2->text();
    int i=val.toInt();

    if(tx!=ty){
    Arista *a=new Arista(o,d,i);
    crearArista(tx,ty,i,a,dirigido);
    qgraphic->addItem(a);
    }

    ui->lineEdit_2->clear();
}

void Grafo::on_pushButton_5_clicked()
{
    QString f=floyd();
    ui->listWidget->addItem(f);
}

void Grafo::on_pushButton_6_clicked()
{
    QString o=ui->lineEdit_3->text();
    int origen=o.toInt();
    QString d=Djikstra(origen);
    ui->listWidget_2->addItem(d);
}
