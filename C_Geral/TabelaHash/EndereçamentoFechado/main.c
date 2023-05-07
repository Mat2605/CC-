#include "funct.h"
int main(void) {
    //Forma de armazenamento e organização de dados na forma de um vetor estático e com o auxilio de listas encadeadas
    // e que a forma de armazenamento é com base no hash code do respectivo elemento a ser inserido,calculado a partir do módulo do valor pelo tamanho
    //da tabela,caso dois valores tenham hash codes iguais,ocorre uma colisão e o elemento é inserido após o ultimo
    //elemento armazenado na respectiva lista na posição
    Tabela_Hash *tabela = malloc(sizeof(Tabela_Hash));
    for (int i = 0; i < 7; i++) {
        tabela->table[i] = NULL;
    }

    inserir(tabela, "A", 1);
    inserir(tabela, "M", 2);
    inserir(tabela, "B", 3);
    inserir(tabela, "C", 4);
    inserir(tabela, "D", 5);
    inserir(tabela, "F", 6);
    inserir(tabela, "E", 7);
    inserir(tabela, "J", 8);
    inserir(tabela, "K", 9);

    imprimir_Tabela_Hash(tabela);

    remover(tabela, "A");

    imprimir_Tabela_Hash(tabela);

    return 0;
}
