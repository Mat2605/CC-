#include <iostream>
#include <utility>

using namespace std;

int main() {
    // Criando pares usando diferentes métodos
    pair<int, string> pair1(3, "abc");
    pair<int, string> pair2 = {4, "zzz"};
    auto pair3 = make_pair(3, "hgt");

    // Exibindo os valores do primeiro e segundo elementos do pair1
    cout << "pair1.first: " << pair1.first << endl;   // Saída: 3
    cout << "pair1.second: " << pair1.second << endl; // Saída: "abc"

    // Trocando os valores de pair1 e pair2 usando swap
    swap(pair1, pair2);

    // Exibindo os valores do primeiro e segundo elementos do pair2 após a troca
    cout << "pair2.first: " << pair2.first << endl;   // Saída: 4
    cout << "pair2.second: " << pair2.second << endl; // Saída: "zzz"

    // Verificando se pair1 é maior que pair2 (compara apenas o primeiro elemento)
    cout << "(pair1 > pair2): " << (pair1 > pair2) << endl; // Saída: 1 (true)

    return 0;
}
