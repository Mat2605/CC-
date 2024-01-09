#include <iostream>
#include <random>

using namespace std;

int main() {
    // Semente para o gerador pseudoaleatório
    random_device rd;

    // Criação do gerador PRNG usando a semente
    mt19937 mt(rd());

    // Definindo a faixa de números desejada
    int minNumber = 1;
    int maxNumber = 100;

    // Distribuição uniforme para inteiros na faixa [minNumber, maxNumber]
    uniform_int_distribution<int> dist(minNumber, maxNumber);

    // Gerando números pseudoaleatórios
    int randomNum1 = dist(mt);
    int randomNum2 = dist(mt);

    // Exibindo os números gerados
    cout << "Número pseudoaleatório 1: " << randomNum1 << endl;
    cout << "Número pseudoaleatório 2: " << randomNum2 << endl;

    return 0;
}
