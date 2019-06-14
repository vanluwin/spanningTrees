#include "Graph.hpp"

int main(int argc, char **argv) {
    if(argc < 3) {
        cout << "Argumentos faltando!\nUso: " << argv[0] << " <grafo> <saida>\n";
        exit(0);
    }  
  
    Graph graph(argv[1]);
    
    if(string(argv[2]).find("stdout") != std::string::npos)
        spanningTrees(&graph);
    else if(string(argv[2]).find("arquivo") != std::string::npos) {
        cout << "Arvores geradoras serao salvas no arquivo allSpanningTrees\n";
        spanningTreesToFile(&graph);
    }
    else {
        cout << "Saida invalida\n";
        exit(0);
    }

    return 0;
}