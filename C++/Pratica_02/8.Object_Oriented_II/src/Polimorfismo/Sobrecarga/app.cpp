#include <iostream>
using namespace std;
//exemplo de polimorfismo de sobrecarga
class Poly{
    public:
    int fator01,fator02;
    Poly(){
        this->fator01 = 0;
        this->fator02 = 0;
    }
    //sobrecarga em calcular
    int calcular(){ 
        return 0;
    }
    int calcular(int valor,int valor02){
        this->fator01 = valor;
        this->fator02 = valor02;
        return fator01*fator02;
    }

};
int main(){
    Poly obj;
    cout << obj.calcular() << "|" << obj.calcular(21,2) << "\n";
    return 0;
}