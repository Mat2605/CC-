#include <iostream>

class FuncaoExemplo {
private:
    int valor;

public:
    FuncaoExemplo() : valor(0) {}

    // Sobrecarga do operador de chamada de função
    int operator()(int x, int y) const {
        return x + y + valor;
    }

    // Sobrecarga do operador de incremento (++x)
    FuncaoExemplo& operator++() {
        ++valor;
        return *this;
    }

    // Sobrecarga do operador de incremento (x++)
    FuncaoExemplo operator++(int) {
        FuncaoExemplo temp(*this);
        ++valor;
        return temp;
    }

    // Sobrecarga do operador de decremento (--x)
    FuncaoExemplo& operator--() {
        --valor;
        return *this;
    }

    // Sobrecarga do operador de decremento (x--)
    FuncaoExemplo operator--(int) {
        FuncaoExemplo temp(*this);
        --valor;
        return temp;
    }

    // Sobrecarga do operador de atribuição (=)
    FuncaoExemplo& operator=(const FuncaoExemplo& outra) {
        if (this != &outra) {
            valor = outra.valor;
        }
        return *this;
    }
};

int main() {
    FuncaoExemplo soma;
    FuncaoExemplo outra;

    // Usando um objeto como uma função
    int resultado = soma(3, 4);
    std::cout << "Resultado inicial: " << resultado << "\n";

    // Incrementando e usando novamente
    ++soma;
    resultado = soma(3, 4);
    std::cout << "Resultado após incremento: " << resultado << "\n";

    // Atribuindo o valor de 'outra' para 'soma'
    soma = outra;
    resultado = soma(3, 4);
    std::cout << "Resultado após atribuição: " << resultado << "\n";

    return 0;
}
