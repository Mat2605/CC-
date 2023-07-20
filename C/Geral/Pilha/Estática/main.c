#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Constante para o tamanho do array
#define N 1000

// inicializa o topo como -1
int top = -1;

//array
int stack[N];

void push();       // Alocar
int pop();         // Remover
int peek();        // Retorna o elemento no topo da pilha
bool isEmpty();    // Se a pilha está vazia
bool isFull();

void push(){
    if(top == N-1)
        printf("Processo negado,Pilha cheia\n");
    else{
        int x;
        printf("Entre com um elemento: ");
        scanf("%d", &x);
        top+=1;
        stack[top] = x;
    }
}

int pop(){
    if(top == -1)
        printf("Processo negado,pilha vazia\n");
    else{
        int x = stack[top];
        printf("%d Removido\n", x);
        top-=1;
        return x;
    }
    return -1;
}

int peek(){
    int x = stack[top];
    printf("%d é o elemento no topo da pilha\n", x);
    return x;
}

bool isEmpty(){
    if(top == -1){
        printf("Pilha vazia\n");
        return true;
    }
    printf("Pilha não está vazia\n");
    return false;
}

bool isFull(){
    if(top == N-1){
        printf("Pilha cheia\n");
        return true;
    }
    printf("Pilha não está cheia\n");
    return false;
}   

int main(void){
    printf("Capacidade total:%d\n", N);
    int choice;

    while(1){
        printf("\nMenu com operaçoes para interação com a pilha:\n");
        printf(" 0: Exit            1: Push            2: Pop            3: Topo\n");
        printf(" 4: Pilha vazia     5: Checar pilha cheia\n\n");
        scanf("%d", &choice);

        switch(choice){
            case 0: exit(0);
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: isEmpty(); break;
            case 5: isFull(); break;
            default: printf("Opção inválida!\nPor favor tente novamente.\n");
        }
    }
    return 0;
}


