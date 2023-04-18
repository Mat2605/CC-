#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funct.h"

#define reg 3

int main(void) {
    char **MatrizBinario, conteudo[25], *nomeArquivo, *p;
    FILE *fp, *fpS;
    int resposta, aux, opcao;
    fpS = fopen("saida.asm", "w");
    // processa as instruções
    fp = fopen("entrada.asm","r");
    aux = contagem_linhas(fp);
    MatrizBinario = (char **)malloc(aux * sizeof(char *));
    for(int i = 0; i < aux; i++) {
        MatrizBinario[i] = (char*)malloc(sizeof(char)*reg);
    }

    while (fgets(conteudo, 25, fp ? fp : stdin)) {
        p = strtok(conteudo, ", ");

        if (!(strcmp(p, "add"))) {
            TipoR(p, fpS, MatrizBinario, "000");
        } else if (!(strcmp(p, "xor"))) {
            TipoR(p, fpS, MatrizBinario, "100");
        } else if (!(strcmp(p, "sll"))) {
            TipoR(p, fpS, MatrizBinario, "001");
        } else if (!(strcmp(p, "addi"))) {
            TipoI(p, fpS, MatrizBinario, "000", "0010011");
        } else if (!(strcmp(p, "lw"))) {
            TipoILwSw(p, fpS, MatrizBinario, "010", "0000011");
        } else if (!(strcmp(p, "sw"))) {
            TipoILwSw(p, fpS, MatrizBinario, "010", "0100011");
        }
    }

    fclose(fp);
    fclose(fpS);

    return 0;
}
