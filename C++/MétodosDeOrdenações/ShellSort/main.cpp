#include <iostream>
#include <cstdlib>
#include <time.h>
#define ArraySize 50
using namespace std;
int main(int argc,char *argv[]){
    clock_t inicio, fim;
    double tempo_gasto;
    inicio = clock();
    int *vetor = new int[ArraySize],h=1,j,i,aux;
    for(i = 0;i<ArraySize;i++){
        vetor[i] = rand() + 100;
    }
    do{
        h = (h*3) + 1;
    }while(h<ArraySize);
    do{
        h = h/3;
        for(i = h;i<ArraySize;i++){
            aux = vetor[i];
            j = i;
            while(vetor[j-h]>aux){
                vetor[j] = vetor[j-h];
                j -=h;
                if(j<h){
                    break;
                }
            }
            vetor[j] = aux;

        }

    }while(h!=1);
    for(i = 0;i<ArraySize;i++){
        cout << "Vetor[" << i << "]: " << vetor[i]<<"\n";
    }
    fim = clock(); // Fim da contagem de tempo
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << "Tempo Gasto: " << tempo_gasto << "\n";
    return 0;
}