#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct No{

    int c;
    struct No *esq;
    struct No *dir;

}No;

void inicializar(No **var){
    (*var) = NULL;
}
void inserir(No **var,int c){
    if((*var)==NULL){

        *var = (No*)malloc(sizeof(No));
        (*var)->dir = NULL;
        (*var)->esq = NULL;
        (*var)->c = c;

    }else{
        if((*var)->c<c){
            inserir(&((*var)->dir),c);
        }else if((*var)->c>c){
            inserir(&((*var)->esq),c);
        }
    }
}
int contador(No *var){
    if(var==NULL){
        return 0;
    }else{
        return 1 + contador(var->dir)+contador(var->esq);
    }
}
No* retirar(No *var,int c){
    if(var==NULL){
        printf("\tárvore vazia!\n");
        return NULL;
    }else{
        if(var->c==c){
            if(var->esq==NULL && var->dir==NULL){
                free(var);
                printf("Elemento removido!\n");
                return NULL;

            }else{
                if(var->esq!=NULL && var->dir!=NULL){
                    No *aux = var->esq;
                    while(aux->dir!=NULL){
                        aux = aux->dir;
                    }
                    var->c = aux->c;
                    aux->c = c;
                    return var;

                    }else{
                        No *aux;
                        if(var->esq!=NULL){
                        aux = var->esq;
                    }else{
                        aux = var->dir;
                        
                    }
                    free(var);
                    return aux;
                    }
            }
        }else{
            if(var->c>c){
                var->esq = retirar(var->esq,c);
            }else if(var->c<c){
                var->dir = retirar(var->dir,c);
                
            }
        }

    }


}
void Ordem(No *var){
    if(var!=NULL){
        Ordem(var->esq);
        printf("Número : %d\n",var->c);
        Ordem(var->dir);
    }
}
int Busca(No *var,int c){
    while(var!=NULL){
        if(var->c==c){
            return 1;
        }else if(var->c>c){
            var = var->esq;
        }else{
            var = var->dir;
        }
    }
    return -1;
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
int profundidade(No *var,int c){
    if (var== NULL) {
        return -1;  // key not found
    }
    if (var->c == c) {
        return 0;  // key found at root
    } else if (var->c > c) {
        int left_depth = profundidade(var->esq, c);
        return (left_depth == -1) ? -1 : left_depth + 1;
    } else {
        int right_depth = profundidade(var->dir, c);
        return (right_depth == -1) ? -1 : right_depth + 1;
    }
    
}

int Maior_Valor(No *var){
    if(var==NULL){
        printf("\tÁrvore Vazia!\n");
    }else{

        while(var->dir!=NULL){
            var = var->dir;
        }

    }
    return var->c;
    }

int main(void){
    No *ptr;
    inicializar(&ptr);
    inserir(&ptr,100);
    inserir(&ptr,101);
    inserir(&ptr,90);
    inserir(&ptr,91);
    inserir(&ptr,98);
    Ordem(ptr);
    printf("\tMaior Valor : %d",Maior_Valor(ptr));
    printf("\tProfundidade: %d\n",profundidade(ptr,91));
    printf("\tBusca : %d\n",Busca(ptr,91));
    return 0;
}