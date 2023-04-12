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
                while(p!=NULL){
                    if(aux==-1){
                        fprintf(fpS,"0000000");
                        //funct 7 Tipo R
                    }else{
                        p = remover_caractere(p);
                        //elimina a primeira posição de p,no caso x
                        if(aux==0){
                            vetorArquivo = Rs_converte(p);
                            MatrizBinario[aux] = vetorArquivo;
                            //printf("\t%s\n",MatrizBinario[aux]);
                            //armazena rd
                        }else if(aux==1){
                            vetorArquivo = Rs_converte(p);
                            MatrizBinario[aux] = vetorArquivo;
                            //armazena rs1
                        }else if(aux==2){
                            vetorArquivo = Rs_converte(p);
                            MatrizBinario[aux] = vetorArquivo;
                            //armazena rs2
                            fprintf(fpS,MatrizBinario[aux]);
                            fprintf(fpS,MatrizBinario[aux-1]);
                            fprintf(fpS,"000");
                            fprintf(fpS,MatrizBinario[aux-2]);
                            fprintf(fpS,"0110011\n");
                        }
                    }

                    aux+=1;
                    p = strtok(NULL," ,");

                }

                

            }else if(!(strcmp(p,"xor"))){
                while(p!=NULL){
                    if(aux==-1){
                        fprintf(fpS,"0000000");
                        //funct 7 Tipo R ADD

                    }else{
                        p = remover_caractere(p);
                        //elimina a primeira posição de p,no caso x
                        if(aux==0){
                            vetorArquivo = Rs_converte(p);
                            MatrizBinario[aux] = vetorArquivo;
                            //printf("\t%s\n",MatrizBinario[aux]);
                            //armazena rd
                        }else if(aux==1){
                            vetorArquivo = Rs_converte(p);
                            MatrizBinario[aux] = vetorArquivo;
                            //armazena rs1
                        }else if(aux==2){
                            vetorArquivo = Rs_converte(p);
                            MatrizBinario[aux] = vetorArquivo;
                            //armazena rs2
                            fprintf(fpS,MatrizBinario[aux]);
                            fprintf(fpS,MatrizBinario[aux-1]);
                            fprintf(fpS,"100");
                            fprintf(fpS,MatrizBinario[aux-2]);
                            fprintf(fpS,"0110011\n");
                        }

                    }
                    aux+=1;
                    p = strtok(NULL," ,");
                }

            }
            aux = -1;
        
    }
    fclose(fp);
    fclose(fpS);
    return 0;
}
