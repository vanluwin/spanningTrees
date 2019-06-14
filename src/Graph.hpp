#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream> 
#include <string>
#include <cstring> // memcpy
#include "MinHeap.hpp"
#include "MinHeap.cpp"

#include <list>

using namespace std;

/*
    Estrutura para representar uma aresta ponderada
    Flags:
        0: Aresta opcional
        1: Aresta obrigatoria
        2: Aresta proibida
*/
struct Edge {
    int src, dst, weight, flag;
};
 
// Classe para abstrair um grafo
class Graph {
    private:
        // Arquivo que armazena o grafo
        ifstream file;
        // Número de vertices e arestas
        int nVertices, nEdges;
        // Custo total do grafo
        int cost;
    public:
        // Arestas do grafo 
        Edge *edges;

        Graph();
        Graph(int _nVertices, int _nEdges);
        Graph(string filePath);
        Graph(const Graph &graph);
        Graph(int _nVertices, Edge *edgeList, int _nEdges, int _cost);
        ~Graph();

        int getVertices();
        int getEdges();
        int getCost();
        int getFlag(Edge edge);

        void setCost(int _cost);
        void setFlag(Edge edge, int flag);

        void depthFirstSearch(int v, bool *visited);
        bool isConnected();

        Graph operator = (const Graph &graph);

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

// Função de partição para o algoritmo de Sorensen e Janssens
void partition(Graph *p, Graph *spanningTree, MinHeap<Graph> *parts);

// Algoritmo de Sorensen e Janssens (AGs mostradas em stdout)
void spanningTrees(Graph *graph);

// Algoritmo de Sorensen e Janssens (AGs salvas no arquivo allSpanningTrees)
void spanningTreesToFile(Graph *graph);

#endif // GRAPH_H