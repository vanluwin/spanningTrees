output: main.o MinHeap.o Graph.o
	g++ -std=c++11 main.o MinHeap.o Graph.o -o output.out

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

MinHeap.o: MinHeap.hpp MinHeap.cpp
	g++ -std=c++11 -c MinHeap.cpp

Graph.o: Graph.hpp Graph.cpp
	g++ -std=c++11 -c Graph.cpp

clean:
	rm *.o output.out
