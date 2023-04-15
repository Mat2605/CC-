#include "funct.h"
//Converte o Imediato de instruções para binário,valores negativos e positivos
char* converteImediato(char *variavel){
    int decimal,rI,aux = 0, negativo = 0;
    char *vetor_binario;
    vetor_binario = (char*)malloc(sizeof(char)*12);
    //imediato será retornado com 12 bits
    decimal = atoi(variavel);

    if(decimal < 0) {
        // número é negativo, aplicar complemento de dois
        decimal = abs(decimal); // obtém o valor absoluto do número
        decimal = ~decimal + 1; // inverte todos os bits e adiciona 1
        negativo = 1;
    }

    for(int i = 11;i>=0;i--){
        rI = decimal>>i;
        if((rI&1)){
            vetor_binario[aux] = '1';
        }else{
            vetor_binario[aux] = '0';
        }
        aux+=1;
    }

    if(negativo) {
        // adiciona o bit de sinal (1 para negativo)
        vetor_binario[0] = '1';
    }
    vetor_binario[12] = '\0';
    return vetor_binario;
}
////////////////////////////////////////////////////////
char* remover_caractere(char *p){
    memmove(p,p+1,strlen(p));
    return p;
}
//Tira o 'x' dos registradores,restando apenas os números para conversão
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
    //número retornado é 5 bits
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
void escreve_saida(FILE* fpS, char** MatrizBinario, char* funct3, char* opcode) {
    fprintf(fpS, MatrizBinario[2]);
    fprintf(fpS, MatrizBinario[1]);
    fprintf(fpS, funct3);
    fprintf(fpS, MatrizBinario[0]);
    fprintf(fpS, opcode);
    fprintf(fpS, "\n");
}

void TipoR(char* p, FILE* fpS, char** MatrizBinario, char* funct3) {
    int aux = -1;
    while (p != NULL) {
        if (aux == -1) {
            fprintf(fpS, "0000000");
            //funct 7 Tipo R
        } else {
            p = remover_caractere(p);
            //elimina a primeira posição de p,no caso x
            char* valor = Rs_converte(p);
            if (aux == 0) {
                //armazena rd
                MatrizBinario[aux] = valor;
            } else if (aux == 1) {
                //armazena rs1
                MatrizBinario[aux] = valor;
            } else if (aux == 2) {
                //armazena rs2
                MatrizBinario[aux] = valor;
                escreve_saida(fpS, MatrizBinario, funct3, "0110011");
                return;
            }
        }
        aux += 1;
        p = strtok(NULL, " ,");
    }
}

void TipoI(char* p, FILE* fpS, char** MatrizBinario, char* funct3, char* opcode) {
    int aux = 0;
    p = strtok(NULL, " ,");
    //avança na string
    while (p != NULL) {
        if (aux == 0) {
            //recebe rd
            p = remover_caractere(p);
            MatrizBinario[aux] = Rs_converte(p);
        } else if (aux == 1) {
            //recebe rs1
            p = remover_caractere(p);
            MatrizBinario[aux] = Rs_converte(p);
        } else if (aux == 2) {
            //recebe imediato
            MatrizBinario[aux] = converteImediato(p);
            //printf("\tMatrizBinario[%d] ==> %s\n",aux,MatrizBinario[aux]);
            //printf("\tMatrizBinario[%d] ==> %s\n",aux-1,MatrizBinario[aux-1]);
            //printf("\tMatrizBinario[%d] ==> %s\n",aux-2,MatrizBinario[aux-2]);
            escreve_saida(fpS, MatrizBinario, funct3, opcode);
            return;
        }
        aux += 1;
        p = strtok(NULL, " ,");
    }
}
void TipoILwSw(char *p,FILE *fpS,char **MatrizBinario,char *funct3,char *opcode){
    int aux = 0;
    p = strtok(NULL," ,()");
    while(p!=NULL){
        if(aux==0){
            p = remover_caractere(p);
            MatrizBinario[aux] = Rs_converte(p);
        }else if(aux==1){
            MatrizBinario[aux+1] = converteImediato(p);
        }else if(aux==2){
    
            p = remover_caractere(p);
            MatrizBinario[aux-1] = Rs_converte(p);
           
            escreve_saida(fpS,MatrizBinario,funct3,opcode);
        }
        aux+=1;
        p = strtok(NULL," ,()");
    }
}