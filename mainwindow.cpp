#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Grafo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Sort *sort=new Sort();
    sort->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    Grafo *grafo=new Grafo();
    grafo->show();
}
