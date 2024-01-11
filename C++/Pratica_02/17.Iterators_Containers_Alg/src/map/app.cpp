#include <map>
#include <iostream>

using namespace std;

int main() {
    // Criando mapas de string para inteiros e de double para inteiros
    map<string, int> map1 {{"bb", 5}, {"aa", 3}};
    map<double, int> map2; // mapa vazio

    // Acessando o valor associado à chave "aa" no mapa map1
    cout << map1["aa"]; // imprime 3

    // Inserindo ou alterando valores no mapa map1
    map1["dd"] = 3; // insere <"dd", 3>
    map1["dd"] = 7; // altera <"dd", 7>
    cout << map1["cc"]; // insere <"cc", 0>

    // Exibindo os valores do mapa map1 usando range-based for loop
    cout << "Values of map1: ";
    for (const auto& it : map1) {
        cout << it.second << " ";
    }
    cout << endl;

    // Inserindo um par chave-valor no mapa map1
    map1.insert({"jj", 1});

    // Buscando a chave "jj" no mapa map1
    auto search = map1.find("jj"); // retorna um iterador
    cout << (search != map1.end()); // true

    // Encontrando o valor associado à chave "bb" no mapa map1
    auto it = map1.lower_bound("bb");
    cout << it->second; // 5

    return 0;
}
