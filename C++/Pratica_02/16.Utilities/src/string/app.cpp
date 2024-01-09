#include <iostream>
#include <string>

using namespace std;

int main() {
    // Criando strings
    string a; 
    string b("first");

    // Verificando se a string está vazia
    if (a.empty()) {
        cout << "String 'a' está vazia." << endl;
    } else {
        cout << "String 'a' não está vazia." << endl;
    }

    // Obtendo o tamanho da string
    cout << "Tamanho da string 'b': " << b.size() << endl;

    // Encontrando substrings
    size_t pos = b.find("irs");
    if (pos != string::npos) {
        cout << "Substring encontrada em 'b' na posição: " << pos << endl;
    } else {
        cout << "Substring não encontrada em 'b'." << endl;
    }

    // Encontrando última ocorrência de substring
    pos = b.rfind("r");
    if (pos != string::npos) {
        cout << "Última ocorrência de 'r' em 'b' na posição: " << pos << endl;
    } else {
        cout << "Substring não encontrada em 'b'." << endl;
    }

    // Encontrando primeira ocorrência de qualquer caractere em sequência
    pos = b.find_first_of("xyz");
    if (pos != string::npos) {
        cout << "Primeira ocorrência de 'x', 'y', ou 'z' em 'b' na posição: " << pos << endl;
    } else {
        cout << "Nenhum dos caracteres encontrados em 'b'." << endl;
    }

    // Encontrando última ocorrência de qualquer caractere em sequência
    pos = b.find_last_of("xyz");
    if (pos != string::npos) {
        cout << "Última ocorrência de 'x', 'y', ou 'z' em 'b' na posição: " << pos << endl;
    } else {
        cout << "Nenhum dos caracteres encontrados em 'b'." << endl;
    }

    // Criando uma substring
    string sub = b.substr(2, 3);
    cout << "Substring de 'b' a partir da posição 2, com comprimento 3: " << sub << endl;

    // Limpando a string
    a.clear();
    cout << "String 'a' após limpar: " << a << endl;

    // Apagando caracteres em posições específicas
    b.erase(1);
    cout << "String 'b' após apagar o caractere na posição 1: " << b << endl;

    // Substituindo parte da string
    b.replace(1, 2, "EEE");
    cout << "String 'b' após substituir parte: " << b << endl;

    // Obtendo ponteiro para sequência de caracteres
    const char* cStr = b.c_str();
    cout << "C-style string de 'b': " << cStr << endl;

    return 0;
}
