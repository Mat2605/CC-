#include <iostream>
#define pi 3.14
int valor1;
//variável global.
//definir uma constante,se mantém durante a execução do programa
using namespace std;
int main(){

    //Tipo Nome = Valor Inicial;
    //Cada variável apresenta o seu escopo,seja global ou local.
    //incrementos e decrementos seguem o mesmo padrão;
    //pré e pós fixado:
    //antes de printar incrementa a variável,printa e depois incrementa.
    int num = 26;
    //valor 32 bits
    //variável local.
    char vogal = 'M';
    //armazena um byte
    double flutuante = 26.05;
    //flutuante ou double,sendo o double mais preciso e com maior espaço de armazenamento.
    bool condicional = true;
    //armazena true ou false,resultado de desvios condicionais,imprime 1 para true e 0 para falso.
    unsigned int num_positivo;
    //unsigned para valores positivos;
    long int maior_valor;
    unsigned short int menor_valor;
    string caracteres = "Matheus";
    //em c++ string é uma variável já definida,armazena texto.
    //printar as variáveis:
    cout << num << "\n";
    cout << vogal << "\n";
    cout << pi << "\n";
    cout << flutuante << "\n";
    cout << caracteres << "\n";
    cout << condicional << "\n";
    //Ou: cout << num << "\n"<< vogal << "\n"<<flutuante << "\n"<< caracteres << "\n"<< condicional << "\n"
    //comando para entrada de dados ==> cin,muda a direção dos apontadores.
    cout << "Digite dois valores:"<<"\n";
    cin >> maior_valor >> menor_valor;
    cout << maior_valor + menor_valor<< "\n";


    return 0;
}