#include <iostream>
#include <string>
using namespace std;
void alterar_valor(int *num){
    *num = 10;
}
void alterar_valor(string *palavra){

    *palavra = "Padrao";
    
}
int main(int argc,char* argv[]){
    int valor = 5;
    string palavra = "Matheus";
    cout << "num> " << valor << "\n";
    cout << "Palavra> " << palavra << "\n";
    alterar_valor(&valor);
    alterar_valor(&palavra);
    cout << "num> " << valor << "\n";
    cout << "Palavra> " << palavra << "\n";


    //funções com o mesmo nome só que com parâmetros diferentes,exclusivo c++
    return 0;
}