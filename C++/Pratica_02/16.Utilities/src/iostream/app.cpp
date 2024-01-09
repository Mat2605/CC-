#include <iostream>
#include <bitset>
#include <iomanip>  //setprecision
using namespace std;

int main() {
    // formatos decimais/hex/oct
    cout << dec << 0xF << "\n"; 
    cout << hex << 16 << "\n"; 
    cout << oct << 8 << "\n";

    // para sequência de bits 
    cout << bitset<32>(3.45f) << "\n";
    cout << bitset<32>(4) << "\n"; 

    // correção nos operadores de inserção para boolalpha
    cout << boolalpha << 1 << "\n";
    cout << boolalpha << 0 << "\n"; 

    //número de casas decimais
    cout<< setprecision(2)<< 3.538 << "\n";

    //representação de flutuantes
    cout << setprecision(2) << fixed << 32.5 << "\n";
    cout << setprecision(2) << scientific << 32.5 << "\n";

    //junção de strings
    cout << right << setw(7) << "abc" << "##" << "\n";
    cout << left << setw(7) << "abc" << "##" << "\n"; 


    return 0;
}

