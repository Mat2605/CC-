#include <iostream>
#include <math.h>
using namespace std;
constexpr double f(int a,int b); // declaração de uma função
constexpr double f(int a,int b){
    return pow(a,b);
} //definição de uma função
int f(int a,int b,int c){ //sobrecarga de funções 'f',princípio do polimorfismo
    return a*b*c;
}
[[noreturn]] void multi(int *a,int *c){ //passagem por ponteiro
    *c = (*a)*(*a); //valores sendo acessados
}
void newmulti(int &a,int &b){ //passagem por referencia
    b = a*a;
}
int main(){
    int f1 = 5, f2 = 2,f3 = 0;
    cout << f(f1,f2) << "\n"; //passagem do valor
    cout << f(10,12,13) << "\n"; //funções de mesmo nome mas com assinaturas diferentes. 
    multi(&f1,&f3);
    cout << f3 << "\n";
    newmulti(f1,f2);
    cout << f2 << "\n";
    return 0;
}