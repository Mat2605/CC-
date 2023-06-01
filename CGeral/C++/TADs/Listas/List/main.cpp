#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> lista;

    // Inserção de elementos
    lista.push_back(10);  // Insere no final
    lista.push_front(5);  // Insere no início
    auto iterador = lista.begin();
    ++iterador;  // Avança para o segundo elemento
    lista.insert(iterador, 7);  // Insere após o primeiro elemento

    // Acesso aos elementos
    cout << "Elementos da lista: ";
    for (const auto& elemento : lista) {
        cout << elemento << " ";
    }
    cout << endl;

    // Ordenar a lista em ordem crescente
    lista.sort();
    cout << "Elementos da lista após ordenação: ";
    for (const auto& elemento : lista) {
        cout << elemento << " ";
    }
    cout << endl;

    // Inverter a ordem dos elementos na lista
    lista.reverse();
    cout << "Elementos da lista após inversão: ";
    for (const auto& elemento : lista) {
        cout << elemento << " ";
    }
    cout << endl;

    // Verificar se a lista está vazia
    if (lista.empty()) {
        cout << "A lista está vazia." << endl;
    } else {
        cout << "A lista não está vazia." << endl;
    }

    // Tamanho da lista
    cout << "Tamanho da lista: " << lista.size() << endl;

    // Remover elementos
    lista.pop_back();  // Remove o último elemento
    lista.pop_front();  // Remove o primeiro elemento
    lista.erase(++lista.begin());  // Remove o segundo elemento

    // Verificar se a lista está vazia novamente
    if (lista.empty()) {
        cout << "A lista está vazia." << endl;
    } else {
        cout << "A lista não está vazia." << endl;
    }

    return 0;
}

