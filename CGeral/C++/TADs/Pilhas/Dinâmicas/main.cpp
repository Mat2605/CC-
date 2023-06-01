//Refazer aqui!
#include <iostream>
#include <string>
using namespace std;

typedef struct Componente{

    string caracteres;
    int matricula;
    //vai apontar para o elemento debaixo
    struct Componente *upper;

}Componente;

//Número de elementos na pilha
int pilhaContador;
//apontador para topo
void NewPilha(){
    pilhaContador = 0;

}
void pop(Componente *ptr){
    if(ptr==NULL){
        cout << "A pilha esta vazia!" << "\n";
    }else{
        Componente *aux = new Componente;
        aux = aux->upper;
        delete aux;
        cout << "Removido!" << "\n";
    }

}
Componente *push(string caracteres,int inteiro){

    Componente *key = new Componente;
    key->caracteres.assign(caracteres);
    key->matricula = inteiro;
    key->upper = NULL; 
    pilhaContador+=1;
    return key;


}
bool PilhaisEmpty(){
    if(pilhaContador==0){
        return true;
    }else{
        return false;
    }
}
int TamanhoPilha(){
    return pilhaContador;
}
void imprimir_Pilha(Componente *ptr){
    Componente *aux = new Componente;
    aux = ptr;
    while(aux->upper!=NULL){
        cout << "[" << aux->caracteres << "][" << aux->matricula <<"]" << "\n";
        aux = aux->upper;
    }

}


int main(int argc,char *argv[]){
    //estrutura para o armazendo de dados
    //sua particularidade consiste no fato de que o elemento a ser retirado é sempre o último a ser inserido
    //Dois tipos dinâmica e estática,um com um tamanho variável e outro fixo.
    //Dinâmica é formado por células ou struct
    Componente *ptr;
    NewPilha();


    return 0;

}