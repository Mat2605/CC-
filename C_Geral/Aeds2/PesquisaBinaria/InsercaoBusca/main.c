#include <stdio.h>
#include <stdlib.h>

typedef struct No{

    int conteudo;
    struct No *esq;
    struct No *dir;
        
}No;

void inicializar_arvore(No **var){
    *var = NULL;

}

//alocação,menores valores que o nó serão alocados na esquerda,maiores a direita;
void inserir(No **var,int valor){
    if((*var)==NULL){
        *var = (No*)malloc(sizeof(No));
        (*var)->dir = NULL;
        (*var)->esq = NULL;
        (*var)->conteudo = valor;
    }else{
        if((*var)->conteudo>valor){
            inserir(&((*var)->esq),valor);

        }else if((*var)->conteudo<valor){

            inserir(&((*var)->dir),valor);

        }
    }

}

int contador_componentes(No *var){
    if(var==NULL){
        return 0;
    }else{
        return 1+contador_componentes(var->dir) + contador_componentes(var->esq);
    }
}
////////////////////////
void PreOrdem(No *var){
    if(var!=NULL){

        printf("\tPre Ordem --> %d\n",var->conteudo);
        PreOrdem(var->esq);
        PreOrdem(var->dir);

    }
}
///////////////////////////
void Ordem(No *var){
    if(var!=NULL){
        Ordem(var->esq);
        printf("\tOrdem --> %d\n",var->conteudo);
        Ordem(var->dir);
    }
}
///////////////////////////
void PosOrdem(No *var){
    if(var!=NULL){
        PosOrdem(var->esq);
        PosOrdem(var->dir);
        printf("\tPos Ordem --> %d\n",var->conteudo);
    }
}


int main(void){

    No *value;
    inicializar_arvore(&value);
    inserir(&value,100);
    inserir(&value,101);
    inserir(&value,90);
    inserir(&value,91);
    inserir(&value,98);
    PreOrdem(value);
    Ordem(value);
    PosOrdem(value);
    system("PAUSE");
    return 0;
}