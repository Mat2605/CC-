#include <iostream>
using namespace std;

// Declarando a classe B antes da classe A
class B;

// Definindo a classe A
class A {
private:
    int privateA;

public:
    A() : privateA(42) {}

    // Declarando a classe B como amiga
    friend class B;

    // Função que pode ser acessada por B
    void exibirPrivateA() {
        cout << "Membro privado de A: " << privateA << endl;
    }
    friend int f(A a);
};

int f(A a) {
    return a.privateA;
}

// Definindo a classe B
class B {
private:
    int privateB;

public:
    B() : privateB(99) {}

    // Função que pode acessar membros privados de A
    void acessarA(A& objetoA) {
        cout << "Acessando membro privado de A a partir de B: " << objetoA.privateA << endl;
    }
};

int main() {
    A objetoA;
    B objetoB;

    // Chamando a função de B para acessar o membro privado de A
    objetoB.acessarA(objetoA);

    // Chamando a função de A para exibir seu próprio membro privado
    objetoA.exibirPrivateA();

    return 0;
}
