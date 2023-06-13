#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define tamanho 7

typedef struct conteudo {
    int n;
    char *c;
} conteudo;

typedef struct Tabela_Hash {
    struct conteudo *tabela[tamanho];
} Tabela_Hash;
void inicializar_Tabela_Hash(Tabela_Hash *hash) {
    for (int i = 0; i < tamanho; i++) {
        hash->tabela[i] = NULL;
    }
}

void gerar_vetor(int vetor[7]) {
    for (int i = 0; i < 7; i++) {
        vetor[i] = (rand() % (100 - 1 + 1)) + 1;
    }
}

int encontrarHash(char *conteudo, int M, int vetor[7]) {
    int fh = 0;
    int j = 0;
    for (int i = 0; conteudo[i] != '\0'; i++) {
        if (j == 7) {
            j = 0;
        } else {
            fh += conteudo[i] * vetor[j];
            j += 1;
        }
    }
    printf("%d",fh % M);
    return fh % M;
}

struct conteudo *criar_No(char *nome, int num) {
    struct conteudo *no = malloc(sizeof(conteudo));
    no->c = malloc(strlen(nome) + 1);
    strcpy(no->c, nome);
    no->n = num;
    return no;
}

void inserir(struct Tabela_Hash *hash, char *key, int num, int vetor[7]) {
    int index = encontrarHash(key, 7, vetor);
    printf("%d\n",index);
    struct conteudo *no = criar_No(key, num);
    if (hash->tabela[index] == NULL) {
        hash->tabela[index] = no;
    } else {
        printf("\tJa esta presente na lista\n");
    }
}

void imprimir(struct Tabela_Hash *hash) {
    for (int i = 0; i < 7; i++) {
        if (hash->tabela[i] != NULL) {
            printf("\t--> %s | --> %d\n", hash->tabela[i]->c, hash->tabela[i]->n);
        }

    }
}

int main() {
    srand(time(NULL));
    Tabela_Hash hash;
    inicializar_Tabela_Hash(&hash);
    int vetor[7] = {0};
    gerar_vetor(vetor);
    inserir(&hash, "chave1", 10, vetor);
    inserir(&hash, "abacaxi", 20, vetor);
    inserir(&hash, "abb", 30, vetor);
    inserir(&hash, "bba", 30, vetor);
    imprimir(&hash);
    return 0;
}
