#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream> 
#include <string>
#include <cstring> // memcpy

using namespace std;

// Estrutura para representar uma aresta ponderada
struct Edge {
    int src, dst, weight;
};
 
// Classe para abstrair um grafo
class Graph {
    private:
        // Arquivo que armazena o grafo
        ifstream file;
        // Número de vertices e arestas
        int nVertices, nEdges;
        
    public:
        // Arestas do grafo 
        Edge *edges;

        Graph(string filePath);
        Graph(const Graph &graph);
        Graph(int _nVertices, Edge *edgeList, int _nEdges);
        ~Graph();

        int getVertices();
        int getEdges();

        friend ostream& operator << (ostream &os, Graph &graph);  
};

// Estrutura para representar um subconjunto
struct Subset {
    int parent, rank;
};

// Funções auxiliares para o algoritmo de Kruskal

// Encontra o conjunto de um elemento i
int find(Subset *subsets, int i);

// Realiza a união de dois conjuntos
void doUnion(Subset *subsets, int x, int y);

int comparison(const void *a, const void *b);

// Algoritmo para ordenação das arestas
void mergeSort(Edge *arr, int first, int last, int (*compare)(Edge*, Edge*));
void merge(Edge *arr, int first, int middle, int last, int (*compare)(Edge*, Edge*));

// ALgoritmo de kruskal
Graph kruskal(Graph *graph); 

#endif // GRAPH_H