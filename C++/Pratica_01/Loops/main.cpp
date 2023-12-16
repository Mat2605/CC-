#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    //as estrutuas de repetição continuam as mesmas das vistas em c
    //For,do While,while
    int pares = 0,impares = 0,num = 2,count = 0;
    for(int i = 0;i<=100;i++){
        //todo for apresenta uma variável de controle,uma condição,e um incremento
        //o loop será realizado até a condicional se tornar verdadeira
        //caso isso nunca ocorra,teremos um loop infinito
        //a instrução break pode parar o loop a qualquer momento,excesso de breaks pode ser um problema
        if(i%2==0){
            pares+=1;
        }else{
            impares+=1;
        }
    }
    cout << "Total de valores pares de 0 a 100: " << pares << "\n" << "Total de valores Impares de 0 a 100: " << impares <<"\n";
    //Outras maneiras de escrever o for
    /*
    int i = 0;
    for(;i<10;){
        i++;
        Tanto o incremento quanto a inicialização são feitas fora do cabeçario da funçaõ for

    }
    for(;;){
        //for infinito,apenas break pode parar o loop
    }
    */
   for(;;){

        num*=num;

        count+=1;
        if(num>30000){
            break;
        }
   }
   cout << "Total de Laços para que num passem de 30000: " << count << "\n";
   //Tanto While quanto do-While seguem a mesma fórmula;
   //while executa o bloco de código quando a condicional for verdadeira,usado para realizar um número impreciso de repetições
   //do{}while(condicional) semelhante ao while
    return 0;
}