output: completeGraph.o gridGraph.o
	g++ -std=c++11 completeGraph.o -o completeGraph.out
	g++ -std=c++11 gridGraph.o -o gridGraph.out

completeGraph.o: completeGraph.cpp
	g++ -std=c++11 -c completeGraph.cpp

gridGraph.o: gridGraph.cpp
	g++ -std=c++11 -c gridGraph.cpp

clean:
	rm *.o *.out