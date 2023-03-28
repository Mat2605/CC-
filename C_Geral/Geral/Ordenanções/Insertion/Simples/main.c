#include <stdio.h>
#include <stdlib.h>
int main(void){
    int *vetor,aux,j;
    vetor = (int*)malloc(sizeof(int)*8);
    for(int i = 0;i<8;i++){

        vetor[i] = 10 - i; 
         
    }
    for(int i =1;i<8;i++){
        aux = vetor[i];
        j = i -1;
        while((j>=0)&&(aux<vetor[j])){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = aux;


    }
    for(int i = 0;i<8;i++){
        printf("\t%d\n",vetor[i]);
    }

    return 0;
}
