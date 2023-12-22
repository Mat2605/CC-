#include <iostream>
using namespace std;

#define SUB3(a,b) ((a)-(b))

// Macro para calcular o quadrado de um número
#define SQUARE(x) ((x) * (x))

// Macro para calcular o máximo entre dois números
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Macro para imprimir uma mensagem de depuração
#define DEBUG_MESSAGE(msg) cout << "DEBUG: " << msg << "\n"

void f() {
    #define FUNCTION_MESSAGE(func) cout << "Function: " << func << "\n"
    
    FUNCTION_MESSAGE(__FUNCTION__);
    
    #define value 4
    cout << value << "\n";
}
int main() {
    cout << "Line: " << __LINE__ << " File: " << __FILE__ << " Date: " << __DATE__ << " Time: " << __TIME__ << "\n"; // MACROS ÚTEIS
    cout << SUB3(3, 4) << "\n";
    int num = 5;
    cout << "Square of " << num << ": " << SQUARE(num) << "\n";
    int a = 10, b = 7;
    cout << "Max between " << a << " and " << b << ": " << MAX(a, b) << "\n";
    f();
    DEBUG_MESSAGE("This is a debug message");
    #define value 3
    f();
    std::cout << value << "\n";
    return 0;
}

