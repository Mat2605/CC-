#include <iostream>
#include <random>
#include <chrono>
using namespace std;

int main() {
    // Obtendo sementes usando a biblioteca chrono
    unsigned seed1 = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    unsigned seed2 = seed1 + 1000;

    // Criando uma sequência de sementes
    seed_seq seq1{ seed1, seed2 };

    // Criando um gerador PRNG usando a sequência de sementes
    default_random_engine generator1(seq1);

    // Criando um gerador PRNG usando std::random_device
    random_device rnd;
    default_random_engine generator2(rnd());

    // Gerando números pseudoaleatórios com os dois geradores
    int randomNum1 = generator1();
    int randomNum2 = generator2();

    // Exibindo os números gerados
    cout << "Número pseudoaleatório 1: " << randomNum1 << endl;
    cout << "Número pseudoaleatório 2: " << randomNum2 << endl;

    return 0;
}
