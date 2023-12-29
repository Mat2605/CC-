#include <iostream>
using namespace std;
template<typename T>
    T add(T a,T b){
        return a+b;
}

template <typename T>
    T f(T a){
        return a*2;
}
template <int A,int B> //template sem tipos genéricos
int retornar(){
    return A*B;

}

enum class Enum { Left, Right };
template<Enum Z>
int add_enum(int a, int b) {
    return (Z == Enum::Left) ? a + b : a;
}
template<int DIV, typename T>
T ceil_div(T value) {
return (value + DIV - 1) / DIV;
}

template<int A = 3>
int print1() {
cout << A;
}


int main(){
    cout << add(23,21) << "||" << add(2.0f,3.0f);
    //template implícito e explícita
    cout << "\n" << f(3) << "\n" << f<short>(2.0) << "\n";
    //chamando retornar
    cout << retornar<32,2>() << "\n";
    cout << add_enum<Enum::Left>(3, 4);
    cout << "\n" <<  ceil_div<5>(11);
    print1<2>(); 

    return 0;

}