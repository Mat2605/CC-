#include <iostream>
#include <string>
using namespace std;

struct Aluno{
    int matricula;
    float nota;
    string nome;


void InserirValores(Aluno *ptr, int inteiro, string caracteres, float flutuante){
    ptr->nota = flutuante;
    ptr->matricula = inteiro;
    ptr->nome = caracteres;
    cout << "Estrutura Inicializada com os valores inseridos!\n";
}

void imprimir(Aluno *ptr, int tamanho){
    for(int i = 0; i < tamanho; i++){
        cout << "String armazenada na estrutura: " << ptr[i].nome << "\n";
        cout << "Inteiro armazenado na estrutura: " << ptr[i].matricula << "\n";
        cout << "Flutuante armazenado na estrutura: " << ptr[i].nota << "\n";
    }
}
};

int main(int argc,char *argv[]){
    //Maneira Tradicional:
    Aluno *vetorAlunos = new Aluno[5];
    /*for(int i = 0; i < 5; i++){
        InserirValores(&vetorAlunos[i], i, "ABC", 1.5);
    }
    imprimir(vetorAlunos, 5);
    */
    //Declarar os métodos dentro da próprio struct
    for(int i = 0;i<5;i++){
        vetorAlunos[i].InserirValores(&vetorAlunos[i],i,"ABC",1.0);
    }
    vetorAlunos->imprimir(vetorAlunos,5);
    return 0;
}
