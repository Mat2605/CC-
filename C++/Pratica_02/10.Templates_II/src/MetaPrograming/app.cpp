#include <iostream>

using namespace std;  // Não é uma prática comum colocar "using namespace std;" dentro do corpo do código

template<int N>
struct Factorial {
    // GENERIC template: Recursive step
    static constexpr int value = N * Factorial<N - 1>::value;
};
//Ou: 
template<typename T>
constexpr int factorial(T value) {
T tmp = 1;
for (int i = 2; i <= value; i++)
tmp *= i;
return tmp;
};

template<>
struct Factorial<0> {
    // FULL SPECIALIZATION: Base case
    static constexpr int value = 1;
};

int main() {
    constexpr int x = Factorial<5>::value; // Calcula o fatorial de 5 em tempo de compilação
    cout << "Fatorial de 5: " << x << endl;  // Deve imprimir 120

    // Exemplo para ilustrar a especialização completa para o caso de N = 0
    constexpr int y = Factorial<0>::value;
    cout << "Fatorial de 0: " << y << endl;  // Deve imprimir 1

    // Exemplo que resultaria em recursão infinita (comente para evitar erros)
    // int z = Factorial<-1>::value;  // Isso causaria uma recursão infinita em tempo de compilação

    return 0;
}
