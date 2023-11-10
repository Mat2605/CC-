#include <iostream>
#include <string>
using namespace std;
char meio_string(string palavra){
    int count = palavra.size();
    if(count==0){

        return '\0';

    }else{

        return palavra[count/2];

    }

}
string alterar_string(string *palavra){
    int count = (*palavra).size();
    for(int i = 0;i<count;i++){
        if(((*palavra)[i]=='a')||((*palavra)[i]=='e')||((*palavra)[i]=='i')||((*palavra)[i]=='o')||((*palavra)[i]=='u')){
            (*palavra)[i] = '_';
        }
    }
    return *palavra;
}
int* aumentar_valor(int *vetor,int tamanho){
    for(int i = 0;i<tamanho;i++){
        vetor[i] = vetor[i] * (i*3);
    }
    return vetor;

}
int main(int argc,char *argv[]){
    string palavra = "Matheus";  
    //necessária a alocação de memória nesse caso
    int* vetor_inteiros = new int[5];
    for(int i = 0;i<5;i++){
        vetor_inteiros[i] = 1+i;
    }
    //main já é uma função,recebe parametros e retorna um valor 0,indicando que o programa foi inicializado
    //função void ==> não retorna nenhum valor
    //passagem por parâmetro não altera o valor da variável globalmente,porém,por referencia o valor muda.
    //tipo de retorno,nome,parâmetro.
    //função simples,nenhuma alteração no valor da variável
    cout << "Caractere no meio da string: " << meio_string(palavra) << "\n";
    cout << "String alterada: " << alterar_string(&palavra);
    vetor_inteiros = aumentar_valor(vetor_inteiros,5);
    for(int i = 0;i<5;i++){
        cout << "[ " << vetor_inteiros[i] << "]"; 
    }
    cout << "\n";
    //passagem de referencia,uso de ponteiro
    return 0;

}
