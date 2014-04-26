#include "Heap.h"
#include <QDebug>




int main()
{
    int array[] ={0};
    Heap <int> teste(array,1,7);

    teste.insert (1);
    teste.insert (2);
    teste.insert (3);
    teste.insert (4);
    teste.insert (5);


    for (int i= 1; i<=5;i++)
    {
         qDebug() << array[i] << "\n";

    }



}
