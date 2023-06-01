#include <iostream>
using namespace std;
int main(int argc,char *argv[]){
    //passar argumentos do programa a partir da linha de comando
    //argc --> guarda o número de parametros informados
    //argv --> ponteiro para uma matriz strings;
    /*
    pode ser útil em várias situações, como quando você precisa que o usuário forneça 
    informações adicionais para o seu programa durante a execução, ou quando você deseja 
    executar diferentes partes do programa com base em diferentes argumentos passados na linha de comando.
    */
    //entrada apenas de caracteres
    cout << "argv[0]==>" << argv[0] << "\n";
    cout << "argv[1]==>" << argc << "\n";
    //imprime o nome do programa,conta como parametro para argc
    return 0;

}