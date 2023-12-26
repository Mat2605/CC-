#include <iostream>
using namespace std;

// Superclasse
class B {
public:
    int operador01, operador02, resultado;
    B(int valor01, int valor02) {
        this->operador01 = valor01;
        this->operador02 = valor02;
    }
};

// Subclasse
class C : public B {
public:
    C(int valor01, int valor02) : B(valor01, valor02) {
        this->resultado = 0;
    }
    void somar() {
        this->resultado = this->operador01 + this->operador02;
    }
    int retornaResultado() {
        return this->resultado;
    }
};

int main() {
    B o1(1, 2);
    C o2(20, 3);
    o2.somar();
    cout << "Resultado da soma: " << o2.retornaResultado() << endl;
    return 0;
}
