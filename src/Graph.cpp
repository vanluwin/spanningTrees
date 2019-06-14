#include "Graph.hpp"
#include <vector>

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

    edge = {arr[0], arr[1], arr[2], 0};
}

// Função de comparação de pesos
int compareWeight(Edge *a, Edge *b) { 
    return a->weight <= b->weight; 
}

// Função de comparação de origens de arestas
int compareVertex(Edge *a, Edge *b) {
    if (a->src == b->src) return a->dst < b->dst;

    return a->src < b->src;
}

// Função de comparação de grafos pelos seus respectivos custos
int compareGraph(Graph *a, Graph *b) {
    return a->getCost() > b->getCost();
}

// Construtor default
Graph::Graph() {}

Graph::Graph(int _nVertices, int _nEdges) {
    nVertices = _nVertices;
    nEdges = _nEdges;
}

// Construtor usando um arquivo de instancia
Graph::Graph(string filePath) {
    file.open(filePath);

    string line;

    if (file.is_open()) {
        // Verifica se o grafo é grid ou completo
        if (filePath.find("completo") != std::string::npos) {
            // Lê a quantidade de vértices
            getline(file, line);
            nVertices = stoi(line);

            // Calcula a quantidade de vertices
            nEdges = (nVertices * (nVertices - 1)) / 2;

        } else {
            // Lê a quantidade de linhas e colunas do grafo
            getline(file, line);
            Edge edge;
            extractIntegers(line, edge);

            int rows = edge.src;
            int cols = edge.dst;

            // Calcula o numero de vértices e arestas
            nVertices = rows * cols;
            nEdges = (2 * rows * cols) - rows - cols;
        }

        // Aloca espaço para a lista de adjacência
        edges = new Edge[nEdges];

        if (edges == NULL) {
            delete[] edges;
            cout << "Erro ao alocar o vetor de arestas!\n";
            exit(0);
        }

        // Lê as arestas a serem inseridas no grafo
        int i = 0, _cost = 0;
        while (getline(file, line)) {
            // Armazena os valores dos vertices e aresta lidos
            Edge edge;
            extractIntegers(line, edge);

            // Insire o que foi lido na lista de adjacência
            edges[i] = edge;
            i++;
            // Incrementa o custo parcial
            _cost += edge.weight;
        }
        // Atualiza o custo total
        cost = _cost;

        file.close();

    } else {
        cout << "Erro ao abrir o arquivo.\n";
        exit(0);
    }
}

// Construtor para a MST
Graph::Graph(int _nVertices, Edge *edgeList, int _nEdges, int _cost) {
    nVertices = _nVertices;
    nEdges = _nEdges;
    cost = _cost;

    // Aloca espaço para a lista de adjacência
    edges = new Edge[nEdges];

    // Copia a lista passada para o atribuito da classe
    memcpy(edges, edgeList, nEdges * sizeof(Edge));

    // mergeSort(edges, 0, nEdges - 1, compareVertex);
}

// Construtor de cópia
Graph::Graph(const Graph &graph) {
    nVertices = graph.nVertices;
    nEdges = graph.nEdges;
    cost = graph.cost;

    edges = new Edge[nEdges];

    memcpy(edges, graph.edges, nEdges * sizeof(Edge));
}

// Class Destructor
Graph::~Graph() { 
    if(nEdges > 0)
        delete[] edges;
}

int Graph::getVertices() { return nVertices; }

int Graph::getEdges() { return nEdges; }

int Graph::getCost() { return cost; }

void Graph::setCost(int _cost) {
    cost = _cost;
}

int Graph::getFlag(Edge edge) {
    for(int i = 0; i < nEdges; i++) {
        if(edges[i].src == edge.src && edges[i].dst == edge.dst)
            return edges[i].flag;
    }
}

void Graph::setFlag(Edge edge, int flag) {
    for(int i = 0; i < nEdges; i++) {
        if(edges[i].src == edge.src && edges[i].dst == edge.dst)
            edges[i].flag = flag;
    }
}

void Graph::depthFirstSearch(int v, bool *visited) {
    // Mark the current node as visited and print it 
    visited[v] = true; 

    // Recur for all the vertices 
    // adjacent to this vertex 
    for(int i = 0; i < nEdges; i++)  
        if(edges[i].flag != 2 && !visited[i]) 
            depthFirstSearch(i, visited);    
}

bool Graph::isConnected() {

    bool *visited = new bool[nVertices];

    for(int i = 0; i < nVertices; i++) {
        visited[i] = false;
    }

    for(int i = 0; i < nEdges; i++) {
        // Aresta proibida
        if(edges[i].flag == 2)
            continue;

        int u = edges[i].src;
        int v = edges[i].dst;

        visited[u] = true;
        visited[v] = true;
    }

    for(int i = 0; i < nVertices; i++) {
        //cout << i << " is visited " << visited[i] << endl;
        if(!visited[i])
            return false;
    }

    return true;
}

Graph Graph::operator = (const Graph &graph) {
    nVertices = graph.nVertices;
    nEdges = graph.nEdges;
    cost = graph.cost;

    edges = new Edge[nEdges];

    memcpy(edges, graph.edges, nEdges * sizeof(Edge));

    return *this;
}

