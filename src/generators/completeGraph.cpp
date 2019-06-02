#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Argumentos faltando!\nUso: " << argv[0] << " <numenro_de_vertices>\n";
        return -1;
    }

    srand(time(NULL));

    cout << "Gerando grafo com " << argv[1] << " vertices...\n";

    string fileName = argv[1];
    fileName += "completo.in";

    ofstream file;
    file.open(fileName);

    
    file << argv[1] << endl;

    for(int i = 1; i < atoi(argv[1]); i++) {
        for(int j = i + 1; j <= atoi(argv[1]); j++) {
            file << i << " " << j << " " << rand() % 100 + 1 << endl;
        }     
    }

    file.close();

    return 0;
}