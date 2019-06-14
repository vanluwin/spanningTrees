#include "MinHeap.hpp"

// Class Constructor
template <typename Type>
MinHeap<Type>::MinHeap(int _heapCapacity) {
    heapSize = 0;
    heapCapacity = _heapCapacity;

    heap = new Type[heapCapacity];
}

// Class Destructor
template <typename Type>
MinHeap<Type>::~MinHeap() {
    delete[] heap;
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
void MinHeap<Type>::push(Type element, int (*compare)(Type*, Type*)) {
    // Insere o elemento no fim da heap
    heapSize++;
    int i = heapSize -1;
    heap[i] = element;
    
    // Verifica se a min heap foi violada e a restabelesce
    while(i != 0 && compare(&heap[father(i)], &heap[i])) {
        swap(&heap[i], &heap[father(i)]);
        i = father(i);
    }
}

template <typename Type>
Type MinHeap<Type>::pop() {
    if (heapSize == 1) { 
        heapSize--; 
        return heap[0]; 
    } 

    // Guarda o menor o menor valor e restora a heap
    Type root = heap[0]; 
    heap[0] = heap[heapSize - 1]; 
    heapSize--; 
    heapify(0); 

    return root; 
}

template <typename Type>
void MinHeap<Type>::heapify(int i) { 
    int l = left(i); 
    int r = right(i); 

    int smallest = i; 
    if (l < heapSize && heap[l].getCost() < heap[i].getCost()) 
        smallest = l; 
    if (r < heapSize && heap[r].getCost() < heap[smallest].getCost()) 
        smallest = r; 
    if (smallest != i) { 
        swap(&heap[i], &heap[smallest]); 
        heapify(smallest); 
    } 
} 

template <typename Type>
bool MinHeap<Type>::empty() {
    return heapSize == 0 ? true : false;
}

template <typename Type>
int MinHeap<Type>::getSize() {
    return heapSize;
}

template <typename Type>
Type MinHeap<Type>::front() {
    return heap[0]; 
}

template <typename Type>
ostream& operator << (ostream &os, MinHeap<Type> &minHeap) {
    for(int i = 0; i < minHeap.heapSize; i++) {
        //cout << minHeap.heap[i].src << " -- " << 
        //    minHeap.heap[i].dst << " " << 
        //    minHeap.heap[i].weight 
        //<< endl;
        cout << minHeap.heap[i] << endl;
    }

    return os;
}
