#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
void LimparPontuacao(char* palavra) {
    int i, j = 0;
    for (i = 0; palavra[i] != '\0'; i++) {
        if (isalpha(palavra[i]) || palavra[i] == '\0') {
            //se o char é um caractere
            palavra[j++] = palavra[i];
    
        }
    }
    palavra[j] = '\0';
}
int CondicaoDeExistencia(FILE **ptr){
    *ptr = fopen("File02.txt", "r");
    if (*ptr == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }else{
        printf("Arquivo Encontrado!\n");
        return 0;
    }
}
int LerPorBuffer(FILE** ptr, char** ConteudoArquivo) {
    char buffer[100];
    int linha = 0;

    while (fgets(buffer, 100, *ptr) != NULL) {
        char* palavra = strtok(buffer, " \t\n");
        while (palavra != NULL) {
            LimparPontuacao(palavra);
            int tamanho = strlen(palavra);
            if (tamanho > 0) {
                ConteudoArquivo[linha] = (char*)malloc((tamanho + 1) * sizeof(char));
                strcpy(ConteudoArquivo[linha], palavra);
                linha++;
            }
            palavra = strtok(NULL, " \t\n");
        }
    }
    return linha;
}
void partition(int esq, int dir, int *i, int *j, char **var) {
    *i = esq;
    *j = dir;
    char *pivo = (char*) malloc((strlen(var[((*i + *j) / 2)]) + 1) * sizeof(char));
    strcpy(pivo, var[((*i + *j) / 2)]);
    do {
        while (strcmp(pivo, var[*i]) > 0)
            (*i)++;
        while (strcmp(var[*j], pivo) > 0)
            (*j)--;

        if (*i <= *j) {
            char *aux = (char*) malloc((strlen(var[*i]) + 1) * sizeof(char));
            strcpy(aux, var[*i]);
            strcpy(var[*i], var[*j]);
            strcpy(var[*j], aux);
            (*i)++;
            (*j)--;
            free(aux);
        }
    } while (*i <= *j);
    free(pivo);
}

void quicksort(int inicio, int tamanho, char **ConteudoArquivo) {
    int i, j;
    partition(inicio, tamanho, &i, &j, ConteudoArquivo);
    if (inicio < j) {
        quicksort(inicio, j, ConteudoArquivo);
    }
    if (i < tamanho) {
        quicksort(i, tamanho, ConteudoArquivo);
    }
}

void QuickSortForStrings(char **ConteudoArquivo, int tamanho) {
    quicksort(0, tamanho - 1, ConteudoArquivo);
}
int main(void){
    char *ConteudoArquivo[216];
    FILE *ptrFile;
    int tamanho;
    CondicaoDeExistencia(&ptrFile);
    tamanho = LerPorBuffer(&ptrFile,ConteudoArquivo);
    QuickSortForStrings(ConteudoArquivo,tamanho);
    for(int i = 0;i<tamanho;i++){
        printf("[%d]==:%s\n", i, ConteudoArquivo[i]);
    }
    return 0;
}