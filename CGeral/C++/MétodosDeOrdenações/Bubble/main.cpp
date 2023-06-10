#include <iostream>
#include <cstdlib>
#define ArraySize 10
using namespace std;
int main(int argc,char *argv[]){
    int *vetor = new int[ArraySize],aux;
    for(int i = 0;i<ArraySize;i++){
        vetor[i] = rand()+1;
    }
    for(int i = 0;i<ArraySize;i++){
        for(int j = 0;j<ArraySize-i-1;j++){
            if(vetor[j]>vetor[j+1]){
                aux = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    for(int i = 0;i<ArraySize;i++){
        cout << "Vetor[" << i << "]: " << vetor[i]<<"\n";
    }

    return 0;
}