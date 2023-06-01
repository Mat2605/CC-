#include <stdio.h>
#include <stdlib.h>
int main(void){

    int num,*vetor_binario,*vetor_binario_2,count = 0,rI;
    float flutuante,decimal,num_fracionada,aux;

    vetor_binario = (int*)malloc(sizeof(int)*32);
    vetor_binario_2 = (int*)malloc(sizeof(int)*32);
  
    printf("Digite um numero decimal,na forma de ponto flutuante: ");
    printf("\nPor Exemplo,caso queira saber o valor de 10 na base 2,digite 10.0;\n");
    scanf("%f", &flutuante);

    num = (int)flutuante;
    decimal = flutuante - num;
  
    for(int i = 31; i >= 0; i--) {
        rI = num >> i;
    if((rI & 1)) {
        vetor_binario[31-i] = 1;
    } else {
        vetor_binario[31-i] = 0;
    }}

    while(1){
        decimal = decimal*2;
        vetor_binario_2[count] = (int)decimal;
        if(decimal>1)
            decimal-=1;
        aux = decimal - vetor_binario_2[count];
        count+=1;
        if(aux==0)
            break;
    }

    for(int i = (count);i<32;i++){
        vetor_binario_2[i] = 0;
    }

    printf("\n");
    printf("Valor digitado na Base 2: \n");
    printf("Parte Inteira: \n");
    for(int i = 0;i<32;i++){
        printf("%d",vetor_binario[i]);
    }
    printf("\nParte Inteira: \n");
    for(int i = 0;i<32;i++){
        printf("%d",vetor_binario_2[i]);
    }

    printf("\n");
    system("pause");
    return 0;
}