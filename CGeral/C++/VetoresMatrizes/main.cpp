#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
int main(){
    //a declaração estática de vetores e matrizes continuam as mesmas
    int matriz[1][10],array1[5],array2[5],aux1 = 0,aux2 = 0,*vetor,**Matriz;
    for(int i = 0;i<5;i++){
        array1[i] = i;
        array2[i] = i*2;
        cout << "Array2[" << i << "]:"<< array2[i] << "\n";
        cout << "Array1[" << i << "]:"<< array1[i] << "\n";
    }
    for(int i = 0;i<10;i++){
        if(i%2==0){
            matriz[0][i] = pow(array2[aux2],i);
            aux2+=1;
        }else{
            matriz[0][i] = array1[aux1] *2;
            aux1 +=1;
        }
        
        cout << "Matriz[" << i << "]:" << matriz[0][i] << "\n";
    }
    system("cls");
    return 0;
}
