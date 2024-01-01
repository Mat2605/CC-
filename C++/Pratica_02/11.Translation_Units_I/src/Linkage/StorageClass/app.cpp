#include <iostream>
using namespace std;
// Declaração de uma variável global sem especificação de classe de armazenamento
int v1;

// Declaração de uma variável global com a classe de armazenamento estática
static int v2 = 2;

// Declaração de uma variável global com a classe de armazenamento externa
extern int v3;

// Declaração de uma variável global com a classe de armazenamento thread_local
thread_local int v4;

// Declaração de uma variável global com as classes de armazenamento thread_local e estática
thread_local static int v5;

// Função principal do programa
int main() {
    // Declaração de uma variável local automática (auto) no escopo da função main
    int v6;

    // Declaração de uma variável local automática (auto) com inicialização
    auto v7 = 3;

    // Declaração de uma variável local estática no escopo da função main
    static int v8;

    // Declaração de uma variável local com as classes de armazenamento thread_local e automática (auto)
    thread_local int v9;

    // Alocação dinâmica de um array de inteiros e atribuição à variável "array"
    auto array = new int[10]; // "array" é uma variável local automática
    // Observação: A palavra-chave "auto" na declaração de "array" significa que o tipo é deduzido automaticamente pelo compilador.

    // Nota: No final do escopo da função main, a variável "array" ainda existe na memória, mas precisa ser deletada manualmente para evitar vazamentos de memória.
}
