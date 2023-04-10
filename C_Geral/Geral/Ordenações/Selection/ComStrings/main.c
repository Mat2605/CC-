#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    char aux[15];
    char strings[5][10] = {"D","A","S","Z","G"};
    int min;
    for(int i =0;i<5-1;i++){
        min = i;
        for(int j = i+1;j<5;j++){
            if(strcmp(strings[j],strings[min])<0){
                min = j;
            }
        }
        strcpy(aux,strings[min]);
        strcpy(strings[min],strings[i]);
        strcpy(strings[i],aux);
    }

    for(int i = 0;i<5;i++){
        printf("\t%s\n",strings[i]);
    }

    return 0;
}