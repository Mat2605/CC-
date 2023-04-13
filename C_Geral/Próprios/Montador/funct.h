#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void TipoR(char *p,FILE *fpS,char **MatrizBinario,char *vetorArquivo,char *funct3);
void TipoI(char *p,FILE *fpS,char **MatrizBinario,char *vetorArquivo,char *funct3,char *opcode);
char* remover_caractere(char *p);
char* Rs_converte(char *variavel);
char* Imediato_converte(char *variavel);
void TipoRpreencher_rd(char *vetor,char *vetor_binario);
void TipoRpreencher_rs1(char *vetor,char *vetor_binario);
void TipoRpreencher_rs2(char *vetor,char *vetor_binario);
int contagem_linhas(FILE *fp);