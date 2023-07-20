#include "C:\Users\mathe\Documents\CC++\C\Proprios\ArquivosDefinitivo\.h\Funct.h"
#include "C:\Users\mathe\Documents\CC++\C\Proprios\ArquivosDefinitivo\.h\ListaDePalavras.h"

//ESSE PROJETO SERÁ PARA CONSEGUIR MANIPULAR UM ARQUIVO COM VÁRIOS TIPOS DE OPERAÇÕES
//FACILITAR PARA PROJETOS FUTUROS COM ESSE TIPO DE ABORDAGEM

int main(void) {
    clock_t inicio, fim;
    double tempo_gasto;

    char *ConteudoArquivo[216];
    char *Ordena[216];
    int *vetorLinhas;
    FILE *ptrFile;
    unsigned int Linhas,tamanho;
    Lista lista;

    Inicializa_Lista(&lista);

    inicio = clock();

    CondicaoDeExistencia(&ptrFile);
    ContagemLinhas(&ptrFile,&Linhas);
    tamanho =  LerPorToken(&ptrFile,ConteudoArquivo);

    for(int i = 0;i<tamanho;i++){
        Ordena[i] = (char*)malloc((strlen(ConteudoArquivo[i])) * sizeof(char));
        strcpy(Ordena[i],ConteudoArquivo[i]);
    }

    QuickSortForStrings(Ordena,tamanho);
    for(int i = 0;i<tamanho;i++){
        Inserir_Componente(&lista,Ordena[i]);
    }
    Imprimir_Conteudo(&lista);
    ContagemLinhas(&ptrFile,&Linhas);
    fim = clock(); // Fim da contagem de tempo
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC; // Tempo gasto em segundos
    printf("Tempo gasto: %lf segundos\n", tempo_gasto);
    fclose(ptrFile);
    return 0;
}


