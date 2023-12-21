#include <iostream>
using namespace std;
int main(){
    int a1; // inicialização padrão
    int a2(2); // inicialização direta
    int a3(0); // inicialização direta
    // int a4(); // a4 is a function
    int a5 = 2; // de cópia
    int a6 = 2u; // de cópia
    int a7 = int(2); //lista de cópia
    int a8 = int(); //de cópia
    int a9 = {2}; // lista de cópia
    int b1 = {2}; //inicialização direta com lista

    //Conversão de tipos: 

    int b4 = -1; // ok
    int b5{-1}; // ok
    unsigned b6 = -1; // ok
    //unsigned b7{-1}; // erro
    float f1{10e30}; // ok
    float f2 = 10e40; // ok
    //float f3{10e40}; // erro

   
    return 0;
}