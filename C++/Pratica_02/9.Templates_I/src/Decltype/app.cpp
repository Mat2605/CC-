#include <iostream>
using namespace std;

void f(int, float);

int main() {
    int x = 3;
    int& y = x;
    const int z = 4;
    int array[2];

    decltype(x) result1;        // Agora result1 é do mesmo tipo que x
    decltype(2 + 3.0) result2;  // Agora result2 é do mesmo tipo que a expressão 2 + 3.0
    decltype(y) result3 = x;    // Agora result3 é uma referência para o mesmo tipo que y
    decltype(z) result4 = z;    // Agora result4 é do mesmo tipo que z
    decltype(array) result5;    // Agora result5 é do mesmo tipo que array

    result1 = x;
    result2 = 2 + 3.0;
    result3 = x;
    result5[0] = 1; // Exemplo de uso de array

    cout << "Programa executado com sucesso." << endl;

    return 0;
}
