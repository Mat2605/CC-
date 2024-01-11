#include <set>
#include <iostream>

using namespace std;

int main() {
    // Criando conjuntos de inteiros e strings
    set<int> set1 {5, 2, 3, 2, 7};
    set<int> set2 = {2, 3, 2};
    set<string> set3 = {"abc", "efg"};
    set<int> set4; // conjunto vazio

    // Removendo o elemento 2 do conjunto set2
    set2.erase(2); // [3]

    // Inserindo a string "hij" no conjunto set3
    set3.insert("hij"); // ["abc", "efg", "hij"]

    // Exibindo os elementos do conjunto set1 usando range-based for loop
    cout << "Elements of set1: ";
    for (const auto& it : set1) {
        cout << it << " ";
    }
    cout << endl;

    // Buscando o elemento 2 no conjunto set1
    auto search = set1.find(2); // retorna um iterador
    cout << (search != set1.end()); // true

    // Encontrando o primeiro elemento maior ou igual a 4 no conjunto set1
    auto it = set1.lower_bound(4);
    cout << *it; // 5

    // Contando o número de ocorrências do elemento 2 no conjunto set1
    set1.count(2); // 1, note: só pode ser 0 ou 1

    // Encontrando um intervalo de elementos iguais a 2 no conjunto set1
    auto it_pair = set1.equal_range(2); // retorna um par de iteradores
    // it_pair.first aponta para o início do intervalo, it_pair.second aponta para o final do intervalo
    // Neste caso, o intervalo é [2, 3)
    
    return 0;
}
