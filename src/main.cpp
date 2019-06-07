#include "MinHeap.hpp"
#include "MinHeap.cpp"
#include "Graph.hpp"

int main(int argc, char **argv) {
    int arr[] = { 35, 33, 42, 10, 14, 19, 27, 44, 26, 31 };

    MinHeap<int> myHeap(10);

    for(int elem : arr) {
        myHeap.insert(elem);
    }

    //cout << "\nMy Heap: " << myHeap << "\n\n";

    Graph myGraph("../completo/7completo.in");

    cout << endl << myGraph << endl;

    return 0;
}