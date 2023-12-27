#include <iostream>
using namespace std;
class Base {
public:
    void mensagem() {
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
    Base& baseRef = derivadaObj;  // Upcasting

    baseRef.mensagem();  // Acessando a função da classe Base
    // baseRef.outraMensagem();  // Isso resultaria em erro, pois outraMensagem pertence à Derivada

    return 0;
}
