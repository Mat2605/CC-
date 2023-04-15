#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void TipoR(char *p,FILE *fpS,char **MatrizBinario,char *funct3);
void TipoI(char *p,FILE *fpS,char **MatrizBinario,char *funct3,char *opcode);
void TipoILwSw(char *p,FILE *fpS,char **MatrizBinario,char *funct3,char *opcode);
void escreve_saida(FILE* fpS, char** MatrizBinario, char* funct3, char* opcode);
char* remover_caractere(char *p);
char* Rs_converte(char *variavel);
char* converteImediato(char *variavel);
int contagem_linhas(FILE *fp);