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

int Contagem(No *var){
    if(var==NULL){
        return 0;
    }else{
        return 1 + Contagem(var->dir) + Contagem(var->esq);
    }
}

int altura(No *var){
    if(var==NULL){
        return -1;
    }else{
        int left = altura(var->esq);
        int right = altura(var->dir);
        if(right>left){
            return right + 1;
        }else{
            return left + 1;
        }
    }
}

void inserir(No **var,int num){
    if((*var)==NULL){
        *var = (No*)malloc(sizeof(No));
        (*var)->dir = NULL;
        (*var)->esq = NULL;
        (*var)->conteudo = num;
    }else{
        if((*var)->conteudo<num){
            inserir(&((*var)->dir),num);
        }else{
            inserir(&((*var)->esq),num);
        }
    }
}

void Ordem(No *var){
    if(var!=NULL){
        Ordem(var->esq);
        printf("\tOrdem --> %d\n",var->conteudo);
        Ordem(var->dir);
    }
}

void OrdemDecrescente(No *var){
    if(var!=NULL){
        OrdemDecrescente(var->dir);
        printf("\tOrdem --> %d\n",var->conteudo);
        OrdemDecrescente(var->esq);
    }
}

/*void Largura(No *var){
    int num = altura(&var),count = -1;
    while(count!=num){

        if(count==-1){
            printf("%d\n",var->conteudo);
            count+=1;
        }else{
            if((var->esq!=NULL)&(var->dir!=NULL)){

            }
            printf("%d\n",var->esq);
            printf("%d\n",var->dir);
            var->esq = var->esq->esq;
        }   
    }
}*/

int main(void){

    No *ptr;
    inicializar_arvore(&ptr);
    inserir(&ptr,5);
    inserir(&ptr,3);
    inserir(&ptr,7);
    inserir(&ptr,2);
    inserir(&ptr,4);
    inserir(&ptr,1);
    inserir(&ptr,6);
    Ordem(ptr);
    OrdemDecrescente(ptr);
    printf("\tAltura ==> %d\n",altura(ptr));

    system("pause");
    return 0;
}