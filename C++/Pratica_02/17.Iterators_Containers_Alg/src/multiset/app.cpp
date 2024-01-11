#include <set>
#include <iostream>

using namespace std;

int main() {
    // Criando multiconjuntos de inteiros e strings
    multiset<int> multiset1 {5, 2, 3, 2, 7};
    multiset<int> multiset2 = {2, 3, 2};
    multiset<string> multiset3 = {"abc", "efg"};

    // Inserindo elementos no multiconjunto
    multiset1.insert(5);
    multiset1.insert(7);

    // Exibindo os elementos do multiconjunto usando range-based for loop
    cout << "Elements of multiset1: ";
    for (const auto& it : multiset1) {
        cout << it << " ";
    }
    cout << endl;

    // Contando o número de ocorrências do elemento 2 no multiconjunto
    cout << "Count of 2 in multiset1: " << multiset1.count(2) << endl;

    // Encontrando um intervalo de elementos iguais a 2 no multiconjunto
    auto it_pair = multiset1.equal_range(2); // retorna um par de iteradores
    // it_pair.first aponta para o início do intervalo, it_pair.second aponta para o final do intervalo

    return 0;
}
