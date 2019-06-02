output: main.o MinHeap.o
	g++ -std=c++11 main.o MinHeap.o -o output.out

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

MinHeap.o: MinHeap.hpp MinHeap.cpp
	g++ -std=c++11 -c MinHeap.cpp

clean:
	rm *.o output.out
