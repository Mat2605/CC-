#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 10
typedef struct chave{

    char caracteres[20];
    struct chave *next;

}chave;

typedef struct TabelaHash{

    struct chave *tabela[TAMANHO];

}TabelaHash;
int hash(char *c){
    int fh = 0;
    for(int i = 0;c[i]!='\0';i++){
        fh += c[i];
    }
    return fh % TAMANHO;
}
struct chave* CriarChave(char *c){
    struct chave* aux = malloc(sizeof(chave));
    strcpy(aux->caracteres,c);
    aux->next = NULL;
    return aux;
}

void InserirTabela(TabelaHash *tabela,char *c){
    int index = hash(c);
    struct chave *aux = CriarChave(c);
    if(tabela->tabela[index]==NULL){

        tabela->tabela[index] = aux;

    }else{
        struct chave *var = tabela->tabela[index];
        while(var->next!=NULL){
            var = var->next;
        }
        var->next = aux;
    }
    
}
void remover(TabelaHash *tabela,char *c){
    int index = hash(c);
    if(tabela->tabela[index]!=NULL && (!strcmp(tabela->tabela[index]->caracteres,c))){
        struct chave *aux = tabela->tabela[index];
        tabela->tabela[index] = tabela->tabela[index]->next;
        free(aux);
        return;
    }
    struct chave *aux = tabela->tabela[index];
    struct chave *aux_2= NULL;
    while(aux!=NULL){
        if(!strcmp(aux->caracteres,c)){
            aux_2->next = aux->next;
            free(aux);
            return;
        }
        aux_2 = aux;
        aux = aux->next;

    } 
}
void busca(TabelaHash *tabela, char *c) {
    int index = hash(c);
    if (tabela->tabela[index] != NULL && strcmp(tabela->tabela[index]->caracteres, c) == 0) {
        printf("\tEncontrado!\n");
        return;
    }
    struct chave *aux = tabela->tabela[index];
    while (aux != NULL) {
        if (!strcmp(aux->caracteres,c)) {
            printf("\tEncontrado!\n");
            return;
        }
        aux = aux->next;
    }
    printf("\tNão Encontrado!\n");
}



void imprimir(TabelaHash *tabela){
    for(int i = 0;i<TAMANHO;i++){
        printf("<%d>",i);
        struct chave* aux = tabela->tabela[i];
        while(aux!=NULL){
            printf("<%s>",aux->caracteres);
            aux = aux->next;
        }
        printf("\n");
    }
}
int main(void){
    TabelaHash *tabela = malloc(sizeof(TabelaHash));
    for(int i = 0;i<TAMANHO;i++){
        tabela->tabela[i] = NULL;
    }
    InserirTabela(tabela,"A");
    InserirTabela(tabela,"B");
    InserirTabela(tabela,"C");
    InserirTabela(tabela,"D");
    InserirTabela(tabela,"E");
    InserirTabela(tabela,"F");
    InserirTabela(tabela,"G");
    InserirTabela(tabela,"H");
    InserirTabela(tabela,"I");
    InserirTabela(tabela,"J");
    InserirTabela(tabela,"K");
    InserirTabela(tabela,"L");
    InserirTabela(tabela,"M");
    InserirTabela(tabela,"N");
    InserirTabela(tabela,"O");
    InserirTabela(tabela,"P");
    InserirTabela(tabela,"Q");
    InserirTabela(tabela,"R");
    InserirTabela(tabela,"S");
    InserirTabela(tabela,"T");
    InserirTabela(tabela,"U");
    InserirTabela(tabela,"V");
    InserirTabela(tabela,"W");
    InserirTabela(tabela,"X");
    InserirTabela(tabela,"Y");
    InserirTabela(tabela,"Z");
    InserirTabela(tabela,"M");
    remover(tabela,"M");
    busca(tabela,"Y");
    imprimir(tabela);
    return 0;
}