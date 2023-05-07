#include <iostream>
using namespace std;

// Função que recebe uma matriz 2D por referência
void modificar_matriz(int** matriz, int linhas, int colunas) {
    // Modifica o valor do elemento (0,0) da matriz
    matriz[0][0] = 10;
}

int main() {
    int linhas = 2;
    int colunas = 2;

    // Aloca memória para a matriz
    int** matriz = new int*[linhas];
    for (int i = 0; i < linhas; i++) {
        matriz[i] = new int[colunas];
    }

    // Preenche a matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = i * colunas + j;
        }
    }

    // Imprime a matriz antes da modificação
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << matriz[i][j] << " " << "\n";
        }
    }

    // Chama a função que modifica a matriz
    modificar_matriz(matriz, linhas, colunas);

    // Imprime a matriz depois da modificação
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << matriz[i][j] << " "<<"\n";
        }
    }

    // Libera a memória alocada para a matriz
    for (int i = 0; i < linhas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
