#include <iostream>
using namespace std;
#include <iostream>

class MeuNumero {
public:
    // Construtor com explicit
    explicit MeuNumero(int valor) : numero(valor) {
        cout << "Construtor chamado. Valor: " << numero << "\n";
    }

    // Método para obter o valor
    int obterValor() const {
        return numero;
    }

private:
    int numero;
};

// Função para demonstrar conversões explícitas
void funcaoRecebeMeuNumero(MeuNumero num) {
    cout << "Número recebido: " << num.obterValor() << "\n";
}

int main() {
    // MeuNumero numeroA = 42; // Isso causaria erro de compilação se explicit for usado
    funcaoRecebeMeuNumero(MeuNumero(99));

    MeuNumero numeroB(42); // Agora a inicialização requer conversão explícita
    cout << "Número B: " << numeroB.obterValor() << "\n";

    return 0;
}
