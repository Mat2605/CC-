#include <iostream>
using namespace std;
int f(int *value){
    return *value * 40;
}
void g(int& value){
    cout << value << "\n";
}
int main(){
    //declaração de ponteiros para inteiros
    int *ptr,i = 100,*ptr02;
    //recebe o endereço de memória de uma variável
    ptr = &i;
    //acessar o valor
    i +=1; // acessando pelo ponteiro, o valor também é atualizado
    cout << *ptr << "\n";
    //ponteiro void recebe qualquer ponteiro
    void *newPtr = ptr;
    //conversão necessária
    ptr02 = (int *) newPtr;
    //ponteiros para um conjunto de valores
    int *ptr03 = new int[5];
    ptr03[0] = 1;
    ptr03[1] = 2;
    ptr03[2] = 3;
    ptr03[3] = 4;
    ptr03[4] = 5;
    cout << (ptr03[0]) << '\n';
    //passagem de referências
    int c = 2;
    int& d = c;
    int& e = d;
    e+=1;
    d+=1;
    cout << c << "\n"; // será 4 
    //passagem por referência
    cout << f(&c) << "\n";
    //sem &/ a passagem diretamente sendo um inteiro também retorna um erro
    g(c);

    return 0;
}