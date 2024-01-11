#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  

using namespace std;

int main() {
    // Criando um vetor de inteiros
    vector<int> numeros = {5, 2, 8, 1, 7};

    // Usando algoritmos da STL
    sort(numeros.begin(), numeros.end());  // Ordenando o vetor em ordem crescente

    // Imprimindo os elementos do vetor após a ordenação
    cout << "Vetor ordenado: ";
    for (const auto& numero : numeros) {
        cout << numero << " ";
    }
    cout << endl;

    // Usando a função reverse para inverter a ordem dos elementos
    reverse(numeros.begin(), numeros.end());

    // Imprimindo os elementos do vetor após a inversão
    cout << "Vetor invertido: ";
    for (const auto& numero : numeros) {
        cout << numero << " ";
    }
    cout << endl;

    int soma = accumulate(numeros.begin(), numeros.end(), 0);

    // Imprimindo a soma
    cout << "Soma dos elementos: " << soma << endl;

    return 0;
}

