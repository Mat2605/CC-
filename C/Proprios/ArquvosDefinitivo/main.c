#include "Funct.h"
//ESSE PROJETO SERÁ PARA CONSEGUIR MANIPULAR UM ARQUIVO COM VÁRIOS TIPOS DE OPERAÇÕES
//FACILITAR PARA PROJETOS FUTUROS COM ESSE TIPO DE ABORDAGEM
//¯|_(ツ)_/¯
int main(void) {
    clock_t inicio, fim;
    double tempo_gasto;
    char *ConteudoArquivo[216];
    char *Ordena[216];
    FILE *ptrFile;
    unsigned int Linhas,tamanho;
    inicio = clock();
    CondicaoDeExistencia(&ptrFile);
    //tamanho = LerPorBuffer(&ptrFile,ConteudoArquivo);
    //for (int i = 0; i <tamanho; i++) {
      //  printf("[%d]==:%s\n", i, ConteudoArquivo[i]);
    //}
    tamanho =  LerPorToken(&ptrFile,ConteudoArquivo);

    for(int i = 0;i<tamanho;i++){
        Ordena[i] = (char*)malloc((strlen(ConteudoArquivo[i])) * sizeof(char));
        strcpy(Ordena[i],ConteudoArquivo[i]);
    }
    QuickSortForStrings(Ordena,tamanho);
    for(int i = 0;i<tamanho;i++){
        printf("[%d]==:%s\n", i, Ordena[i]);
    }
    //ContagemLinhas(&ptrFile,&Linhas);
    // Restante do código para manipular o arquivo...
    fim = clock(); // Fim da contagem de tempo
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC; // Tempo gasto em segundos
    printf("Tempo gasto: %lf segundos\n", tempo_gasto);
    fclose(ptrFile);
    return 0;
}


