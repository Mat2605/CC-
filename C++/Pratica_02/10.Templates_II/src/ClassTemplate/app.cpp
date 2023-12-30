#include <iostream>
using namespace std;

template <typename T>
class ClasseComGenerico {
private:
    T componente;

public:
    T retornar() {
        return this->componente;
    }

    void atribuir(T VarComponente) {
        this->componente = VarComponente;
    }
};

template <typename T, int N> // Declaração parcial
class ClasseParcial {
private:
    int inteiro = 100;
    T componente;

public:
    T retornar() {
        return this->componente;
    }

    void atribuir(T VarComponente) {
        this->componente = VarComponente;
    }

    T somar() {
        return (this->inteiro + this->componente);
    }
};

int main() {
    ClasseComGenerico<int> obj;
    ClasseParcial<double, 0> obj2;
    obj.atribuir(20);
    obj2.atribuir(20.0);
    cout << obj.retornar() << "\n";
    cout << obj2.somar() << "\n";
    return 0;
}
