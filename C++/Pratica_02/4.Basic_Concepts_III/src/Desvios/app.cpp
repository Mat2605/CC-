#include <iostream>
using namespace std;
int main(){
    //aplicação de alguns recursos de desvios
    int vector[5] ={1,2,3,4,5},flag = 10,a = 5,b = 5,c = 4;
    if(flag%2==0 || vector[-1] == 0){
        cout << "Segunda condicional ignorada\n";
    }
    //operações ternárias.
    int value = (a == b) ? a : (b == c ? b : 3); 
    cout << value << "\n";

    return 0;
}