#include "Graph.hpp"

int main(int argc, char **argv) {
    if(argc < 2) {
        cout << "Argumentos faltando!\nUso: " << argv[0] << " <grafo>\n";
        exit(0);
    } 

    //int arr[] = { 35, 33, 42, 10, 14, 19, 27, 44, 26, 31 };

    Graph graph(argv[1]);
    //Graph graph("../instances/grid/12grid.in", 7);

    //cout << "\nGraph: " << endl << graph << endl;
    cout << "Calculando MST para um grafo com " << 
        graph.getVertices() <<  " vertices e " << 
        graph.getEdges() << " arestas.."
    << endl;

    Graph mst = kruskal(&graph);

    cout << "\nMST:\n" << mst << endl;

    return 0;
}