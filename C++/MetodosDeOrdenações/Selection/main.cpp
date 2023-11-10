#include <iostream>
#include <cstdlib>
#define ArraySize 10
using namespace std;

int main(int argc, char *argv[]){
    int *vetor = new int[ArraySize];
    for(int i = 0; i < ArraySize; i++){
        vetor[i] = rand() + 1;
    }
    int min, aux;
    for(int i = 0; i < ArraySize - 1; i++){
        min = i;
        for(int j = i + 1; j < ArraySize; j++){
            if(vetor[min] > vetor[j]){
                min = j;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
    }
    for(int i = 0; i < ArraySize; i++){
        cout << "Vetor[" << i << "]: " << vetor[i] << "\n";
    }
    delete[] vetor;
    return 0;
}
