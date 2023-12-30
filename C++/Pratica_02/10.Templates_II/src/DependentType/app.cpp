#include <iostream>
using namespace std;
template <typename T, int N>
struct MyStruct {
    // Membro dependente do parâmetro de modelo T
    typename T::value_type array[N];

    // Função para imprimir os elementos do array
    void printArray() {
        for (int i = 0; i < N; ++i) {
            cout << array[i] << " ";
        }
        cout << "\n";
    }
};

// Exemplo de uso
int main() {
    // Definindo uma estrutura simples para ser usada como parâmetro
    struct MyType {
        using value_type = double;
    };

    // Usando a estrutura com um tipo MyType e tamanho do array 3
    MyStruct<MyType, 3> myStruct;

    // Inicializando o array
    myStruct.array[0] = 1.1;
    myStruct.array[1] = 2.2;
    myStruct.array[2] = 3.3;

    // Imprimindo os elementos do array
    myStruct.printArray();

    return 0;
}
