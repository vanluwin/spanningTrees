#include "Graph.hpp"

int main(int argc, char **argv) {
    if(argc < 2) {
        cout << "Argumentos faltando!\nUso: " << argv[0] << " <grafo>\n";
        exit(0);
    }  
  
    Graph graph(argv[1]);
    Graph mst = kruskal(&graph);
    
    cout << "\nGrafo\n" << graph << "\nArvore geradora minima\n" << mst << endl;    

    return 0;
}