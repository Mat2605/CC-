#include <iostream>
using namespace std;
int somatorio(int valor_inicial, int incremento, int n, int contador) {
    if (contador == n) {
        return valor_inicial;
    } else {
        return somatorio(valor_inicial + incremento, incremento, n, contador + 1);
    }
}
int fatorial(int fat){
    if(fat==0){
        return 1;
    }else{
        return fat * fatorial(fat-1);
    }
}

int main(int argc,char *argv[]){
    //uma função que chama a si mesma.
    int resultado = somatorio(2, 3, 4, 0);
    cout << "Somatório: " << resultado;
    cout << "Fatorial: " << fatorial(5);
    return 0;
}