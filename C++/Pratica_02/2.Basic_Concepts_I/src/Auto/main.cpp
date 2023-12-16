#include <iostream>
using namespace std;
auto f1(int x){
    return x*2;
}
void f2(auto var){
    cout << var << "\n";
}
int main(){
    auto A = 2.5 + 1;
    cout << A << "\n";
    float retorno = f1(3);
    cout << retorno << "\n";
    f2(A);
    f2(1);
    return 0;
}