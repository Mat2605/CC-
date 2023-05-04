#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funct.h"

//Ler as especificações

int main(void) {
    char **MatrizBinario, conteudo[25], *nomeArquivo, *p;
    FILE *fp, *fpS;
    int resposta, aux, opcao;
    // processa as instruções
    opcao = OpcaoLeitura(&fp,&fpS);
    aux = contagem_linhas(fp);
    MatrizBinario = (char **)malloc(aux * sizeof(char *));
    for(int i = 0; i < aux; i++) {
        MatrizBinario[i] = (char*)malloc(sizeof(char)*3);
    }

    while (fgets(conteudo, 25, fp ? fp : stdin)) {
        p = strtok(conteudo, ", ");

        if (!(strcmp(p, "add"))) {
            TipoR(p, fpS, MatrizBinario, "000","0000000","0110011");
        } else if(!(strcmp(p, "and"))){
            TipoR(p, fpS, MatrizBinario, "111","0000000","0110011");
        }else if(!(strcmp(p, "sub"))){
            TipoR(p, fpS, MatrizBinario, "000","0100000","0110011");
        }else if (!(strcmp(p, "xor"))) {
            TipoR(p, fpS, MatrizBinario, "100","0000000","0110011");
        }else if(!(strcmp(p, "or"))){
            TipoR(p, fpS, MatrizBinario, "110","0000000","0110011");
        }else if (!(strcmp(p, "sll"))) {
            TipoR(p, fpS, MatrizBinario, "001","0000000","0110011");
        }else if(!(strcmp(p, "srl"))){
            TipoR(p, fpS, MatrizBinario, "101","0000000","0110011");
        } else if (!(strcmp(p, "addi"))) {
            TipoI(p, fpS, MatrizBinario, "000", "0010011");
        }else if(!(strcmp(p, "andi"))){
            TipoI(p, fpS, MatrizBinario, "111", "0010011");
        }else if(!(strcmp(p, "ori"))){
            TipoI(p, fpS, MatrizBinario, "110", "0010011");
        } else if (!(strcmp(p, "lw"))) {
            TipoILw(p, fpS, MatrizBinario, "010", "0000011");
        }else if(!(strcmp(p, "lb"))){
            TipoILw(p, fpS, MatrizBinario, "000", "0000011");
        }else if(!(strcmp(p, "lh"))){
            TipoILw(p, fpS, MatrizBinario, "001", "0000011");
        }else if (!(strcmp(p, "sw"))) {
            TipoISw(p, fpS, MatrizBinario, "010", "0100011");
        }else if(!(strcmp(p, "sb"))){
            TipoISw(p, fpS, MatrizBinario, "000", "0100011");
        }else if(!(strcmp(p, "sh"))){
            TipoISw(p, fpS, MatrizBinario, "010,", "0100011");
        }else if(!(strcmp(p,"bne"))){
            TipoB(p,fpS,MatrizBinario,"001","1100011");
        }else if(!(strcmp(p,"beq"))){
            TipoB(p,fpS,MatrizBinario,"000","1100011");

        }
    }

    fclose(fp);
    fclose(fpS);
    if(opcao==1){
        PrintarArquivo("saida.bin");
    }

    return 0;
}