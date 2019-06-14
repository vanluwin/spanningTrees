all: minimumSpanningTree spanningTrees

minimumSpanningTree: minimumSpanningTree.cpp Graph.o MinHeap.o
	g++ -std=c++11 MinHeap.o Graph.o minimumSpanningTree.cpp -o minimumSpanningTree.out

spanningTrees: spanningTrees.cpp Graph.o MinHeap.o
	g++ -std=c++11 MinHeap.o Graph.o spanningTrees.cpp -o spanningTrees.out

MinHeap.o: MinHeap.hpp MinHeap.cpp
	g++ -std=c++11 -c MinHeap.cpp

Graph.o: Graph.hpp Graph.cpp
	g++ -std=c++11 -c Graph.cpp

clean:
	rm *.o output.out
