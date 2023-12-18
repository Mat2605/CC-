#include <iostream>
using namespace std;
int main(){
    //Diferentes formas de representar flutuantes,com base no formato IEEE764
    float f = 1.3;
    
    cout << f << "\n";
    f = 1.3e3; // 1.3 * 10^3
    cout << f << "\n";
    f = 1.3E5;// 1.3 * 10^5
    cout << f << "\n";
    f = 1.3E4f; // 1.3 * 10^4
    cout << f << "\n";
    f = 1.3e2f; // 1.3 * 10^2
    cout << f << "\n";
    return 0;
}