#include <iostream>

// Template variável para calcular a soma de uma sequência de valores
template <typename... TArgs>
constexpr auto sum(TArgs... args) {
    return (args + ...);
}

int main() {
    // Uso da variável template para calcular a soma
    int result = sum(1, 2, 3, 4, 5);
    std::cout << "Soma: " << result << std::endl;

    // Pode-se usar para outros tipos também
    double doubleResult = sum(1.5, 2.5, 3.5, 4.5);
    std::cout << "Soma de doubles: " << doubleResult << std::endl;

    return 0;
}
