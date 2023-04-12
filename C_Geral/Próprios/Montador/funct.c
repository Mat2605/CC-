#include "funct.h"
char* remover_caractere(char *p){
    memmove(p,p+1,strlen(p));
    return p;
}
int contagem_linhas(FILE *fp){
    char contagem;
    int linhas = 1;
    while((contagem=fgetc(fp))!=EOF){
        if(contagem=='\n'){
            linhas +=1;
        }
    }
    fseek(fp,0,SEEK_SET);
    return linhas;
}
char* Rs_converte(char *variavel){
    //Para Tipo R
    //essa função será responsável para converter os valores para binário de rs1,rd,rs2;
    int decimal,rI,aux = 0;
    char *vetor_binario;
    vetor_binario = (char*)malloc(sizeof(char)*5);
    //o parâmetro terá formato de um registor,ou seja,x3,a posição [1] da string
    //será o valor para ser convertido para binário.
    decimal = atoi(variavel);
    
    for(int i = 4; i >= 0; i--) {
        rI =  decimal>>i;
    if((rI & 1)) {
        vetor_binario[aux] = '1';
    } else {
        vetor_binario[aux] = '0';
    }aux+=1;
    }
    return vetor_binario;
}
void  TipoRpreencher_rd(char *vetor,char *vetor_binario){
    int contador = 0;
    //vai de 1 até 5
    for(int i = 7;i<=11;i++){
        vetor[i] = vetor_binario[contador];
        contador+=1;
    }
}
void TipoRpreencher_rs1(char *vetor,char *vetor_binario){
    int contador = 0;
    //vai de 1 até 5
    for(int i = 15;i<=19;i++){
        vetor[i] = vetor_binario[contador];
        contador+=1;
    }

}
void TipoRpreencher_rs2(char *vetor,char *vetor_binario){
    int contador = 0;
    //vai de 1 até 5
    for(int i = 19;i<=24;i++){
        vetor[i] = vetor_binario[contador];
        contador+=1;
    }
}
void TipoR(char *p,FILE *fpS,char **MatrizBinario,char *vetorArquivo,char *funct3){
    int aux =-1;
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
}