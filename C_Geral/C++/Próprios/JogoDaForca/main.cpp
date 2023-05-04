#include <iostream>
#include <string>
using namespace std;

int main() {
    string entrada, palavra_forca;
    int tamanho_str, contador;
    char letra;
    cout << "Digite uma palavra qualquer:" << "\n";
    getline(cin,entrada);
    // size() equivale aos strlen() em C
    tamanho_str = entrada.size();
    for (int i = 0; i < tamanho_str; i++) {
        if(entrada[i]==' '){

            palavra_forca += ' ';

        }else{
            palavra_forca += '_';
        }
        
    }
    contador = tamanho_str + 3;
    // O jogador tem chance de ter mais 3 tentativas
    while (contador >= 0) {
        cout << "Digite uma letra:" << "\n";
        cin >> letra;
        size_t pos = entrada.find(letra);
        if (pos != string::npos) {
            cout << "Letra presente na palavra!" << "\n";
            for (int i = 0; i < tamanho_str; i++) {
                if (entrada[i] == letra) {
                    palavra_forca[i] = letra;
                }
            }
        } else {
            cout << "Letra nao esta presente na palavra!" << "\n";
        }
        cout << "palavra: " << palavra_forca << "\n";
        if(palavra_forca==entrada){
            cout << "Parabens, voce acertou a palavra!" << "\n";
            break;
            }
        contador -= 1;
        cout << "Voce tem mais " << contador << " tentativas." << "\n";
    }
    return 0;
}
