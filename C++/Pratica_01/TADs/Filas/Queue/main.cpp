#include <iostream>
#include <queue>
using namespace std;
int main(int argc,char *argv[]){
    //estrutura de armazenamendo de dados,semelhante a uma fila real
    //o primeiro a entrar também é o primeiro a sair
    queue <int> inteiros;
    //push(): Insere um elemento no final da fila (back)
    //pop(): Remove o elemento do início da fila (front)
    //front(): Retorna uma referência para o elemento do início da fila
    //back(): Retorna uma referência para o elemento do final da fila
    //Verifica se a fila está vazia. Retorna true se estiver vazia, caso contrário, retorna false
    //size(): Retorna o número de elementos na fila
    //emplance(): implementação de tipos não primitivos
    //swap():transfere o conteúdo de um para outra fila
    inteiros.push(20);
    //primeiro da fila
    inteiros.push(21);
    inteiros.push(22);
    cout << "[" << inteiros.front() << "]\n";
    cout << "[" << inteiros.back() << "]\n";
    cout << "[" << inteiros.size() << "]\n";
    while(!inteiros.empty()){
        cout << "[" << inteiros.front() << "]\n";
        inteiros.pop();
    }

    
    return 0;
}