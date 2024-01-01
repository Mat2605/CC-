#include <iostream>
using namespace std;
// Função declarada como inline
inline int add(int a, int b) {
    return a + b;
}

// Função de multiplicação declarada como inline
inline int multiply(int a, int b) {
    return a * b;
}

// Função de potência declarada como inline
inline int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    int resultAdd = add(3, 4);            
    int resultMultiply = multiply(5, 6); 
    int resultPower = power(2, 3);         

    cout << "Resultado da adição: " << resultAdd << "\n";
    cout << "Resultado da multiplicação: " << resultMultiply << "\n";
    cout << "Resultado da potência: " << resultPower << "\n";

    return 0;
}
