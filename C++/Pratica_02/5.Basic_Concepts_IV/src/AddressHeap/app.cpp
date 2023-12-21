#include <iostream>
using namespace std;
struct MyStruct{
    char conteudo;
};

int main(){
    //Tipos de alocação dinâmica
    int* value = new int; 
    int* array = new int[5]; //vetor
    MyStruct* estruturas = new MyStruct[5]; //vetor de estruturas
    int* vetores = new int[5]();
    delete value;
    delete[] array;
    //Alocação dinâmica de matriz
    int** A = new int*[3];
    for (int i = 0; i < 3; i++){
        A[i] = new int[4]; 
    }
    for (int i = 0; i < 3; i++){
        delete[] A[i];
    } 
    delete[] A;
    return 0;
}