#ifndef HEAP_H
#define HEAP_H
#include "HeapADT.h"

template <typename E>

class Heap: public HeapADT <E>{
private:
    E* heap;
    int maxSize;
    int n;
    void heapfy(int posicao)
    {
        while(!isLeaf (posicao))
        {
            int direita = righ (posicao);
            int esquerda =left (posicao);
            if ((direita<n) && prior(heap[direita],heap[esquerda]))
            {
                esquerda=direita;
            }
            if (prior(heap[posicao], heap[esquerda]))
            {
                return;
            }
            swap(heap, posicao, esquerda);
            posicao=esquerda;
        }

    }

public:

    Heap (E* h,int num, int max )
    {

        heap=h ;
        n=num;
        maxSize=max;
        buildMaxHeap ();

    }
    template <typename T>
    void swap(T array[],int i,int j){
        T temp = array[i];
        array[i]=array[j];
        array[j]=temp;
    }
    void buildMaxHeap()
    {
        int i;
        for(i=(n/2)-1; i>=0;i--)
        {
            heapfy(i);
        }
    }

    bool prior(int a, int  b)
    {
        return (a>b);
    }
    int size () const
    {
        return n;
    }
    bool isLeaf(int posicao)const
    {
        return ((posicao >=n/2)&& (posicao <n));
    }
    int left(int posicao) const
    {
        int left;
        left= ((posicao *2) +1);
        return left;
    }
    int righ(int posicao) const
    {
        int righ;
        righ = ((posicao *2) +2);
        return righ;
    }
    int parent(int posicao) const
    {
        int pai;
        pai= ((posicao-1)/2);
        return pai;
    }
    void insert(const E& it)
    {
        int aux;
        aux=n++;
        heap[aux]=it;
        while((aux!=0)&&(prior (heap[aux], heap[parent(aux)])))
        {
            swap(heap, aux  ,parent(aux));
            aux = parent(aux);

        }
    }
    E removefirst()
    {
        swap(heap,0,(n--));
        if(n!=0)
        {
            heapfy (0);
        }
        return heap[n];
    }
    E remove(int posicao)
    {
        if(posicao == (n--))
        {
            n--;

        }
        else
        {
            swap(heap,posicao, (n--));
            while(posicao!=0 && prior(heap[posicao],heap[parent(posicao)]))
            {
                swap(heap, posicao,parent (posicao));
                posicao=parent(posicao);
            }
            if(n!=0)
            {
                heapfy(posicao);
            }
        }
        return heap[n];
    }







};




#endif // HEAP_H
