#include <iostream>
using namespace std;
struct estrutura{
    char c;
    unsigned int i;
    unsigned int i2;
};
int main(){
    //formas de inicialização
    //por padrão:
    estrutura e;
    //por cópia:
    estrutura e2 = {'a',1,2};
    estrutura e3 = {'b'}; //outros campos com 0
    //direta:
    estrutura e4{'2',3,4};
    //essa ultima declaração é o mesmo que:
    estrutura e5{.c = 'c',.i = 12,.i2=23}; //se um campo não for inicializado receberá defaul/0.

    return 0;
}