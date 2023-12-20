#include <iostream>
using namespace std;
//declaração local
int f(int y){
    struct A{
        int x;
    };
    A flag;
    flag.x = 20;
    return flag.x/2;
}
struct estrutura{
    char A;
    enum Cores {Vermelho,Azul};
};
struct estruturaBytes{
    int b1 : 10; // range [0, 1023] 2^10
    int b2 : 10; // range [0, 1023] 2^10
    int b3 : 8; // range [0, 255] 2^8
};

int main(){
    estrutura flag;
    estruturaBytes aux;
    flag.A = 'A';
    cout << flag.A << "\n";
    cout << flag.Azul << "\n";
    cout << f(20) << "\n";
    cout << (aux.b1 + aux.b2 + aux.b3) << "\n";

    return 0;
}