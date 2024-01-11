#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    // Criando arrays de inteiros
    array<int, 3> arr1 = {5, 2, 3};
    array<int, 4> arr2 = {1, 2}; // [3]: 0, [4]: 0
    // array<int, 3> arr3 = {1, 2, 3, 4}; // Erro de compilação (tamanho incorreto)
    
    // Copy constructor
    array<int, 3> arr4(arr1);

    // Operador de atribuição
    array<int, 3> arr5 = arr1;

    // Preenchendo o array com o valor 3
    arr5.fill(3); // Igual a { 3, 3, 3 }

    // Ordenando o array
    sort(arr1.begin(), arr1.end()); // arr1: 2, 3, 5

    // Verificando se arr1 é maior que arr2
    cout << "arr1 > arr2: " << (arr1.size() > arr2.size()) << endl; // true

    // Tamanho do array em bytes
    cout << "sizeof(arr1): " << sizeof(arr1) << endl; // 12

    // Tamanho do array
    cout << "arr1.size(): " << arr1.size() << endl; // 3

    // Exibindo os elementos do array usando range-based for loop
    cout << "Elements of arr1: ";
    for (const auto& it : arr1) {
        cout << it << ", ";
    }
    cout << endl;

    // Acessando o primeiro elemento do array
    cout << "arr1[0]: " << arr1[0] << endl; // 2

    // Acessando o primeiro elemento de forma segura usando at()
    cout << "arr1.at(0): " << arr1.at(0) << endl; // 2 (seguro)

    // Acessando o primeiro elemento usando data()
    cout << "arr1.data()[0]: " << arr1.data()[0] << endl; // 2

    return 0;
}
