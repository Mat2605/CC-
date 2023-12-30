#include <iostream>

// Left Fold: Soma todos os elementos na sequência
template<typename... Args>
constexpr auto sum(Args... args) {
    return (args + ...);
}

// Right Fold: Multiplica todos os elementos na sequência
template<typename... Args>
constexpr auto product(Args... args) {
    return (... * args);
}

int main() {
    // Uso da função com folding expression para soma
    constexpr int resultSum = sum(1, 2, 3, 4, 5);
    std::cout << "Soma: " << resultSum << std::endl;

    // Uso da função com folding expression para multiplicação
    constexpr int resultProduct = product(1, 2, 3, 4, 5);
    std::cout << "Produto: " << resultProduct << std::endl;

    return 0;
}
