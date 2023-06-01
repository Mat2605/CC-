#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    FILE *fp;
    int line = 0;
    char conteudo[15];
    fp = fopen("entrada.asm","r");
    while(fgets(conteudo,line,fp)){
        line+=1;
    }
    
    fseek(fp,0,SEEK_SET);
    line = 0;
    char *p,*matriz_conteudo[line];
    while(fgets(conteudo,15,fp)){
        matriz_conteudo[line] = (char*)malloc(sizeof(conteudo));
        p = strtok(conteudo," ,.-!");
        strcpy(matriz_conteudo[line],p);
        while(p!=NULL){
            p = strtok(NULL," .;-!");
        }
        line+=1;
    }
    for(int i = 0;i<line;i++){

        printf("\t%s\n",matriz_conteudo[i]);

    }
    fclose(fp);
    return 0;
}