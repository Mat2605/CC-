#include <stdio.h>
#include <stdlib.h>
int main(void){
    int *vetor,aux,h = 1,j;
    vetor = (int*)malloc(sizeof(int)*8);
    for(int i = 0;i<8;i++){
        vetor[i] = i-(2*i);
    }
    do h = h*3 +1;while(h<8);
    do{
        h = h/3;
        for(int i = h;i<8;i++){
            aux = vetor[i];
            j = i;
            while(vetor[j-h]>aux){
                vetor[j] = vetor[j-h];
                j-=h;
                if(j<h){
                    break;
                }

            }
            vetor[j] = aux;
        }
    }while(h!=1);

    for(int i = 0;i<8;i++){
        printf("\t%d\n",vetor[i]);
    }



    return 0;
}