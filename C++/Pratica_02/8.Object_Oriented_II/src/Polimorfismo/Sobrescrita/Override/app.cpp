#include <iostream>
using namespace std;

class Base {
public:
    virtual void funcaoVirtual() {
        cout << "Função na classe base." << endl;
    }
};

class Derivada : public Base {
public:
    void funcaoVirtual() override {
        cout << "Função na classe derivada." << endl;
    }
};

int main() {
    Base objetoBase;
    Derivada objetoDerivada;

    objetoBase.funcaoVirtual();
    objetoDerivada.funcaoVirtual();

    Base* ponteiro = &objetoDerivada;
    ponteiro->funcaoVirtual();

    return 0;
}
