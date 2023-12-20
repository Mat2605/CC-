#include <iostream>
using namespace std;

int main(){
    enum DIAS {DOMINGO,SEGUNDA,TERCA,QUARTA,QUINTA,SEXTA,SABADO};
    enum CORES {VERMELHO,VERDE,PRETO,BRANCO,AZUL};
    DIAS var = DOMINGO,var02 = SABADO;
    CORES flag = VERMELHO;
    cout << var <<" | " << flag << "\n"; //Retorna o índice da constante
    cout << (var==QUARTA) << "\n"; // false
    cout << (var==flag) << "\n"; //vai retornar true
    cout << (var < var02) << "\n"; // a comparação é feita a partir dos índices

    return 0;
}