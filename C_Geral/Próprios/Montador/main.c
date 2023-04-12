#include "funct.h"
int main(void){
    int aux;
    //controla a sequência de armazenamento dos registradores,ajuda na inicialização
    //da matriz
    char **MatrizBinario,conteudo[25],*nomeArquivo,*vetorArquivo,*p;
    //Armazenará o conteúdo em binário;
    //armazena o conteúdo do arquivo.
    //Recebe o conteúdo do arquivo
    //printf("\t\t||Digite o nome do arquivo: \n");
    //scanf("%s",&nomeArquivo);
    FILE *fp,*fpS;
    fp = fopen("entrada.asm","r");
    fpS = fopen("saida.asm","w");
    //Alocação Dinâmica da Matriz
    aux = contagem_linhas(fp);
    MatrizBinario = (char **)malloc(aux * sizeof(char *));
    //linhas
    for(int i = 0;i<5;i++){
        MatrizBinario[i] = (char*)malloc(sizeof(char)*3);
        //colunas
    }
    //
    aux = -1;
    //renicializa a variável aux
    while(fgets(conteudo,25,fp)){
        p = strtok(conteudo,", ");
            if(!(strcmp(p,"add"))){
                TipoR(p,fpS,MatrizBinario,vetorArquivo,"000");
            }else if(!(strcmp(p,"xor"))){
                TipoR(p,fpS,MatrizBinario,vetorArquivo,"100");

            }
            //aux = -1;
        
    }
    fclose(fp);
    fclose(fpS);
    return 0;
}
