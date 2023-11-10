#include "C:\Users\mathe\Documents\CC++\C\Proprios\ArquivosDefinitivo\.h\ListaDePalavras.h"

void Inicializa_Lista(Lista *var) {
    var->Primeiro = (apontador)malloc(sizeof(celula));
    var->Ultimo = var->Primeiro;
    var->Primeiro->prox = NULL;
}

Palavra* Inicializa_Palavra(Palavra *palavra, char *string) {
    palavra->contador = 1;
    strcpy(palavra->palavra, string);
    return palavra;
}

void Lista_Vazia(Lista *var) {
    if (var->Primeiro == var->Ultimo) {
        printf("Lista esta vazia!\n");
    }
}

void Inserir_Componente(Lista *var, char *string) {
    int palavra_presente = 0;
    apontador temp = var->Primeiro->prox;

    while (temp != NULL) {
        if (!strcmp(string, temp->palavra_lista.palavra)) {
            temp->palavra_lista.contador+=1;
            palavra_presente = 1;
            break;
        }
        temp = temp->prox;
    }
    
    if (!palavra_presente) {
        apontador nova_celula = (apontador)malloc(sizeof(celula));
        nova_celula->prox = NULL;
        nova_celula->palavra_lista = *(Inicializa_Palavra(&nova_celula->palavra_lista, string));
        var->Ultimo->prox = nova_celula;
        var->Ultimo = nova_celula;
    }
}

void Retirar_Componente(Lista *var, Palavra *palavra) {
    celula *aux;
    *palavra = var->Primeiro->prox->palavra_lista;
    aux = var->Primeiro;
    var->Primeiro = var->Primeiro->prox;
    free(aux);
}

void Imprimir_Conteudo(Lista *var) {
    apontador aux;
    aux = var->Primeiro->prox;
    
    while (aux != NULL) {
        printf("Palavra:[%s], Quantidade:[%zu]\n", aux->palavra_lista.palavra, aux->palavra_lista.contador);

        aux = aux->prox;
    }
}
