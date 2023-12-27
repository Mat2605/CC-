#include <iostream>
using namespace std;
//aplicando o polimorfismo de sobrescrita
class A {
    public:
    void f() { 
        cout << "A"; 
    }
    
};
class B : public A {
    public:
    void f() {//recomendável usar override
         cout << "B";
    }
};
void g(A& a) { a.f(); } 
void h(B& b) { b.f(); } 
int main(){
    A a;
    B b;
    g(a);
    g(b);
    return 0;
}