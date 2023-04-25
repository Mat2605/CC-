#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No_Aluno
{
    int nota,matricula;
    char nome[30];
    struct No_Aluno *dir;
    struct No_Aluno *esq;
    

}No_Aluno;

void inicia_arvore(No_Aluno **var){
    *var = NULL;
}
void inserir_arvore(No_Aluno **var,int n,int mat,char *string){
    if(*var==NULL){
        *var = (No_Aluno*)malloc(sizeof(No_Aluno));
        (*var)->matricula = mat;
        strcpy((*var)->nome,string);
        (*var)->nota = n;
        (*var)->esq = NULL;
        (*var)->dir = NULL;
    }else{
        if((*var)->nota>n){
            inserir_arvore(&((*var)->esq),n,mat,string);

        }else if((*var)->nota<n){
            inserir_arvore(&((*var)->dir),n,mat,string);

        }
    }
}
int numero_Alunos(No_Aluno *var){
    if(var==NULL){
        return 0;
    }else{
        return 1 + numero_Alunos(var->dir) + numero_Alunos(var->esq);
    }
}
int menor_nota(No_Aluno *var){
    int menor;
    while(var!=NULL){
        menor = var->nota;
        var = var->esq;
    }
    return menor;
}
int maior_nota(No_Aluno *var){
    int maior;
    while(var!=NULL){
        maior = var->nota;
        var = var->dir;
    }
    return maior;
}
void Ordem_Decrescente(No_Aluno *var){
    if(var == NULL){
        return;
    }
    
    Ordem_Decrescente(var->dir);
    printf("\tNota -->%d|Nome --> %s|Matrícula --> %d\n",var->nota,var->nome,var->matricula);
    Ordem_Decrescente(var->esq);
}

int soma_arvore(No_Aluno *var) {
    if (var == NULL) {
        return 0;
    } else {
        int soma_esq = soma_arvore(var->esq);
        int soma_dir = soma_arvore(var->dir);
        return var->nota + soma_esq + soma_dir;
    }
}
int calcular_media(No_Aluno *var) {
    int total_alunos = numero_Alunos(var);
    int soma = soma_arvore(var);
    return (int)soma/total_alunos;
}
void inicializa_contador(int *count){

    (*count) = 0;
}
int alunosmedia(No_Aluno *var, int media) {
    if (var == NULL) {
        return 0;
    }
    int qtd_esq = alunosmedia(var->esq, media);
    int qtd_dir = alunosmedia(var->dir, media);
    if (var->nota >= media) {
        return 1 + qtd_esq + qtd_dir;
    } else {
        return qtd_esq + qtd_dir;
    }
}




int main(void){
    No_Aluno *no;
    inicia_arvore(&no);
    char conteudo[50],*p,caracteres[30];
    int contador = 0,nn,mat,count = 0;
    FILE *fp;
    fp = fopen("entrada.txt","r");
    while(fgets(conteudo,50,fp)){
        p = strtok(conteudo," ,.-;");
        while(p!=NULL){
            if(contador==0){
                strcpy(caracteres,p);
    
            }else if(contador==1){
                mat = atoi(p);
            }else{
                nn = atoi(p);

            }
            contador+=1;
            p = strtok(NULL," ,.-;");

        }
        contador = 0;
        inserir_arvore(&no,nn,mat,caracteres);
    }
    Ordem_Decrescente(no);
    printf("\tMaior Nota ==> %d\n",maior_nota(no));
    printf("\tMenor Nota ==> %d\n",menor_nota(no));
    printf("\tTotal de Alunos ==> %d\n",numero_Alunos(no));
    printf("\tMédia ==> %d\n",calcular_media(no));
    printf("\tAlunos Acima ou na Média ==> %d\n",alunosmedia(no,calcular_media(no)));
    return 0;
}