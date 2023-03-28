#include <stdio.h>
#include <stdlib.h>
int main(void){

    int *inteiros,**matriz,x = 3,y = 3;

    //Evitar sempre ocupar memória de forma desnecessária.
    //Durante o tempo de execução,fazer alterações no espaço de memória destinado a uma variável.

    //malloc para vetores
    inteiros = (int*) malloc(sizeof(int)*x);
    for(int i = 0;i<x;i++){
        inteiros[i] = i;
    }
    //
    //malloc para matrizes
    //1):
    matriz = (int**)malloc(sizeof(int*)*x);
    for(int i = 0;i<x;i++){
        matriz[i] = (int*)malloc(sizeof(int)*y);
    }
    for(int i = 0;i<x;i++){
        for(int j = 0;j<y;j++){
            matriz[i][j] = i+(2*j);
        }
    }
    //2)
    /*
    matriz = (int **)malloc(sizeof(int*)*x);
  
  for (i = 0; i < x; i++)
  {
    matriz[i] = (int*)malloc(y*sizeof(int));
  }
    */

   //calloc:semelhante a função malloc,declaração diferente.
   //inteiros = (int*) calloc(x,sizeof(int))

   //realloc:serve para alocar memória ou blocos de memória previamente alocados,retorna void para o novo bloco alocado.


   //previamente alocado com o tamanho 3
   //inteiros = realloc(inteiros,2*sizeof(int));

   //Usar realloc com função de malloc
   //inteiros = (int*)realloc(NULL,x*sizeof(int))

   for(int i = 0;i<x;i++){
    printf("\tVetor Inteiros ==> %d\n",inteiros[i]);
    for(int j = 0;j<y;j++){
        printf("\tMatriz ==> %d\n",matriz[i][j]);
    }
   }






    free(inteiros);
    free(matriz);

    return 0;
}
/*
matriz1 = (int **)calloc(n_linhas,sizeof(int *)); 
  for (i = 0; i < n_linhas; i++)
  {
   // alocar a quantidade de colunas de cada linha
    matriz1[i] = (int *)calloc(n_colunas,sizeof(int));
  }
    */