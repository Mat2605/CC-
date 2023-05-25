#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 10

typedef struct chave{

    char c;
    int i;

}chave;

typedef struct TabelaHash{

    struct chave *table[TAMANHO];

}TabelaHash;

int calcularHash(char c){
    int retorno = c % TAMANHO;
    retorno = abs(retorno);
    return retorno;
}
void inicializarTabela(TabelaHash *ptr){
    for(int i = 0;i<TAMANHO;i++){
        ptr->table[i] = NULL;
    }
}

struct chave* CriarChave(char caractere,int num){
    struct chave *aux = (struct chave*)malloc(sizeof(chave));
    aux->c = caractere;
    aux->i = num;
    return aux;
}
void inserir(TabelaHash *ptr,char caractere,int num){
    int index;
    index = calcularHash(caractere);
    struct chave *aux = CriarChave(caractere,num);
    if(ptr->table[index]==NULL){
        ptr->table[index] = aux;
        return;
    }
    while(ptr->table[index]!=NULL){
        index = calcularHash(caractere+1);
    }
    if(ptr->table[index]==NULL && index<TAMANHO){
        ptr->table[index] = aux;
        return;
    }
}
void busca(TabelaHash *hash, char c) {
    int index = calcularHash(c);
    if (hash->table[index] != NULL && hash->table[index]->c == c) {
        printf("Valor encontrado!\n");
        return;
    } else {
        for (int i = 0; i < TAMANHO; i++) {
            if (hash->table[i] != NULL && hash->table[i]->c == c) {
                printf("Valor encontrado!\n");
                return;
            }
        }
    }
    printf("Valor não encontrado\n");
}

void remover(TabelaHash *hash,char c){
    int index;
    index = calcularHash(c);
    struct chave *aux = hash->table[index];
    if(hash->table[index]->c==c && hash->table[index]!=NULL){
        hash->table[index] = NULL;
        free(aux);
        printf("Valor removido\n");
        return;
    }else{
        for(int i = 0;i<TAMANHO;i++){
            if(hash->table[index]->c==c && hash->table[index]!=NULL){
                struct chave *aux = hash->table[index];
                hash->table[index] = NULL;
                free(aux);
                printf("Valor removido\n");
                return;
            }
        }
    }
    printf("Valor não encontrado\n");
}
void imprimir(TabelaHash *ptr) {
    for (int i = 0; i < TAMANHO; i++) {
        if (ptr->table[i] != NULL) {
            printf("<<%d>><%d><%c>",i, ptr->table[i]->i, ptr->table[i]->c);
            printf("\n");
        }
    }
}

int main(void){
    TabelaHash *tabela = malloc(sizeof(TabelaHash));
    inicializarTabela(tabela);
    inserir(tabela,'a',1);
    inserir(tabela,'b',2);
    inserir(tabela,'c',3);
    inserir(tabela,'c',3);
    busca(tabela,'d');
    remover(tabela,'c');
    remover(tabela,'d');
    imprimir(tabela);
    return 0;
}
