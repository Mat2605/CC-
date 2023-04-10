#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    int j;
    char aux[15];
    char strings[5][10] = {"Dedos","Aves","Sal","Zebra","Galo"};
    for(int i =1;i<5;i++){
        strcpy(aux,strings[i]);
        j = i -1;
        while((j>=0)&&(((strcmp(aux,strings[j]))<0))){
            strcpy(strings[j+1],strings[j]);
            j--;
        }
        strcpy(strings[j+1],aux);
    }
    for(int i = 0;i<5;i++){
        printf("\t%s\n",strings[i]);
    }

    return 0;
}