#include "MinHeap.hpp"

// Class Constructor
template <typename Type>
MinHeap<Type>::MinHeap(int _heapCapacity) {
    this->heapSize = 0;
    this->heapCapacity = _heapCapacity;

    this->heap = new Type[this->heapCapacity];
}

// Class Destructor
template <typename Type>
MinHeap<Type>::~MinHeap() {
    delete[] this->heap;
}

template <typename Type>
int MinHeap<Type>::father(int i) {
    return (i - 1) / 2;
}

template <typename Type>
int MinHeap<Type>::left(int i) {
    return (2 * i) + 1;
}

template <typename Type>
int MinHeap<Type>::right(int i) {
    return (2 * i ) + 2;
}

template <typename Type>
void MinHeap<Type>::swap(Type *x, Type *y) {
    Type temp = *x;
    *x = *y;
    *y = temp;
}

template <typename Type>
void MinHeap<Type>::insert(Type element) {
    // Insere o elemento no fim da heap
    this->heapSize++;
    int i = this->heapSize -1;
    this->heap[i] = element;
    
    // Verifica se a min heap foi violada e a restabelesce
    while(i != 0 && this->heap[father(i)] > this->heap[i]) {
        swap(&this->heap[i], &heap[father(i)]);
        i = father(i);
    }
}

template <typename Type>
ostream& operator << (ostream &os, MinHeap<Type> &minHeap) {
    cout << "[ ";
    for(int i = 0; i < minHeap.heapSize; i++) {
        cout << minHeap.heap[i] << " ";
    }
    cout << "]\n";
}
