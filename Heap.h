#ifndef HEAP_H
#define HEAP_H
#include "HeapADT.h"
template <typename E, typename comp >

class Heap: public HeapADT <E>{
public:
    E* Heap;
    int maxsize;
    int n;
    E heap (E* h,int num, int max )
    {
        Heap =h;
        n=num;
        max=maxsize;

    }
    void heapfy(int posicao)
    {
        while(!isLeaf (posicao))
        {
            int direita = righ (posicao);
            int esquerda =left (posicao);


            
        }

    }

    int size () const
    {
        return n;
    }
    bool isLeaf(int posicao)const
    {
        return ((posicao >=this->n/2)&& (posicao <n));
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


};




#endif // HEAP_H
