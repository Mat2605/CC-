#include <iostream>
using namespace std;
int x = 3; // não está na pilha, variável global
struct A {
    int k; // estará na pilha dependendo de onde A for instanciado
};

int main(){
    //Nenhum componente armazenado dentro da pilha não é válido fora do seu escopo
    int y = 3; // na pilha
    char z[] = "abc"; // na pilha
    A a; // na pilha
    void* ptr = malloc(4); //na pilha
    return 0;
}