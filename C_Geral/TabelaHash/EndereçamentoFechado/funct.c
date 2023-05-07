#include "funct.h"

//criar um componente na tabela hash
struct Passageiro *criar_No(char *nome,int num){
    struct Passageiro *No = malloc(sizeof(Passageiro));
    No->nome = malloc(strlen(nome)+1);
    strcpy(No->nome,nome);
    No->num_de_voo = num;
    No->next = NULL;
    return No;
}
//encontrar a rash,M sendo o número de elementos
int encontrarHash(char *conteudo,int M){
    int fh = 0;
    for(int i = 0;conteudo[i]!='\0';i++){
        fh += conteudo[i];
    }
    return fh % M;
}
//inserir uma chave,encontrar o endereço na tabela
void inserir(struct Tabela_Hash *hash, char *key, int value){
    int index =  encontrarHash(key,7);
    struct Passageiro *No = criar_No(key, value);
    //se a lista estiver vazia o elemento é adicionado de cara
    if(hash->table[index] ==NULL){
        hash->table[index] = No;
    }else{
        //caso contrário cria se outro componente da lista,que o anterior irá apontar
        struct Passageiro *No2 = hash->table[index];
        //encontrar o ultimo nó da lista
        while(No2->next!=NULL){
            No2 = No2->next;
        }
        //insere o nó no final da lista
        No2->next = No;
    }
}

//remover um nó na tabela
void remover(Tabela_Hash *tabela,char *key){
    //busca o endereço para a palavra
    int index = encontrarHash(key,7);
    //caso o respectivo endereço não esteja nulo e seu conteúdo for igual a chave de busca,o elemento é removido
    if(tabela->table[index]!=NULL&&(!strcmp(tabela->table[index]->nome,key))){
        free(tabela->table[index]);
        tabela->table[index] = NULL;
        return;
    }
}
struct Passageiro *busca(Tabela_Hash *tabela,char *key){
    int index = encontrarHash(key,7);
    // verifica se a posição na tabela contém o nó com a chave procurada
    if(tabela->table[index]!=NULL && !strcmp(tabela->table[index]->nome,key)){
        return tabela->table[index];
    }
    // se a posição não contém o nó, procura pela chave nas posições seguintes usando sondagem linear
    int i = index + 1;
    while(i!=index){
        if(i>=7){
            i = 0;
        }
        if(tabela->table[i]!=NULL && !strcmp(tabela->table[i]->nome,key)){
            return tabela->table[i];
        }
        i++;

    }
    return NULL;
    //elemento não encontrado.
}
void imprimir_Tabela_Hash(struct Tabela_Hash *hash) {
    for (int i = 0; i < 7; i++) {
        printf("[%d]: ", i);
        struct Passageiro *atual = hash->table[i];
        while (atual != NULL) {
            printf("(%s, %d) -> ", atual->nome, atual->num_de_voo);
            atual = atual->next;
        }
        printf("NULL\n");
    }
}
