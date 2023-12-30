#include <iostream>
using namespace std;

template<typename T, typename B>
class CF {
public:
    template<typename X, typename Y>
    X retornar(X a, Y b) {
        return (a * 2) + static_cast<X>(b);
    }

    B retornar(B a) {
        return a * 30;
    }

    void mostrarTamanhos() {
        cout << sizeof(T) << "|" << sizeof(B) << "\n";
    }
};

int main() {
    CF<int, double> obj;

    int resultadoInt = obj.retornar(5, 3.5);
    double resultadoDouble = obj.retornar(2.5);

    cout << "Resultado Int: " << resultadoInt << "\n";
    cout << "Resultado Double: " << resultadoDouble << "\n";

    obj.mostrarTamanhos();

    return 0;
}
