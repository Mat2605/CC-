#include <iostream>
#include <vector>
#include <concepts>
//versão desatualizada do C++,disponível no C++ 20

// Definindo um conceito chamado Printable
template <typename T>
concept Printable = requires(T value) {
    { std::cout << value } -> std::same_as<std::ostream&>; // Deve retornar std::ostream&
};

// Função que usa o conceito Printable
template <Printable T>
void printValue(const T& value) {
    std::cout << value << std::endl;
}

int main() {
    // Chamando a função com tipos que atendem ao conceito Printable
    printValue(42);
    printValue(3.14);
    printValue("Hello, Concepts!");

    // Tentando chamar a função com um tipo que não atende ao conceito Printable
    // printValue(std::vector<int>{1, 2, 3}); // Isso resultaria em um erro de compilação

    return 0;
}
