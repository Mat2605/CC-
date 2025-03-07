// Queue implementation in C

#include <stdio.h>
#define SIZE 100

void enQueue(int);
void deQueue();
void display();

int items[SIZE], front = -1, rear = -1;

int main() {
  deQueue();
  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);
  enQueue(6);
  display();
  deQueue();
  display();

  return 0;
}

void enQueue(int value) {
  if (rear == SIZE - 1)
    printf("\nFila Cheia!!");
  else {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = value;
    printf("\nInserido -> %d", value);
  }
}

void deQueue() {
  if (front == -1)
    printf("\nFila Vazia!!");
  else {
    printf("\nDeletado : %d", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

// Function to print the queue
void display() {
  if (rear == -1)
    printf("\nFila vazia!!!");
  else {
    int i;
    printf("\nElementos da Fila:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}