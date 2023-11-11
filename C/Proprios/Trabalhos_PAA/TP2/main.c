#include "Headers/Aventureiro.h"

int main(){
    MatrizMapa ptr;
    LeituraMatriz("..\\TP2\\MapasExemplo\\caverna1.txt",&ptr);
    PilhaCoordenadas PtrCoordenadas;
    Fila filas;
    Aventureiro ptrAv;
    IniciarDeslocamento(&ptr,&ptrAv,&PtrCoordenadas,&filas);
    return 0;
}