ostream &operator << (ostream &os, Graph &graph) {
    for (int i = 0; i < graph.nEdges; i++) {
        os << setw(2) << 
            graph.edges[i].src << " " << setw(2) << 
            graph.edges[i].dst << " " << setw(3) << 
            graph.edges[i].weight << " "
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
    // e seu rank é incrementado
    else {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
}

void merge(Edge *arr, int first, int middle, int last,
           int (*compare)(Edge *, Edge *)) {
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

void mergeSort(Edge *arr, int first, int last, int (*compare)(Edge *, Edge *)) {
    if (first < last) {
        int middle = first + (last - first) / 2;

        mergeSort(arr, first, middle, compare);
        mergeSort(arr, middle + 1, last, compare);

        merge(arr, first, middle, last, compare);
    }
}

Graph kruskal(Graph *graph) {
    Edge result[graph->getVertices()];

    int _cost = 0;  // Contador para o custo parcial do grafo
    int e = 0;      // Contador para a árvore
    int i = 0;      // Contador para os vertices ordenados do grafo

    // Ordena as arestas em ordem crescente de peso
    mergeSort(graph->edges, 0, graph->getEdges() - 1, compareWeight);

    // Cria nVertices conjuntos com um elemento
    Subset subsets[graph->getVertices()];

    for (int v = 0; v < graph->getVertices(); v++) {
        subsets[v] = {v, 0};
    }

    // Seleciona nVertices - 1 arestas para a árvore geradora
    while (e < graph->getVertices() - 1) {
        // Seleciona a menor aresta e incrementa o contador de arestas
        Edge nextEdge = graph->edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dst);

        // Verifica se a aresta é obrigatória
        if (nextEdge.flag == 1) {
            //cout << "Inserir obrigatoria " << nextEdge.src << " -- " << nextEdge.dst << " " << nextEdge.weight << endl;

            // Insere a aresta obrigatória
            result[e++] = nextEdge;
            _cost += nextEdge.weight;
            doUnion(subsets, x, y);
        }
        // Verifica se a aresta forma um ciclo e se não é proibida
        else if (x != y && nextEdge.flag != 2) {
            //cout << "Inserir " << nextEdge.src << " -- " << nextEdge.dst << " " << nextEdge.weight << endl;

            // Insere a melhor aresta dentre as não proibidas
            result[e++] = nextEdge;
            _cost += nextEdge.weight;
            doUnion(subsets, x, y);
        }
    }
    
    return Graph(graph->getVertices(), result, e, _cost);
}

void partition(Graph *p, Graph *spanningTree, MinHeap<Graph> *parts) {
    Graph p1 = *p, p2 = *p;

    for(int i = 0; i < spanningTree->getEdges(); i++) {
        // Percore as arestas da AG
        if(p->getFlag(spanningTree->edges[i]) != 1 && p->getFlag(spanningTree->edges[i]) != 2) {
            
            // Faz com que a aresta i seja proibida em p1
            p1.setFlag(spanningTree->edges[i], 2);
            // Faz com que a aresta i seja obrigatoria em p1
            p2.setFlag(spanningTree->edges[i], 1);

            /* 
                Faz o custo da partição ser o custo de sua AG
                mantendo a propriedade da heap
            */
            p1.setCost(kruskal(&p1).getCost());

            // Se a partição for conectada, ela é inserida na heap
            if(p1.isConnected()) {
                //cout << "\nP " << p1.getCost() << endl << p1 << endl;
                parts->push(p1, compareGraph);
            }

            p1 = p2;
        }
    
    
    }
}

// Implementação do algoritmo de Sorensen e Janssens
void spanningTrees(Graph *graph) {

    cout << "\nObtendo todas as arvores geradoras para\n" << *graph << endl; 
    
    MinHeap<Graph> partitions(200);

    // Adiciona a partição P0 (grafo passado como parametro)
    partitions.push(*graph, compareGraph);

    /* 
        Gera as partições a partir do grafo com menor custo,
        como se fez uso de uma heap basta pegar sua raiz com
        custo O(1).
    */ 
    Graph spanningTree, Ps;
    while(!partitions.empty()) {
        Ps = partitions.pop();

        spanningTree = kruskal(&Ps);
        cout << "\nc[s(P)] = " << spanningTree.getCost() << endl << spanningTree << endl;

        partition(&Ps, &spanningTree, &partitions);
    }
}

void spanningTreesToFile(Graph *graph) {
    cout << "\nObtendo todas as arvores geradoras para\n" << *graph << endl; 

    // Cria arquivo para escrita
    ofstream file;
    file.open("allSpanningTrees");

    file << "Graph\n" << *graph << endl;

    MinHeap<Graph> partitions(200);

    // Adiciona a partição P0 (grafo passado como parametro)
    partitions.push(*graph, compareGraph);

    /* 
        Gera as partições a partir do grafo com menor custo,
        como se fez uso de uma heap basta pegar sua raiz com
        custo O(1).
    */ 
    Graph spanningTree, Ps;
    while(!partitions.empty()) {
        Ps = partitions.pop();

        spanningTree = kruskal(&Ps);
        file << "\nc[s(P)] = " << spanningTree.getCost() << endl << spanningTree << endl;

        partition(&Ps, &spanningTree, &partitions);
    }

    file.close();
}