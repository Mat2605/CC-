#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct No
{
    int matricula;
    char nome[12];
    struct No *esq,*dir;
}No;

void iniciar(No **var){
    (*var) = NULL;
}
void inserir(No **var,int conteudo,char *nome){
    if((*var) == NULL){
        *var = (No*)malloc(sizeof(No));
        (*var)->dir = NULL;
        (*var)->esq = NULL;
        (*var)->matricula = conteudo;
        strcpy((*var)->nome,nome);
    }else{
        if((*var)->matricula>conteudo){
            inserir(&((*var)->esq),conteudo,nome);
        }else if((*var)->matricula<conteudo){
            inserir(&((*var)->dir),conteudo,nome);
        
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
void Ordem(No *var){
    if(var!=NULL){
        Ordem(var->esq);
        printf("matricula : %d Nome: %s\n",var->matricula,var->nome);
        Ordem(var->dir);
    }
}
//Possível remover uma folha,um nó com 1 ou dos filhos;
No* remover(No *var,int num){
    if(var==NULL){
        printf("Árvore Vazia!\n");
        return NULL;
    }else{
        if(var->matricula==num){
            //procurar o nó para remover,folha isolada
            if(var->esq==NULL && var->dir==NULL){
                free(var);
                printf("Elemento removido!\n");
                return NULL;
            }else{
                //o ponteiro do nó filho deve apontar para o avó agora;
                if(var->esq!=NULL && var->dir!=NULL){

                    //nó com dois filhos;
                    //o nó que será removido,tem um ponteiro pai,sendo apontado para o mesmo, e dois ponteiros pra filhos;
                    //escolher qual subárvore percorrer,pegar o maior número na esquerda ou o menor na direita,manter a estrutura geral da árvore;
                    No *aux = var->esq;
                    while(aux->dir!=NULL){
                        aux = aux->dir;
                    }
                    var->matricula = aux->matricula;
                    strcpy(var->nome,aux->nome);
                    aux->matricula = num;//alocar o conteudo a ser eliminado
                    var->esq = remover(var->esq,num);
                    return var;

                }else{
                    No *aux;
                    if(var->esq!=NULL){
                        aux = var->esq;
                    }else{
                        aux = var->dir;
                        //transferir o filho do nó que será removido
                    }
                    free(var);
                    return aux;//volta para var->esq ou var->dir;
                }

            }
        }else{
            if(var->matricula>num){

                var->esq = remover(var->esq,num);

            }else if(var->matricula<num){

                var->dir = remover(var->dir,num);

            }
        }
   
    }
}
/*
Se a árvore estiver vazia ==  volta Nulo;
Se o elemento procurado for menor que a chave atual,chamar a função recursivamente a esquerda;
Se o elemento procurado for maior que a chave atual,chamar a função recursivamente a direita;
Se o nó direito for nulo e o esquerdo for diferente de nulo,o nó removido será substituido pelo seu esquerdo;
Se o nó esquerdo for nulo e o direito for diferente de nulo,o nó removido será substituido pelo seu direito;
O nó a ser removido é substituido pelo seu antecessor
A remoção sempre deve substituir o item removido com outro que mantenha a estrutura da árvore;
*/
int main(void){

    No *ptr;
    iniciar(&ptr);
    inserir(&ptr,4664,"Matheus");
    inserir(&ptr,4668,"Marcela");
    inserir(&ptr,4663,"MC");
    inserir(&ptr,4661,"Rafa");
    inserir(&ptr,4662,"Dc");
    inserir(&ptr,4665,"B");
    remover(ptr,4663);
    Ordem(ptr);

    return 0;
}
