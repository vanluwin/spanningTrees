#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
 
int main(int argc, char **argv) {
    if (argc < 3) {
        cout << "Argumentos faltando!\nUso: " << argv[0] << " <linhas> <colunas>\n";
        return -1;
    }

    srand(time(NULL));

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    int vertices = rows * cols;

    cout << "Gerando grafo grid com " << vertices << " vertices...\n";

    string fileName = to_string(vertices) + "grid.in";

    ofstream file;
    file.open(fileName);
    
    file << rows << endl << cols << endl;

    int matrix[rows][cols];
    int k = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = k;
            k++;
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if (j + 1 < cols)
                file << matrix[i][j] << " " << matrix[i][j+1] << " " << rand() % 100 + 1 << endl;
            if (i + 1 < rows)
                file << matrix[i][j] << " "  << matrix[i+1][j] << " " << rand() % 100 + 1 << endl;
        }
    }

    file.close();

    return 0;
}