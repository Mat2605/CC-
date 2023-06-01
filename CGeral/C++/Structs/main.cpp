#include <iostream>
using namespace std;
//Agrupamento de tipos primitivos,criando um novo tipo de variável
typedef struct PrimeiraStruct{
    string caracteres;
    int inteiro;
}PrimeiraStruct;
int main(int argc,char *argv[]){
    //Declaração de uma struct direta na main
    PrimeiraStruct StructVariable;
    //se comporta como um novo tipo de variável
    //declaração direta|Receber valores via teclado
    StructVariable.caracteres = "Caracteres";
    StructVariable.inteiro = 26;
    cout << "String armazenada na estrutura: " << StructVariable.caracteres<< "\n";
    cout << "Inteiro armazenada na estrutura: " << StructVariable.inteiro<< "\n";

    system("cls");

    cout << "Digite uma string qualquer: " << "\n";
    cin >> StructVariable.caracteres;
    cout << "Digite um inteiro qualquer: " << "\n";
    cin >> StructVariable.inteiro;
    cout << "String armazenada na estrutura: " << StructVariable.caracteres<< "\n";
    cout << "Inteiro armazenada na estrutura: " << StructVariable.inteiro<< "\n";
    
    return 0;
}