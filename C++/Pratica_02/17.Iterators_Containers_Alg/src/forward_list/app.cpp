#include <forward_list>
#include <iostream>

using namespace std;

int main() {
    // Criando forward_lists de inteiros e strings
    forward_list<int> flist1 {2, 3, 2};
    forward_list<string> flist2 = {"abc", "efg"};
    forward_list<int> flist3(2); // [0, 0]
    forward_list<int> flist4{2}; // [2]
    forward_list<int> flist5(2, -1); // [-1, -1]

    // Preenchendo flist5 com o valor 4
    fill(flist5.begin(), flist5.end(), 4); // Igual a {4, 4}

    // Adicionando um elemento no início da forward_list
    flist1.push_front(5); // [5, 2, 3, 2]

    // Inserindo um elemento após o primeiro elemento da forward_list
    flist1.insert_after(flist1.begin(), 0); // [5, 0, 2, 3, 2]

    // Removendo o elemento após o primeiro elemento da forward_list
    flist1.erase_after(flist1.begin()); // [5, 2, 3, 2]

    // Removendo todas as ocorrências do valor 2
    flist1.remove(2); // [3, 5, 3, 3]

    // Removendo elementos duplicados consecutivos
    flist1.unique(); // [3, 5, 3]

    // Ordenando a forward_list
    flist1.sort(); // [3, 3, 5]

    // Revertendo a ordem dos elementos na forward_list
    flist1.reverse(); // [5, 3, 3]

    // Mesclando flist1 com flist5
    flist1.merge(flist5); // [5, 3, 3, 4, 4]

    // Exibindo os elementos da forward_list usando range-based for loop
    cout << "Elements of flist1: ";
    for (const auto& it : flist1) {
        cout << it << ", ";
    }
    cout << endl;

    // Verificando se a forward_list está vazia
    cout << "Is flist1 empty: " << (flist1.empty() ? "true" : "false") << endl;

    return 0;
}
