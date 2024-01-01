#include <iostream>
using namespace std;
int f() {
    static int val = 1; //variáveis estáticacs locais
    val++;
    return val;
}
int main() {
cout << f() << "\n"; // print 2 
cout << f() << "\n"; // print 3
cout << f() << "\n"; // print 4
}