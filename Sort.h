#ifndef SORT_H
#define SORT_H
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <QWidget>
#include <QTime>
using namespace std;

namespace Ui {
class Sort;
}

class Sort : public QWidget
{
    Q_OBJECT

public:
    QTime tBinsort,tMergesort,tQuicksort,tHeapsort,tBurbuja;
    int size;
    int *numeros,*nBin,*nMerge,*nQuick,*nHeap,*nBurbuja;
    void inicializar();
    void llenar();
    //BINSORT
    void bucket_sort (int *arr, int n);
    void ordenarBucketSort(int *arr,int n);
    //MERGESORT
    void merge(int *arr, int l, int m, int r);
    void mergeSort(int *arr, int l, int r);
    void ordenarMergeSort(int *arr,int n);
    //QUICKSORT
    void quickSort(int* array, int inicio, int final);
    int splitArray(int* array, int pivote, int inicio, int final);
    void swap(int &a, int &b);
    void ordenarQuickSort(int *arr,int n);
    //HEAPSORT
    void heapSort(int *A,int n);
    explicit Sort(QWidget *parent = 0);
    //BURBUJA
    void burbuja(int *num,int TAM);
    ~Sort();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Sort *ui;
};

#endif // SORT_H
