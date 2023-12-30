#include <iostream>
#include <type_traits>
using namespace std;

// Função para imprimir se o tipo é inteiro
template <typename T>
enable_if_t<is_integral<T>::value>
printIfInteger(T value) {
    cout << "É um inteiro: " << value << endl;
}

// Função para imprimir se o tipo é ponto flutuante
template <typename T>
enable_if_t<is_floating_point<T>::value>
printIfFloatingPoint(T value) {
    cout << "É um ponto flutuante: " << value << endl;
}

// Função para imprimir se o tipo é uma string
template <typename T>
enable_if_t<is_same<T, string>::value>
printIfString(const T& value) {
    cout << "É uma string: " << value << endl;
}

// Sobrecarga para imprimir nullptr
void printIfPointer(nullptr_t) {
    cout << "É um ponteiro: nullptr" << endl;
}

int main() {
    printIfInteger(42);
    printIfFloatingPoint(3.14);
    printIfString(string("Hello"));
    printIfPointer(nullptr);

    // Exemplo para um tipo não suportado
    // printIfString(42); // Isso resultaria em um erro de compilação

    return 0;
}


