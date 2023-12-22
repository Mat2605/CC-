#include <iostream>
#include <algorithm> // para o uso de funções lambda
using namespace std;

int a = 0;

//declaração de lambda por referencia
auto x = [&](int b) {
    a = b * b;
    return a;
};

int main() {
    int array[] = {7, 2, 5, 1}, a = 0, b = 2;

    auto lambda = [](int a, int b) { return a > b; }; // lambda para ordenar em ordem decrescente
    sort(array, array + 4, lambda);

    cout << "Array ordenado em ordem decrescente:\n";
    for (int i = 0; i < 4; i++) {
        cout << array[i] << "\n";
    }

    cout << "Resultado da funcao: " << x(b) << "\n";

    //passagem por valor
    auto isEven = [](int num) { return num % 2 == 0; };
    cout << "O numero " << b << (isEven(b) ? " e par" : " e ímpar") << "\n";

    //mais passagem por valor
    auto average = [](double x, double y) { return (x + y) / 2.0; };
    cout << "A media de " << b << " e " << a << " e: " << average(b, a) << "\n";

    // Lambda que passa uma variável por referência
    auto multiplyByReference = [](int& x, int& y) { return x * y; };
    int result = multiplyByReference(b, a);
    cout << "Resultado da multiplicacao por referencia: " << result << "\n";

    // Lambda que passa todas as variáveis por referência
    auto modifyAllByReference = [&](int& x, int& y, int& z) {
        x *= 2;
        y += 5;
        z -= 3;
    };

    cout << "Valores antes da modificacao por referencia: " << b << ", " << a << ", " << array[0] << "\n";
    modifyAllByReference(b, a, array[0]);
    cout << "Valores depois da modificacao por referencia: " << b << ", " << a << ", " << array[0] << "\n";

    return 0;
}
