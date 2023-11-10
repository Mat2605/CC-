#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int set[], int n, int sum) {
    //Tabela programação dinâmica
    bool subset[n + 1][sum + 1];
    int i, j;

    // Caso base: a soma de um subconjunto vazio é sempre 0
    for (i = 0; i <= n; i++)
        subset[i][0] = true;

    // Caso base: se o conjunto está vazio, não é possível encontrar uma soma não nula
    for (i = 1; i <= sum; i++)
        subset[0][i] = false;

    // Preenche a tabela subset usando a abordagem de programação dinâmica
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= sum; j++) {
            if (j < set[i - 1]) {
                subset[i][j] = subset[i - 1][j];
            } else {
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
            }
        }
    }

    // Imprime na tela o maior valor encontrado
    for(i = 1;i<=n;i++){
        for(j = 1; j <= sum; j++){
            if(j==9){
                if(subset[i][j]){
                    printf("TRUE!\n");
                }
            }
        }
    }
    for (j = sum; j >= 0; j--) {
        if (subset[n][j]) {
            printf("Maior valor possível: %d\n", j);
            break;
        }
    }

    return subset[n][sum];
}

int main() {
    //Encontrar nesse subconjunto que resulte em 17
    int set[] = {3, 1, 5, 9, 12};
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 17;
    if (isSubsetSum(set, n, sum)) {
        printf("É possível dividir o conjunto em dois subconjuntos com a mesma soma.\n");
    } else {
        printf("Não é possível dividir o conjunto em dois subconjuntos com a mesma soma.\n");
    }

    return 0;
}
