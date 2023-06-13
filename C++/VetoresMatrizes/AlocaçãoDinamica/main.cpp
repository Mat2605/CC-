#include <iostream>
using namespace std;
int main(){
    int n = 5;
    int m = 3;
    //Alocação Dinamica de vetor;
    int *vet = new int[m];
    //Alocação Dinamica da matriz;
    int **mat = new int*[n];
    for(int i = 0;i<m;i++){
        vet[i] = i*i;
        cout << "vetor["<<i<<"]:"<<vet[i]<<"\n";
    }
    for(int i = 0; i < n; i++) {
        mat[i] = new int[m];}

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mat[i][j] = i + j;}}

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<<"Matriz[" << i << "][" << j << "]:" << mat[i][j] << "\n";
            }
                }
    for(int i = 0; i < n; i++) {
        delete[] mat[i];
    }
    delete[] vet;
    delete[] mat;

    return 0;
}