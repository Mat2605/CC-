#include <iostream>
using namespace std;
struct A {

virtual void f() { 
    cout << "A"; 
}

};
struct B : A {
void f() {
    cout << "B";
}

};
void f(A& a) { a.f(); }
void g(A* a) { a->f(); } 
void h(A a) { a.f(); } 
int main(){
    B b;
    f(b);
    cout << "\n";
    g(&b); 
    cout << "\n";
    h(b); 
    return 0;
}
/*
A função f(A& a) é chamada com um objeto do tipo B. Mesmo que o parâmetro seja do tipo A&, a função f é virtual.
Isso significa que, em tempo de execução, o tipo real do objeto é considerado, e a versão da função na classe
derivada B é chamada.

A função g(A* a) é chamada com o endereço de um objeto do tipo B. A função f é virtual, então ela considera o tipo real 
do objeto apontado pelo ponteiro, e a versão da função f na classe derivada B é chamada.

A função h(A a) é chamada com um objeto do tipo B. No entanto, o parâmetro é passado por valor, o que resulta em slicing,
pois apenas a parte da classe A do objeto B é passada para a função h.

*/