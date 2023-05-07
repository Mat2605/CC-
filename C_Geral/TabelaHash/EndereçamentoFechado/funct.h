#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Passageiro{
    char *nome;
    int num_de_voo;
    struct Passageiro *next;
} Passageiro;

typedef struct Tabela_Hash{
    struct Passageiro *table[7];   
} Tabela_Hash;

int encontrarHash(char *conteudo, int M);
struct Passageiro *criar_No(char *nome, int num);
void inserir(Tabela_Hash *hash, char *key, int value);
struct Passageiro *busca(Tabela_Hash *tabela, char *key);
void remover(Tabela_Hash *tabela, char *key);
void imprimir_Tabela_Hash(struct Tabela_Hash *hash);