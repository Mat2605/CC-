#include "C:\Users\mathe\Documents\CC++\C\Proprios\ArquivosDefinitivo\.h\Funct.h"

int CondicaoDeExistencia(FILE **ptr){
    *ptr = fopen("C:\\Users\\mathe\\Documents\\CC++\\C\\Proprios\\ArquivosDefinitivo\\ArquivosDeTexto\\File01.txt", "r");
    if (*ptr == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }else{
        printf("Arquivo Encontrado!\n");
        return 0;
    }
}
int ContagemLinhas(FILE **ptr,int *linhas){
    char caractere_aux;
    (*linhas) = 1;
    if(CondicaoDeExistencia(ptr)==1){
        return 0;
    }else{
        caractere_aux = fgetc(*ptr);
        while(caractere_aux!=EOF){
            caractere_aux = fgetc(*ptr);
            if(caractere_aux=='\n'){
                (*linhas)+=1;
            }
        }
    }
    fseek(*ptr,0,SEEK_SET);
    return *linhas;
}
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
int CaracterePorCaractere(FILE **ptr,char** ConteudoArquivo){
    //Arquivo sem sinais de pontuação funciona normalmente, não é bom em toda situação.
    //Alguns "Espaços" sobram e são armazenados como palavras,Formatando o arquivo para ter apenas um linha funciona.
    int auxWord = 0,auxLinhas = 0,tamanho = 0;
    char caractere_aux,AuxConteudo[216][216];
    caractere_aux = fgetc(*ptr);
    while(caractere_aux!=EOF){
        if(caractere_aux==' '|caractere_aux=='\n'){
            LimparPontuacao(AuxConteudo[auxLinhas]);
            tamanho = strlen(AuxConteudo[auxLinhas]);
            ConteudoArquivo[auxLinhas] = (char*)malloc((tamanho + 1) * sizeof(char));
            strcpy(ConteudoArquivo[auxLinhas],AuxConteudo[auxLinhas]);
            auxWord = 0;
            auxLinhas +=1;
        }else{
                AuxConteudo[auxLinhas][auxWord] = caractere_aux;
                auxWord+=1;        
        }
        caractere_aux = fgetc(*ptr);
    }
    //for (int i = 0; i < auxLinhas; i++) {
        //printf("\n[%d]==:%s",i,ConteudoArquivo[i]);
    //}
    printf("\n");
    return auxLinhas;
    fseek(*ptr,0,SEEK_SET);
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
    fseek(*ptr,0,SEEK_SET);
    return linha;
}


int LerPorToken(FILE **ptr, char** ConteudoArquivo) {
    int linha = 0;
    char palavra[50];
    
    
    while (fscanf(*ptr, "%49s", palavra) == 1) {
        ConteudoArquivo[linha] = (char*) malloc((strlen(palavra) + 1) * sizeof(char));
        if (ConteudoArquivo[linha] == NULL) {
            printf("Erro ao alocar memória.\n");
            return linha;
        }
        strcpy(ConteudoArquivo[linha], palavra);
        linha++;
    }
    
    for (int i = 0; i < linha; i++) {
        printf("[%d] ==> %s\n", i, ConteudoArquivo[i]);
    }
    
    fseek(*ptr, 0, SEEK_SET);
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


