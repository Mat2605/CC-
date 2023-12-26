#include <iostream>
using namespace std;

class A {
protected:
    int id;

public:
    A(int _id) : id(_id) {
        cout << "Construtor da classe A chamado. ID: " << id << endl;
    }
    void exibirID() {
        cout << "ID da classe A: " << id << endl;
    }
};

class B : public A {
public:
    B(int _id) : A(_id) {
        cout << "Construtor da classe B chamado. ID: " << id << endl;
    }

    void exibirID() {
        cout << "ID da classe B: " << id << endl;
    }
};

int main() {
    A objetoA(1);
    B objetoB(2);
    objetoA.exibirID();
    objetoB.exibirID();

    return 0;
}
