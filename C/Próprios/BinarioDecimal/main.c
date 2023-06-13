#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void){
    char c[64];
    int *vetor_decimal,*vetor_decimal_2,count = 31;
    long int num;
    float inteiro= 0.0,decimal = 0.0;
    /////////////////////////////////////////////
    vetor_decimal = (int*)malloc(sizeof(int)*32);
    vetor_decimal_2 = (int*)malloc(sizeof(int)*32);
    /////////////////////////////////////////////

    printf("\t|Digite o número em binário,formato 64 bits|:");
    printf("\t32 representando a parte inteira e 32 a parte decimal!\n");
    scanf("%s",&c);

    for(int i = 0;i<32;i++){

        vetor_decimal[count] = ((int)c[i])-48;
        inteiro += vetor_decimal[count]*(pow(2,count));
        count-=1;

    }
    //printf("\tInteiro==>%f\n",inteiro);
    printf("\n");
    count = 0;
    for(int i = 32;i<64;i++){
        vetor_decimal_2[count] = ((int)c[i])-48;
        decimal += vetor_decimal_2[count]/(pow(2,count+1));
        count+=1;
    }
    //printf("\tDecimal==>%f\n",decimal);
    printf("\n");

    printf("\tBinário Digitado na Base 10: %f\n",decimal+inteiro);
    return 0;
}