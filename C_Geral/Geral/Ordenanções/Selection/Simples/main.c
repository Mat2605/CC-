#include <stdio.h>
#include <stdlib.h>
int main(void){
    int *vetor,min,aux;
    vetor = (int*)malloc(sizeof(int)*8);
    for(int i = 0;i<8;i++){

        vetor[i] = 10 - i; 
         

    }
    for(int i = 0;i<7;i++){
        min = i;
        for(int j = i+1;j<8;j++){
            if(vetor[min]>vetor[j]){
                min = j;
            }
        }
        aux = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = aux;

    }

    for(int i = 0;i<8;i++){
        printf("\t%d\n",vetor[i]);
    }
    return 0;
}