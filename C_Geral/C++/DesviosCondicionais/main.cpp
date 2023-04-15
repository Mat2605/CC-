#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
int main(){
    //as estruturas condicionais seguem a forma das feitas em c
    char nota;
    bool condicional = false;
    int valor,num;
    //comando goto
    //trabalha com desvio do fluxo do programa,alternativa para as intruções de loop
    loop:
    cout << "Digite uma nota: " << "\n";
    cout << "Caso queira encerrar a inserção de notas digite X" << "\n";
    cin >> nota;
    if(nota=='F'){
        cout << "Aluno Reprovado!"<< "\n";
        goto loop;
    }else if(nota=='E'){
        cout << "Aluno está de recuperação!"<< "\n";
        goto loop;
    }else if(nota<'E'){
        cout << "Aluno está aprovado!"<<"\n";
        goto loop;
    }else{
        cout << "Loop Encerrado..." <<"\n";
   
    }
    //operadores lógicos >,<,>=,<=,==,!=
    if(!condicional){
        cout << "Condicional contém false!"<< "\n";
    }else{
        cout << "Condicional contém true";
    }
    /////////////////////////////
    system("cls");
    //comando para limpar a tela.
    //and,or,not são os operadores lógicos
    //representados por &&,||,!
    cout << "Digite um valor aleatório: " << "\n";
    cin >> valor;
    if((valor<10)&&(valor%2==0)){
        cout << " O valor digitado é menor do que 10 e é par" <<"\n";
    }else if((valor<10)&&(valor%2!=0)){
        cout << " O valor é menor do que 10 e é impar" << "\n";
    }
    //condicional ternário,uma forma mais reduzida de um if,condicionais mais simples.
    //Variável que recebera um valor vindo de uma condição,condição,valor caso seja true,valor caso seja false
    num = (valor<10) ? 20 : 5;
    //caso valor for menor do que 10,num assume o valor de 20,caso contrátrio num recebe 5
    cout << "Valor de num: " <<num <<"\n";
    system("cls");
    //Switch - Case,mesma estrutura utilizada em C
    cout << "Digite a opção que deseja fazer: " << "\n";
    cout << "[1] -> Adição; " << "\n";
    cout << "[2] -> Multiplicação por 10; " << "\n";
    cout << "[3] -> Potência de 10;" << "\n";
    cin >> num;
    cout << "Digite um valor aleatório: " << "\n";
    cin >> valor;
    switch (num)
    {
    case 1:
        valor = 2*valor;
        cout << "Encerrando..." << "\n";
        break;
    case 2:
        valor = valor*10;
        cout << "Encerrando..." << "\n";
        break;
    case 3:
        valor = pow(valor,10);
        cout << "Encerrando..." << "\n";
        break;
    default:
        cout << "Encerrando..." << "\n";
        break;
    }
    cout << "Valor Final: " <<valor <<"\n";
    system("pause");
    return 0;

}