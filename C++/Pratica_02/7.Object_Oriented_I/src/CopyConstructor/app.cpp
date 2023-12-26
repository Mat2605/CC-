#include <iostream>
using namespace std;

class NovaClasse {
private:
    int dados;

public:
    // Construtor padrão
    NovaClasse() {
        dados = 0;
        cout << "Construtor padrão chamado. Dados: " << dados << endl;
    }

    // Construtor com parâmetro
    NovaClasse(int var) {
        this->dados = var;
        cout << "Construtor com parâmetro chamado. Dados: " << dados << endl;
    }

    // Construtor de cópia
    NovaClasse(const NovaClasse &outra) : dados(outra.dados) {
        cout << "Construtor de cópia chamado. Dados: " << dados << endl;
    }
    void exibirDados() const {
        cout << "Dados: " << dados << endl;
    }
};

int main() {
    NovaClasse objetoPadrao;          // Construtor padrão
    NovaClasse objetoComParametro(5); // Construtor com parâmetro
    // Criação de um objeto usando o construtor de cópia
    NovaClasse objetoCopia(objetoComParametro);
    objetoPadrao.exibirDados();
    objetoComParametro.exibirDados();
    objetoCopia.exibirDados();

    return 0;
}
