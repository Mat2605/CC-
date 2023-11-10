#include <iostream>
#include <cstdlib>
#include <time.h>
#define ArraySize 10
using namespace std;
int main(int argc,char *argv[]){
    clock_t inicio, fim;
    double tempo_gasto;
    inicio = clock();
    int *vetor = new int[ArraySize],i,j,aux;
    for(i = 0;i<ArraySize;i++){
        vetor[i] = rand() + 100;
    }
    for(i = 1;i<ArraySize;i++){
        aux = vetor[i];
        j = i - 1;
        while((j>=0)&&(aux<vetor[j])){
            vetor[j+1] = vetor[j];
            j-=1;
        }
        vetor[j+1] = aux;
    }
    for(i = 0;i<ArraySize;i++){
        cout << "Vetor[" << i << "]: " << vetor[i]<<"\n";
    }
    fim = clock(); // Fim da contagem de tempo
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << "Tempo Gasto: " << tempo_gasto << "\n";

    return 0;
}