#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 27
typedef struct chave{

    char palavra[30];
    int matricula;

}chave;

typedef struct TABELA_HASH{

    struct chave *tabela[TAMANHO];

}TABELA_HASH;
void inicializarTabela(TABELA_HASH *tamanho){
    for(int i = 0;i<TAMANHO;i++){
        tamanho->tabela[i] = NULL;
    }
}
void inicializarVetor(int vetor[TAMANHO]){
    for(int i = 0;i<TAMANHO;i++){
        vetor[i] = (rand() % 101) + 1;
    }

}
int calcularHash(char *palavra){
    int fh = 0,j = 0;
    int vetor[TAMANHO];
    inicializarVetor(vetor);
    for(int i = 0;palavra[i]!='\0';i++){
        if(j>TAMANHO){
            j = 0;
        }
        fh += vetor[j] * palavra[i];
        j++;
    }
    return fh % TAMANHO;
}
void inserir(TABELA_HASH *tabela, char *c, int num) {
    int index;
    index = calcularHash(c);
    
    if (tabela->tabela[index] == NULL) {
        tabela->tabela[index] = malloc(sizeof(chave));
        tabela->tabela[index]->matricula = num;
        strcpy(tabela->tabela[index]->palavra, c);
        return;
    } else {
        index = calcularHash(c+1);
        while (tabela->tabela[index] != NULL) {
            if (tabela->tabela[index] == NULL) {
                tabela->tabela[index] = malloc(sizeof(chave));
                tabela->tabela[index]->matricula = num;
                strcpy(tabela->tabela[index]->palavra, c);
                return;
            }
            index = calcularHash(c+1);
        }
    }
}

void imprimir(TABELA_HASH *tabela){
    for(int i = 0;i<TAMANHO;i++){
        printf("<%d>",i);
        if(tabela->tabela[i]!=NULL){
            printf("<%d><%s>",tabela->tabela[i]->matricula,tabela->tabela[i]->palavra);
        }
        printf("\n");
    }
}
int main(void){
    TABELA_HASH *tabela = malloc(sizeof(TABELA_HASH));
    inicializarTabela(tabela);
    inserir(tabela,"MAT",4668);
    inserir(tabela,"ATM",4668);
    inserir(tabela,"AMT",4668);
    inserir(tabela,"MAT",4668);
    inserir(tabela,"ATM",4668);
    inserir(tabela,"AMT",4668);
    imprimir(tabela);
    return 0;
}