#include <list>
#include <iostream>

using namespace std;

int main() {
    // Criando listas de inteiros e strings
    list<int> list1 {2, 3, 2};
    list<string> list2 = {"abc", "efg"};
    list<int> list3(2); // [0, 0]
    list<int> list4{2}; // [2]
    list<int> list5(2, -1); // [-1, -1]

    // Preenchendo list5 com o valor 3
    list5.assign(2, 3); // Igual a {3, 3}

    // Adicionando um elemento no final da lista
    list1.push_back(5); // [2, 3, 2, 5]

    // Mesclando list1 com list5
    list1.merge(list5); // [2, 3, 2, 5, 3, 3]

    // Removendo todas as ocorrências do valor 2
    list1.remove(2); // [3, 5, 3, 3]

    // Removendo elementos duplicados consecutivos
    list1.unique(); // [3, 5, 3]

    // Ordenando a lista
    list1.sort(); // [3, 3, 5]

    // Revertendo a ordem dos elementos na lista
    list1.reverse(); // [5, 3, 3]

    // Exibindo os elementos da lista usando range-based for loop
    cout << "Elements of list1: ";
    for (const auto& it : list1) {
        cout << it << ", ";
    }
    cout << endl;

    // Tamanho da lista
    cout << "list1 size: " << list1.size() << endl;

    // Verificando se a lista está vazia
    cout << "Is list1 empty: " << (list1.empty() ? "true" : "false") << endl;

    return 0;
}

