#include <iostream>
#include <stack>
//Biblioteca com as funções pop e push
using namespace std;
int main(int argc,char *argv[]){
    int resposta = 3;
    stack <string> cores;
    stack <string> aux;
    //uma pilha com células strings denominada "cores"

    cores.push("Amarelo");
    //função para inserir um elemento 
    cores.push("Vermelho");
    cores.push("Verde");
    //Ordem na pilha Verde --> Vermelho --> Amarelo.
    do{
        cout << "[1] --> Ver o tamanho da pilha " << "\n";
        cout << "[2] --> Ultimo elemento inserido " << "\n";
        cout << "[3] --> Zerar a pilha " << "\n";
        cout << "[4] --> Printar a pilha" << "\n";
        cin >> resposta;
        if(resposta==1){
            cout << "Tamanho: " << cores.size() << "\n";
        }else if(resposta==2){
            cores.swap(aux);
            cout << "Ultimo elemento: " << aux.top() << "\n";
            aux.pop();
        }else if(resposta==3){
            cout << "Pilha Zerada " << "\n";
            while(!cores.empty()){
                cores.pop();
            }
        }else if(resposta==4){
            cores.swap(aux);
            while(!aux.empty()){
                cout << "[" << aux.top() << "]" << "\n";
                aux.pop();
            }
        }


    }while((resposta!=3)&&(resposta!=4));
    return 0;
}