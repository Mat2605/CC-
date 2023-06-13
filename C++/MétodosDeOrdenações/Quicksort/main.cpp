#include <iostream>
#include <time.h>
#include <cstdlib>
#define ArraySize 10
using namespace std;
void Partir(int esq,int dir,int *i,int *j,int *vetor){
    *i = esq;
    *j = dir;
    int pivo = (vetor[(*i) + (*j) / 2]), aux;
    do{
        while(pivo>(vetor[*i])){
            (*i)++;
        }
        while(pivo<(vetor[*j])){
            (*j)--;
        }
        if(*i<=*j){
            aux = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = aux;
            (*i)++;
            (*j)--;
        }

    }while((*i)<=(*j));

}
void Ordena(int esq,int dir,int *vetor){
    int i,j;
    Partir(esq,dir,&i,&j,vetor);
    if(esq<j){
        Ordena(esq,j,vetor);
    }else if(i<dir){
        Ordena(i,dir,vetor);
    }
}
void QuickSort(int *vetor){


    Ordena(0,ArraySize-1,vetor);

}
int main(int argc,char *argv[]){
    int *vetor = new int[ArraySize];
    for(int i = 0;i<ArraySize;i++){
        vetor[i] = ArraySize - i;
    }
    QuickSort(vetor);
    for(int i = 0;i<ArraySize;i++){
        cout << "Vetor[" << i << "]: " << vetor[i]<<"\n";
    }
    return 0;

}