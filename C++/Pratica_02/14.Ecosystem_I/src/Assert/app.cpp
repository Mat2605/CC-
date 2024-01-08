#include <iostream>
#include <cassert>
using namespace std;
int dividir(int numerador, int denominador) {
    assert(denominador != 0);

    return numerador / denominador;
}

int main() {
    int numerador, denominador;
    
    cout << "Digite o numerador: ";
    cin >> numerador;

    cout << "Digite o denominador: ";
    cin >> denominador;

    int resultado = dividir(numerador, denominador);

    cout << "Resultado: " << resultado << endl;

    return 0;
}
