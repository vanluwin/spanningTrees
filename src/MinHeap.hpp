#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <iomanip>
using namespace std;

template <typename Type>
class MinHeap {
    private:
        // Array que armazena a heap
        Type *heap;
        // Tamanho autal da heap
        int heapSize;
        // Tamanho maximo da heap
        int heapCapacity;
        // Troca dois elementos de posição
        void swap(Type *x, Type *y);

    public:
        MinHeap(int _heapSize);
        ~MinHeap();

        // Indice do pai de i
        int father(int i);
        // Indice do filho esquerdo de i
        int left(int i);
        // Indice do filho direito de i
        int right(int i);
        // Insere um elemento na heap
        void insert(Type element);
        // Sobrecarga do operador << 
        template <typename T>
        friend ostream& operator << (ostream &os, MinHeap<T> &heap);  
};

#endif // MINHEAP_H