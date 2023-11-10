#include <stdio.h>
#include <stdlib.h>
 
#define MAX 10
void quick_sort(int *a, int esq, int dir) {
    int i, j, x, y;
     
    i = esq;
    j = dir;
    x = a[(esq + dir) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < dir) {
            i++;
        }
        while(a[j] > x && j > esq) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esq) {
        quick_sort(a, esq, j);
    }
    if(i < dir) {
        quick_sort(a, i, dir);
    }
}
 

int main(void){
    int i, vet[MAX];
 
    for(i = 0; i < MAX; i++){
        vet[i] = i*i - 100;}
 
    quick_sort(vet, 0, MAX - 1);
 
    for(i = 0; i < MAX; i++){
    printf("%d\n", vet[i]);}
    system("PAUSE");
    return 0;
}
 