#include <iostream> 
using namespace std;
class PrimeiraEmC;
class PrimeiraEmC{
    //componentes publicos
    public: 
    char primeiro_componente;
    string nomeCompleto;
    public: //métodos publicos
    void novocomponente(char c){
        this->primeiro_componente = c;
    }
    void atribuirnome(string s){
        this->nomeCompleto = s;
    }
    string retornarnome(){
        return this->nomeCompleto;
    }

};

int main(){
    PrimeiraEmC obj;
    obj.novocomponente('M');
    obj.atribuirnome("Matheus");
    cout << obj.primeiro_componente << "\n";
    cout << obj.retornarnome() << "\n";

    return 0;
}