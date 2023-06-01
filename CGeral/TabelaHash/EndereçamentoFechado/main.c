#include "funct.h"
int main(void) {
    //Forma de armazenamento e organização de dados na forma de um vetor estático e com o auxilio de listas encadeadas
    // e que a forma de armazenamento é com base no hash code do respectivo elemento a ser inserido,calculado a partir do módulo do valor pelo tamanho
    //da tabela,caso dois valores tenham hash codes iguais,ocorre uma colisão e o elemento é inserido após o ultimo
    //elemento armazenado na respectiva lista na posição

    /*
    Nesse método, cada posição da tabela hash contém uma lista encadeada. 
    Os elementos que têm o mesmo valor de hash são inseridos na mesma posição da lista.
     Se ocorrer uma colisão, ou seja, se vários elementos tiverem o mesmo valor de hash, 
     eles serão inseridos na lista correspondente. 
    Isso permite o armazenamento de múltiplos valores em uma única posição da tabela hash.
    */
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

    remover(tabela, "M");
    busca(tabela,"A");
    busca(tabela,"F");
    imprimir_Tabela_Hash(tabela);

    return 0;
}
