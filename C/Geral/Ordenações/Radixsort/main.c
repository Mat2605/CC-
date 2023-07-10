#include <stdio.h>

// Função para encontrar o maior elemento no array
int encontrarMaior(int array[], int tamanho) {
    int i;
    int maior = array[0];
    for (i = 1; i < tamanho; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}

// Função para realizar a ordenação Radix Sort
void radixSort(int array[], int tamanho) {
    int i;
    int exp = 1;
    int maior = encontrarMaior(array, tamanho);
    int bucket[tamanho];
    int aux[tamanho];

    // Realiza a contagem de cada dígito
    while (maior / exp > 0) {
        int bucketContagem[10] = {0};

        // Conta a ocorrência de cada dígito em uma determinada posição
        for (i = 0; i < tamanho; i++) {
            bucketContagem[(array[i] / exp) % 10]++;
        }

        // Calcula as posições dos elementos no array ordenado
        for (i = 1; i < 10; i++) {
            bucketContagem[i] += bucketContagem[i - 1];
        }

        // Ordena os elementos no array auxiliar usando as contagens
        for (i = tamanho - 1; i >= 0; i--) {
            aux[--bucketContagem[(array[i] / exp) % 10]] = array[i];
        }

        // Copia os elementos do array auxiliar para o array original
        for (i = 0; i < tamanho; i++) {
            array[i] = aux[i];
        }

        exp *= 10;
    }
}

// Função para exibir o array
void exibirArray(int array[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array original:\n");
    exibirArray(array, tamanho);

    radixSort(array, tamanho);

    printf("Array ordenado:\n");
    exibirArray(array, tamanho);

    return 0;
}
