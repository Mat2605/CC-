#include <iostream>
#include <math.h>
using namespace std;
int main(){
    //os operadores básicos são iguais aos utilizados em c,+ - / * %;
    //funções presentes em math.h
    int inteiro = 100;
    int inteiro_negativo = -100;
    double decimal = 25.6;
    cout << "Valor do seno de decimal:" <<sin(decimal)<<"\n";
    cout << "Valor do cosseno de decimal:" <<cos(decimal)<<"\n";
    cout << "Valor da tangente de decimal:" <<tan(decimal)<<"\n";
    cout << "Valor da raiz quadrada de inteiro: " <<sqrt(inteiro)<<"\n";
    cout << "Valor do quadrado de inteiro: " <<pow(inteiro,2)<<"\n";
    cout << "Valor Absoluto de inteiro: " <<abs(inteiro_negativo)<<"\n";
    cout << "Valor da hipotenusa: " << hypot(2,3) << "\n";
    cout << "Valor absoluto de decimal: " <<floor(decimal)<<"\n";
    cout << "Valor absoluto de decimal: " <<fabs(decimal)<<"\n";
    cout << "Valor do arco cosseno inteiro: " <<acos(1)<<"\n";
    cout << "Valor do arco seno inteiro: " <<asin(1)<<"\n";
    cout << "Valor do arco tangente inteiro: " <<atan(1)<<"\n";
    cout << "Logaritmo Natural de inteiro:" << log(inteiro)<<"\n";
    cout << "Maior valor de decimal: " <<ceil(decimal)<<"\n";
    //Esta função retorna o menor inteiro como double, não menor que o argumento fornecido.


    return 0;
}