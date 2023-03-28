#include "var.h"

void inicializar_lista(ListaInteiro *var){
    var->Primeiro = (apontador) malloc(sizeof(celula));
    var->Ultimo = var->Primeiro;
    var->Primeiro->Prox = NULL;
}

void lista_vazia(ListaInteiro *var){
    if(var->Primeiro==var->Ultimo){
        printf("\tLista Vazia!\n");
    }
}

void inserir_valor(ListaInteiro *var,inteiro *V){
    var->Ultimo->Prox = (apontador)malloc(sizeof(celula));
    var->Ultimo = var->Ultimo->Prox;
    var->Ultimo->num = (*V);
    var->Ultimo->Prox = NULL;
}

void retirar_valor(ListaInteiro *var,inteiro *V){
    celula *aux;
    *V = var->Primeiro->Prox->num;
    aux = var->Primeiro;
    var->Primeiro = var->Primeiro->Prox;
    free(aux);
}

void imprimir(ListaInteiro *var){
    apontador aux;
    aux = var->Primeiro->Prox;
    while(aux!=NULL){
        printf("\t%d\n",aux->num.valor);
        aux = aux->Prox;
    }
}
