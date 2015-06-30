#include "Sort.h"
#include "ui_Sort.h"

Sort::Sort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sort)
{
    size=30000;
    numeros = (int*)malloc(sizeof(int)*size);
    nHeap=(int*)malloc(sizeof(int)*size);
    nBin=(int*)malloc(sizeof(int)*size);
    nMerge=(int*)malloc(sizeof(int)*size);
    nQuick=(int*)malloc(sizeof(int)*size);
    nBurbuja=(int*)malloc(sizeof(int)*size);
    ui->setupUi(this);
    inicializar();
    llenar();
}

Sort::~Sort()
{
    delete ui;
}

//INICIALIZACION ARREGLO
void Sort::inicializar(){
    srand(time(0));
    for(int i=0;i<size;i++)
    numeros[i]=1+(rand()%100);
}

void Sort::llenar(){
    for(int i=0;i<size;i++)
      ui->listWidget->addItem(QString::number(numeros[i]));
    for(int i=1;i<=size;i++){
        nHeap[i]=numeros[i-1];
        nBin[i-1]=numeros[i-1];
        nMerge[i-1]=numeros[i-1];
        nQuick[i-1]=numeros[i-1];
        nBurbuja[i-1]=numeros[i-1];
    }
}

//BINSORT O BUCKETSORT
void Sort::bucket_sort (int *arr, int n){
    //Here range is [1,100]
     int m = n;

     //Create m empty buckets
     int buckets[m];

     //Intialize all buckets to 0
     for (int i = 0; i < m; ++i)
       buckets[i] = 0;

     //Increment the number of times each element is present in the input
     //array. Insert them in the buckets
     for (int i = 0; i < n; ++i)
       ++buckets[arr[i]];

     //Sort using insertion sort and concatenate
     for (int i = 0, j = 0; j < m; ++j)
       for (int k = buckets[j]; k > 0; --k)
         arr[i++] = j;
}

void Sort::ordenarBucketSort(int *input_ar, int n){
    bucket_sort (input_ar, n);
    int t=tBinsort.elapsed();
      for (int i = 0; i < n; ++i)
          ui->listWidget_2->addItem(QString::number(input_ar[i]));
      ui->label_7->setText(QString::number(t));
      cout<<"El Tiempo es: "<<t<<endl;
}

void Sort::on_pushButton_clicked()
{
    cout<<"Binsort pos 0: "<<nBin[0]<<endl;
    tBinsort.start();
    ordenarBucketSort(nBin,size);
}

//MERGESORT
void Sort::merge(int *arr, int l, int m, int r){
   int i, j, k;
   int n1 = m - l + 1;
   int n2 =  r - m;

   /* create temp arrays */
   int L[n1], R[n2];

   /* Copy data to temp arrays L[] and R[] */
   for(i = 0; i < n1; i++)
       L[i] = arr[l + i];
   for(j = 0; j < n2; j++)
       R[j] = arr[m + 1+ j];

   /* Merge the temp arrays back into arr[l..r]*/
   i = 0;
   j = 0;
   k = l;
   while (i < n1 && j < n2)
   {
       if (L[i] <= R[j])
       {
           arr[k] = L[i];
           i++;
       }
       else
       {
           arr[k] = R[j];
           j++;
       }
       k++;
   }

   /* Copy the remaining elements of L[], if there are any */
   while (i < n1)
   {
       arr[k] = L[i];
       i++;
       k++;
   }

   /* Copy the remaining elements of R[], if there are any */
   while (j < n2)
   {
       arr[k] = R[j];
       j++;
       k++;
   }
}

void Sort::mergeSort(int *arr, int l, int r){
    if (l < r){
       int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
       mergeSort(arr, l, m);
       mergeSort(arr, m+1, r);
       merge(arr, l, m, r);
   }
}

