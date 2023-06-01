#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int valor;

}inteiro;

typedef struct celula *apontador;

typedef struct celula{
    inteiro num;
    apontador Prox;

}celula;

typedef struct{
    apontador Primeiro, Ultimo;
}ListaInteiro;

void inicializar_lista(ListaInteiro *var);

void lista_vazia(ListaInteiro *var);

void inserir_valor(ListaInteiro *var,inteiro *V);

void retirar_valor(ListaInteiro *var,inteiro *V);

void imprimir(ListaInteiro *var);