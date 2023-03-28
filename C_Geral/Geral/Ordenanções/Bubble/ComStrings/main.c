#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){

    char aux[15];
    char strings[5][10] = {"D","A","S","Z","G"};

    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            if((strcmp(strings[j],strings[j+1]))>0){
                strcpy(aux,strings[j+1]);
                strcpy(strings[j+1],strings[j]);
                strcpy(strings[j],aux);
            }
        }
    }
    for(int i = 0;i<5;i++){
        printf("\t%s\n",strings[i]);
    }

    system("PAUSE");
    return 0;

}