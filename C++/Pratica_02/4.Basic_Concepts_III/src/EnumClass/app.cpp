#include <iostream>
using namespace std;
int main(){
    //são ordenados em ordem aritmética
    enum class DIAS {DOMINGO,SEGUNDA,TERCA,QUARTA,QUINTA,SEXTA,SABADO};
    enum class CORES {VERMELHO,VERDE,PRETO,BRANCO,AZUL};
    DIAS d = DIAS::DOMINGO; //declaração
    CORES c = CORES::VERMELHO; //declaração
    //bool comp = (c==d);  retornara um erro de compilação
    bool Comp = (((int)c)==((int)d)); //agora a comparação é possível, ocorre com os índices,retorna true
    cout << Comp << "\n";
    cout << (CORES::VERMELHO < CORES::VERDE) << "\n"; //outra forma de comparação,retorna true
    cout << (CORES::VERMELHO > CORES::VERDE) << "\n"; //retorna false
    //alterando a ordem de enumeração
    //0,1,-1,0,1
    enum class NovaEnum {A,B,C = -1,D,E};
    NovaEnum e = NovaEnum::C;
    cout << ((int)e) << "\n";
    e = NovaEnum::D;
    cout << ((int)e) << "\n";

    return 0;
}