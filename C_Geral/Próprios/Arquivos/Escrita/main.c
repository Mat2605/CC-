#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_MAX 1000

int main(void) {
    char conteudo[TAM_MAX];
    int tamanho = 0;
    FILE *fp;
    fp = fopen("entrada.asm", "w");

    printf("Digite as strings. Digite uma linha vazia para finalizar.\n");
    while (1) {
        fgets(conteudo, sizeof(conteudo), stdin);

        // se o usuário digitar uma linha vazia, finaliza o loop
        if (strlen(conteudo) == 1) {
            break;
        }

        // escreve a string no arquivo
        fprintf(fp, "%s", conteudo);
        tamanho += strlen(conteudo);
    }

    // fecha o arquivo
    fclose(fp);

    // reabre o arquivo para leitura
    fp = fopen("entrada.asm", "r");

    // imprime o conteúdo do arquivo na tela
    fgets(conteudo, tamanho, fp);
    printf("O conteúdo do arquivo é:\n%s", conteudo);

    // fecha o arquivo
    fclose(fp);

    return 0;
}
