#include <iostream>
using namespace std;
int main(){
    int array[5] = {1,2,3,4,5}; // explícida
    int vetor[] = {1,2,3,4}; // implícida
    int d[3] = {1, 2}; // explícida com d[2] valendo 0
    //todas as posições com 0:
    int e[4] = {0};
    int f[3] = {}; 
    int g[3] {}; 
    //Para matrizes o número de colunas deve ser sempre conhecido
    int a[][2] = { {1,2}, {3,4}, {5,6} }; // implícidas
    int b[][2] = { 1, 2, 3, 4 }; // implícidas
    return 0;
}