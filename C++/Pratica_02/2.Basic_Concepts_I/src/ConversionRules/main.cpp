#include <iostream>
using namespace std;

int main(){

    //inteiro * flutuante = flutuante
    float F = 2.5f;
    unsigned int I = 25;
    cout << F*I << "\n";
    //inteiro pequeno * inteiro pequeno = inteiro

    unsigned short S1 = 4;
    unsigned short S2 = 5;
    cout << S1*S2<< "\n";

    //short * long = long
    long L = 100000;
    cout << L*S1<< "\n";

    //unsigned * signed = unsigned 
    uint8_t a1 = 255;
    uint8_t b1 = 255;
    cout << b1+a1 << "\n";

    return 0;
}