#include "Graph.hpp"

// Extrai inteiros de uma string
void extractIntegers(string str, Edge &edge) { 
    stringstream ss;     
  
    ss << str; 
  
    string temp; 

    int found, i = 0, arr[3];
    
    while (!ss.eof()) { 
  
        ss >> temp; 
  
        if (stringstream(temp) >> found) {
            arr[i] = found;
            i++;
        }

        temp = ""; 
    } 

    edge = { arr[0], arr[1], arr[2] };

} 

// Função de comparação de pesos
int compareWeight(Edge *a, Edge *b) {
    return a->weight <= b->weight;
}

// Função de comparação de origens de arestas
int compareVertex(Edge *a, Edge *b) {
    if(a->src == b->src)
        return a->dst < b->dst;

    return a->src < b->src;
}

// Construtor usando um arquivo de instancia
Graph::Graph(string filePath) {
    file.open(filePath);

    string line;

    if (file.is_open()) {
        // Verifica se o grafo é grid ou completo
        if(filePath.find("completo") != std::string::npos) {
            // Lê a quantidade de vértices
            getline(file, line);
            nVertices = stoi(line);
            
            // Calcula a quantidade de vertices
            nEdges = (nVertices * (nVertices - 1)) / 2;

        } else {
            // Lê a quantidade de linhas do grafo
            getline(file, line);
            int rows = stoi(line);

            // Lê a quantidade de colunas do grafo
            getline(file, line);
            int cols = stoi(line);
            
            // Calcula o numero de vértices e arestas 
            nVertices = rows * cols;
            nEdges = (2 * rows * cols) - rows - cols;

        }

        // Aloca espaço para a lista de adjacência
        edges = new Edge[nEdges];

        if(edges == NULL) {
            delete[] edges;
            cout << "Erro ao alocar o vetor de arestas!\n";
            exit(0);
        }

        // Lê as arestas a serem inseridas no grafo
        int i = 0;
        while (getline(file, line)) {
            // Armazena os valores dos vertices e aresta lidos
            Edge edge;
            extractIntegers(line, edge);

            // Insire o que foi lido na lista de adjacência
            edges[i] = edge;
            i++;    
        }

        file.close();
 
    } else {
        cout << "Erro ao abrir o arquivo.\n"; 
        exit(0);
    }
}

// Construtor para a MST
Graph::Graph(int _nVertices, Edge *edgeList, int _nEdges) {
    nVertices = _nVertices;
    nEdges = _nEdges;

    // Aloca espaço para a lista de adjacência
    edges = new Edge[nEdges];
    
    // Copia a lista passada para o atribuito da classe
    memcpy(edges, edgeList, nEdges * sizeof(Edge));

    mergeSort(edges, 0, nEdges - 1, compareVertex);
}

// Construtor de cópia
Graph::Graph(const Graph &graph) {
    nVertices = graph.nVertices;
    nEdges = graph.nEdges;

    edges = new Edge[nEdges];

    memcpy(edges, graph.edges, nEdges * sizeof(Edge));
}

// Class Destructor
Graph::~Graph() {
    delete[] edges;
}

int Graph::getVertices() {
    return nVertices;
}

int Graph::getEdges() {
    return nEdges;
}

ostream& operator << (ostream &os, Graph &graph) {
    for(int i = 0; i < graph.nEdges; i++) {
        cout << 
            setw(2) << graph.edges[i].src << " --- " << 
            setw(2) << graph.edges[i].dst << " " << 
            setw(2) << graph.edges[i].weight 
        << endl;
    }

    return os;
}

int find(Subset *subsets, int i) {
    // Encontra uma raiz a a coloca como pai de i
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void doUnion(Subset *subsets, int x, int y) {
    int xRoot = find(subsets, x);
    int yRoot = find(subsets, y);

    // Coloca a árvore de menor rank sob
    // a raiz da árvore de maior rank
    if (subsets[xRoot].rank < subsets[yRoot].rank)
        subsets[xRoot].parent = yRoot;
    else if (subsets[xRoot].rank > subsets[yRoot].rank)
        subsets[yRoot].parent = xRoot;

    // Se os ranks são iguais, as raizes são unificadas 
    //e seu rank é incrementado
    else {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
}

void merge(Edge *arr, int first, int middle, int last, int (*compare)(Edge*, Edge*)) {
    int n1 = middle - first + 1;
    int n2 = last - middle;

    Edge leftHalf[n1], rightHalf[n2];
    for (int i = 0; i < n1; i++) leftHalf[i] = arr[first + i];
    for (int j = 0; j < n2; j++) rightHalf[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = first;
    while (i < n1 && j < n2) {
        if (compare(&leftHalf[i], &rightHalf[j])) {
            arr[k] = leftHalf[i];
            i++;
        } else {
            arr[k] = rightHalf[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = leftHalf[i];

        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightHalf[j];

        j++;
        k++;
    }
}

void mergeSort(Edge *arr, int first, int last, int (*compare)(Edge*, Edge*)) {
    if (first < last) {
        int middle = first + (last - first) / 2;

        mergeSort(arr, first, middle, compare);
        mergeSort(arr, middle + 1, last, compare);

        merge(arr, first, middle, last, compare);
    }
}

Graph kruskal(Graph *graph) {

    Edge result[graph->getVertices()];

    int e = 0; // Contador para a MST
    int i = 0; // Contador para os vertices ordenados do grafo
 
    //qsort(graph->edges, graph->getEdges(), sizeof(graph->edges[0]), comparison);
    mergeSort(graph->edges, 0, graph->getEdges() - 1, compareWeight);
 
    Subset subsets[graph->getVertices()];

    // Cria nVertices conjuntos com um elemento
    for(int v = 0; v < graph->getVertices(); v++) {
        subsets[v] = { v, 0 };
    }

    // Seleciona nVertices-1 arestas
    while(e < graph->getVertices() - 1) {
        // Seleciona a menor aresta
        Edge nextEdge = graph->edges[i++];
        
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dst);

        // Verifica se a aresta forma um ciclo
        if(x != y) {
            result[e++] = nextEdge;
            doUnion(subsets, x, y);
        }

    }

    return Graph(graph->getVertices(), result, e);
}
