#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int *vetor,aux;
    vetor = (int*)malloc(sizeof(int)*8);
    for(int i = 0;i<8;i++){

        vetor[i] = 10 - i; 
         

    }

    for(int i = 0;i<7;i++){
        for(int j = 0;j<7;j++){
            if(vetor[j]>vetor[j+1]){

                aux = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = aux;

            }
        }
    }

    for(int i = 0;i<8;i++){
        printf("\tConteúdo Bolha[%d] ==> %d\n",i,vetor[i]);
    }


    system("PAUSE");
    return 0;
}