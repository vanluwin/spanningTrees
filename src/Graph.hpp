#ifndef GRAPH_H
#define GRAPH_H

// Implementação de grafos utilizando matriz de adjacência 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream> 
#include <string>
using namespace std;

class Graph {
    private:
        // Arquivo que armazena o grafo
        ifstream file;
        // Quantidade de vértices
        int vertex;
        // Matrix de adjacência do grafo
        int **matrix;    
    public:
        Graph(string filePath);
        ~Graph();

        friend ostream& operator << (ostream &os, Graph &graph);  
};

#endif // GRAPH_H