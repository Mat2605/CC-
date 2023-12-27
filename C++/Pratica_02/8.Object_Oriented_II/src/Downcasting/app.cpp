#include <iostream>
using namespace std;
class Base {
public:
    virtual void mensagem() {
        cout << "Mensagem da classe Base\n";
    }
};

class Derivada : public Base {
public:
    void outraMensagem() {
        cout << "Mensagem da classe Derivada\n";
    }
};

int main() {
    Derivada derivadaObj;
    Base* basePtr = &derivadaObj;  // Upcasting

    // Tentativa de downcasting usando dynamic_cast
    Derivada* derivadaPtr = dynamic_cast<Derivada*>(basePtr);

    if (derivadaPtr != nullptr) {
        derivadaPtr->outraMensagem();
    } else {
        cout << "A conversão falhou.\n";
    }

    return 0;
}
