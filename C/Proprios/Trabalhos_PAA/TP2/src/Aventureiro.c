#include "../Headers/Aventureiro.h"

void InicializarAventureiro(MatrizMapa *ptrMapa,Aventureiro *ptrAv){
    //Inicia com os pontos de vida lidos no arquivo
    ptrAv->PontosVidaAtual = ptrMapa->VidaJogador;
    //Inicializa a tabela,armazenará os pontos de vida do jogador durante o percurso
    ptrAv->TabelaPD = (int**)malloc(ptrMapa->LinhasMapa * sizeof(int*));
    for(int i = 0;i<ptrMapa->LinhasFinal;i++){
        ptrAv->TabelaPD[i] = (int*)malloc(ptrMapa->ColunasMapa * sizeof(int));
    }
    //A tabela será inicializado com 0 em todas as posições, apenas a posição inicial será diferente
    // Terá os pontos de vida iniciais

    for(int i = 0;i<ptrMapa->LinhasMapa;i++){
        for(int j = 0;j<ptrMapa->ColunasMapa;j++){
            if(i==ptrMapa->LinhasInicial && j==ptrMapa->ColunasInicial){
                ptrAv->TabelaPD[i][j] = ptrMapa->VidaJogador;
            }else{
                ptrAv->TabelaPD[i][j] = 0;
            }
        }
    }
}

void IniciarDeslocamento(MatrizMapa *ptr,Aventureiro *ptrAv,PilhaCoordenadas *PtrCoordenadas,PilhaRamificado *PtrRamificado,FilaPilhas *Filas){
    InicializarAventureiro(ptr,ptrAv);
    initialize(PtrCoordenadas);
    inicializarRamificacao(PtrRamificado);
    initializeFilaPilhas(Filas);
    Deslocar(ptr,ptrAv,PtrCoordenadas,PtrRamificado,Filas);
}

int Deslocar(MatrizMapa *ptr,Aventureiro *ptrAv,PilhaCoordenadas *PtrCoordenadas,PilhaRamificado *PtrRamificado,FilaPilhas *Filas){
    do{

        if(estaVazioRamificacao(PtrRamificado) && isEmptyFilaPilhas(Filas)==0){
            return 1;
        }
    } while (estaVazioRamificacao(PtrRamificado)!=1);
    printf("!\n");
    return 0;
}
