#include <stdio.h>
#include <stdlib.h>

//Buscar o elemento 4

/*void verificar(int *vetor,int inicio,int fim){

    

}*/
int buscaBinaria(int *vetor,int N,int elem){
    int i,inicio,meio,final;
    inicio = 0;
    final = N-1;
    while(inicio<=final){
        meio = (inicio+final)/2; //usa a variavel meio sempre para a comparação
        if(elem<vetor[meio]){
            final = meio-1; //busca na metade esquerda
        }else{
            if(elem>vetor[meio]){
                inicio = meio+1; //busca na metade direita
            }else{
                return meio;
            }
        }
    }
    return -1;
}


void verificar_mid(int *vetor,int C,int F){

    int mid = F/2;


    if(vetor[mid]>4){

        verificar_mid(vetor,mid+1,F+(mid+1));

        //verificar(vetor,mid+1,N);

        

    }else if(vetor[mid]<4){

        verificar_mid(vetor,mid-1,mid-1);

        //verificar(vetor,0,mid-1);



    }else{
        printf("\tO número desejado está na posição [%d].\n",mid);
    }


}

int main(void){

    int *vetor,x = 5,R;
    vetor = (int*) malloc(sizeof(int)*x);
    for(int i = 0;i<x;i++){
        vetor[i] = i;
    }

    R = buscaBinaria(vetor,x,4);
    printf("\tPosição:%d\n",R);


    //verificar_mid(vetor,0,x);

    



    return 0;
}