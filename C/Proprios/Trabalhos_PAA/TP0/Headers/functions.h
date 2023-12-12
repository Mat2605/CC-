#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COLUMN 80
#define LINE 20

void initialize_matriz(char matriz[LINE][COLUMN]);
void CopiarMatriz(char matriz[LINE][COLUMN],char matrizDemo[LINE][COLUMN]);
void CompararMatriz(char matriz[LINE][COLUMN],char matrizDemo[LINE][COLUMN]);

int Menu(char matriz[LINE][COLUMN],char matrizDemo[LINE][COLUMN]);

int VerificarEspacoPonto(int plus_line,int plus_column,char matriz[LINE][COLUMN]);
int VerificarEspacoSimboloMais(int plus_line,int plus_column,char matriz[LINE][COLUMN]);
int VerificarEspacoSimboloX(int plus_line,int plus_column,char matriz[LINE][COLUMN]);
int VerificarEspacoEstrela(int plus_line,int plus_column,char matriz[LINE][COLUMN]);

void DesenharPonto(int EntradaUsuario,char matriz[LINE][COLUMN]);
void DesenharSimboloMais(int EntradaUsuario,char matriz[LINE][COLUMN]);
void DesenharX(int EntradaUsuario,char matriz[LINE][COLUMN]);
void DesenharRandomicamente(int NumeroPontos,int NumeroSomas,int NumeroX,char matriz[LINE][COLUMN]);
void DesenharEstrela(int EntradaUsuario,char matriz[LINE][COLUMN]);

void Print_Matriz(char matriz[LINE][COLUMN]);