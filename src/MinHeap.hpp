#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <iomanip> 
using namespace std;

template <typename Type>
class MinHeap {
    private:
        // Tamanho autal da heap
        int heapSize;
        // Tamanho maximo da heap
        int heapCapacity;
        // Troca dois elementos de posição
        void swap(Type *x, Type *y);

    public:
        // Array que armazena a heap
        Type *heap;
        
        MinHeap(int _heapSize);
        ~MinHeap();

        // Indice do pai de i
        int father(int i);
        // Indice do filho esquerdo de i
        int left(int i);
        // Indice do filho direito de i
        int right(int i);
        // Insere um elemento na heap
        void push(Type element, int (*compare)(Type*, Type*));
        // Retorna o elemento da raiz da heap
        Type front();
        // Remove e retorna a raiz da heap
        Type pop();
        // Restora a heap
        void heapify(int i);
        // Verifica se a heap está vazia
        bool empty();
        // Reorna o tamanho da heap
        int getSize();
        // Sobrecarga do operador << 
        template <typename T>
        friend ostream& operator << (ostream &os, MinHeap<T> &heap);  
};

#endif // MINHEAP_H