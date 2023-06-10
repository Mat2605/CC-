#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


int CondicaoDeExistencia(FILE **ptr);
int ContagemLinhas(FILE **ptr,int *linhas);
void LimparPontuacao(char* palavra);
void partition(int esq,int dir,int *i,int *j,char **var);
void quicksort(int inicio,int tamanho,char **ConteudoArquivo);
void QuickSortForStrings(char **ConteudoArquivo, int tamanho);
int CaracterePorCaractere(FILE **ptr,char** ConteudoArquivo);
int LerPorBuffer(FILE **ptr,char** ConteudoArquivo);
int LerPorToken(FILE **ptr, char** ConteudoArquivo);