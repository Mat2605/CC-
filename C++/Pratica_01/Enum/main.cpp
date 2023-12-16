#include <iostream>
using namespace std;
int main(int argc,char *argv[]){
    //cada valor presente em enum equivale a um inteiro
    //enum é um conjunto de constantes inteiras 
    //que especificam um valor que uma varíavel desse tipo pode ter
    enum cores{vermelho,amarelo,verde};
    //é sequencial a partir do elemento anterior,caso enum cores{vermelho == 1000,amarelo,verde};
    //amarelo assumiria o valor de 1001
    //cada valor presente equivale a um inteiro,vermelho == 0,amarelo == 1,e assim por diante.
    //atribuir uma cor a um número que o usuário digitou
    int entrada,cor_atribuida;
    cout << "Digite um valor inteiro qualquer: " << "\n";
    cin >> entrada;
    if(entrada%10 == 0){
        cor_atribuida = vermelho;
    }else if(entrada % 2 != 0){
        cor_atribuida = amarelo;
    }else if(entrada % 2 == 0){
        cor_atribuida = verde;
    }
    if(cor_atribuida==vermelho){

        cout << "A cor atribuida foi vermelho!" << "\n";

    }else if(cor_atribuida == amarelo){

        cout << "A cor atribuida foi amarela!" << "\n";

    }else{
        cout << "A cor atribuida foi verde!" << "\n";
    }
    return 0;
}