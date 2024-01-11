#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Criando vectors de inteiros e strings
    vector<int> vec1 {2, 3, 4};
    vector<string> vec2 = {"abc", "efg"};
    vector<int> vec3(2); // [0, 0]
    vector<int> vec4{2}; // [2]
    vector<int> vec5(5, -1); // [-1, -1, -1, -1, -1]
    
    // Preenchendo vec5 com o valor 3
    fill(vec5.begin(), vec5.end(), 3); // Igual a {3, 3, 3, 3, 3}
    
    // Tamanho do vector em bytes
    cout << "sizeof(vec1): " << sizeof(vec1) << endl; // Tamanho pode variar dependendo da implementação
    
    // Tamanho do vector
    cout << "vec1.size(): " << vec1.size() << endl; // 3
    
    // Exibindo os elementos do vector usando range-based for loop
    cout << "Elements of vec1: ";
    for (const auto& it : vec1) {
        cout << it << ", ";
    }
    cout << endl;

    // Acessando o primeiro elemento do vector
    cout << "vec1[0]: " << vec1[0] << endl; // 2

    // Acessando o primeiro elemento de forma segura usando at()
    cout << "vec1.at(0): " << vec1.at(0) << endl; // 2 (seguro)

    // Acessando o primeiro elemento usando data()
    cout << "vec1.data()[0]: " << vec1.data()[0] << endl; // 2 (raw array)

    // Adicionando um elemento no final do vector
    vec1.push_back(5); // [2, 3, 4, 5]

    return 0;
}
