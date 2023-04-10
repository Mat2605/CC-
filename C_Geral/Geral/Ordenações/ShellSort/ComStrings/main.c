#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){

    char aux[15];
    char strings[8][10] = {"F","S","B","L","K","I","U","O"};
    int j,h = 1;
    do h = h*3 + 1;while(h<8);
    do{
        h = h/3;
        for(int i = h;i<8;i++){
            strcpy(aux,strings[i]);
            j = i;
            while(((strcmp(strings[j-h],aux))>0)){
                strcpy(strings[j],strings[j-h]);
                j -=h;
                if(j<h){
                    break;
                }
            }
            strcpy(strings[j],aux);
        }
    }while(h!=1);
    for(int i = 0;i<8;i++){
        printf("\t%s\n",strings[i]);
    }

    return 0;
}