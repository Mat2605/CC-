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
void remover(Tabela_Hash *tabela, char *key) {
    // Calcula o índice hash para a chave
    int index = encontrarHash(key, 7);

    // Verifica se o primeiro elemento da lista corresponde à chave
    if (tabela->table[index] != NULL && strcmp(tabela->table[index]->nome, key) == 0) {
        struct Passageiro *remover = tabela->table[index];
        tabela->table[index] = tabela->table[index]->next;
        free(remover);
        return;
    }

    // Procura a chave nas colisões
    struct Passageiro *atual = tabela->table[index];
    struct Passageiro *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, key) == 0) {
            printf("\tEncontrado!\n");
            anterior->next = atual->next;
            free(atual);
            return;
        }

        anterior = atual;
        atual = atual->next;
    }

    printf("\tElemento não encontrado!\n");
}

struct Passageiro* busca(Tabela_Hash* tabela, char* key) {
    int index = encontrarHash(key,7);
    
    // Verifica se a posição na tabela contém o nó com a chave procurada
    if (tabela->table[index] != NULL && strcmp(tabela->table[index]->nome, key) == 0) {
        printf("\tEncontrado!\n");
        return tabela->table[index];
    }
    
    // Se a posição não contém o nó, procura pela chave nas posições seguintes usando sondagem linear
    int i = (index + 1) % 7;
    while (i != index) {
        if (tabela->table[i] != NULL && strcmp(tabela->table[i]->nome, key) == 0) {
            printf("\tEncontrado!\n");
            return tabela->table[i];
        }
        i = (i + 1) % 7;
    }
    
    printf("\tNão Encontrado!\n");
    return NULL;
    // Elemento não encontrado.
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