void Sort::ordenarMergeSort(int *arr,int n){
     mergeSort(arr, 0, n - 1);
     int t=tMergesort.elapsed();
     for (int i = 0; i < n; ++i)
         ui->listWidget_3->addItem(QString::number(arr[i]));
     cout<<"Merge: "<<t<<endl;
     ui->label_8->setText(QString::number(t));
}

void Sort::on_pushButton_2_clicked()
{
    cout<<"Merge pos 0: "<<nMerge[0]<<endl;
    tMergesort.start();
    ordenarMergeSort(nMerge,size);
}

//QUICKSORT
void Sort::swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Sort::quickSort(int* array, int inicio, int final){
    int pivote = array[inicio];
    int split;

    if(final > inicio)
    {
        split = splitArray(array, pivote, inicio, final);

        array[split] = pivote;
        quickSort(array, inicio, split-1);
        quickSort(array, split+1, final);
    }
}

int Sort::splitArray(int* array, int pivote, int inicio, int final){
    int izquierdo = inicio;
    int derecho = final;

    while(izquierdo < derecho)
    {
        while(pivote < array[derecho] && derecho > izquierdo)
            derecho--;

        swap(array[izquierdo], array[derecho]);

        while(pivote >= array[izquierdo] && izquierdo < derecho)
            izquierdo++;

        swap(array[derecho], array[izquierdo]);
    }

    return izquierdo;
}


void Sort::ordenarQuickSort(int *arr,int n){
    quickSort(arr, 0, n-1);
    int t=tQuicksort.elapsed();
    for (int i = 0; i < n; ++i)
        ui->listWidget_4->addItem(QString::number(arr[i]));
    cout<<"Quick: "<<t<<endl;
    ui->label_9->setText(QString::number(t));
}

void Sort::on_pushButton_3_clicked()
{
    cout<<"Quick pos 0: "<<nQuick[0]<<endl;
    tQuicksort.start();
    ordenarQuickSort(nQuick,size);
}

//HEAPSORT
void Sort::heapSort(int *A, int n){
    int j,item,temp,i,k;

    for(k=n;k>0;k--)
    {
        for(i=1;i<=k;i++)
        {
            item=A[i];
            j=i/2;
            while(j>0 && A[j]<item)
            {
                A[i]=A[j];
                i=j;
                j=j/2;
            }
            A[i]=item;
        }
        temp=A[1];
        A[1]=A[k];
        A[k]=temp;
    }
}

void Sort::on_pushButton_4_clicked()
{
    cout<<"Heap pos 0: "<<nHeap[1]<<endl;
    tHeapsort.start();
    heapSort(nHeap,size);
    int t=tHeapsort.elapsed();
      for (int i = 1; i <= size; ++i)
          ui->listWidget_5->addItem(QString::number(nHeap[i]));
      ui->label_10->setText(QString::number(t));
      cout<<"Heap es: "<<t<<endl;
}

//BURBUJA
void Sort::burbuja(int *num,int TAM){
    int temp=0; 			 //Variable temporal
    int i,j;
    for (i=1;i<TAM;i++)
    {
        for (j=0;j<TAM-1;j++)
        {
            if (num[j] > num[j+1])	 //condicion
            {
                temp = num[j];	 //temp guarda momentaneamente el valor de lista[j]
                num[j]=num[j+1];  //Asigno al la posicion lista[j], lo que hay en lista[j+1]
                num[j+1]=temp;	//obtendra un nuevo valor por parte de temp.
            }
        }

    }
}

void Sort::on_pushButton_5_clicked()
{
    cout<<"Burbuja pos 0: "<<nBurbuja[0]<<endl;
    tBurbuja.start();
    burbuja(nBurbuja,size);
    int t=tBurbuja.elapsed();
      for (int i = 0; i < size; ++i)
          ui->listWidget_6->addItem(QString::number(nBurbuja[i]));
      ui->label_11->setText(QString::number(t));
      cout<<"Burbu es: "<<t<<endl;
}
