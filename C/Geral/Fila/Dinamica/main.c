#include <stdio.h>
#include <stdlib.h>
#define MAX 100
 
struct node
{
    int data;
    struct node *link;
}*front, *rear;
 
// function protypes
void insert();
void delete();
void queue_size();
void check();
void first_element();
 
void main()
{
    int choice, value;
 
    while(1)
    {
        printf("Entre com a opcao escolhida\n");
        printf("1 : Criar uma Fila \n2 : Inserir Elemento\n");
        printf("3 : Retirar Elemento\n4 : Checar se pilha esta vazia\n");
        printf("5. Primeiro elemento da fila\n");
        printf("6. Quantos elementos na pilha\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        switch (choice)   
        {
        case 1: 
            printf("Pilha vazia com essa capacidade %d\n", MAX);
            break;
        case 2:    
            insert();
            break;
        case 3: 
            delete();
            break;
        case 4: 
            check();
            break;
        case 5: 
            first_element();
            break;
        case 6: 
            queue_size();
            break;
        case 7: 
            exit(0);
        default: 
            printf("Opcao inválida\n");
            break;
        }
    }
}
 
// to insert elements in queue
void insert()
{
    struct node *temp;
 
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Entre com um valor \n");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (rear  ==  NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }    
}
 
// delete elements from queue
void delete()
{
    struct node *temp;
 
    temp = front;
    if (front == NULL)
    {
        printf("Fila vazia \n");
        front = rear = NULL;
    }
    else
    {    
        printf("Elemento removido %d\n", front->data);
        front = front->link;
        free(temp);
    }
}
 
// check if queue is empty or not
void check()
{
    if (front == NULL)
        printf("\nFila Vazia\n");
    else
        printf("*************** Elementos presente na fila **************\n");
}
 
// returns first element of queue
void first_element()
{
    if (front == NULL)
    {
        printf("**************** Fila Vazia ****************\n");
    }
    else
        printf("**************** Primeiro Elemento %d ***********\n", front->data);        
}
 
// returns number of entries and displays the elements in queue
void queue_size()
{
    struct node *temp;
 
    temp = front;
    int cnt = 0;
    if (front  ==  NULL)
    {
        printf(" Fila Vazia \n");
    }
    while (temp)
    {
        printf("%d  ", temp->data);
        temp = temp->link;
        cnt++;
    }
    printf("********* Tamanho da fila: %d ******** \n", cnt);
}