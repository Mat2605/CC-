#include <stdlib.h>
#include <stdio.h>

typedef struct node_str
{
    int number;
    struct node_str* prev;
    
}node_t;

typedef node_t* node;

typedef struct stack_str
{
    node first;            
    
}stack_t;

typedef stack_t* stack;

node new_node(int num)
{
    node n;
    n=(node)malloc(sizeof(node_t));
    n->number = num;
    n->prev   = NULL;
    return n;
}

stack new_stack()
{
    stack s;
    s=(stack)malloc(sizeof(stack_t));
    s->first = NULL;
    return s;
} 

void add_stack_node(stack s , int num)
{
    node n = new_node(num);
    n->prev = s->first;
    s->first = n;
}

node_t extract_stack_node(stack s)
{
    node aux;
    node_t n;

    if (s->first != NULL)
    {
        aux = s->first;
        s->first = s->first->prev;
        n = *aux;
        free(aux);
    }
    return n;
}

void destroy_stack(stack s)
{
    node_t n;
    while(s->first != NULL)
    {
        n = extract_stack_node(s);
        printf("%d\n", n.number);
    }
    free(s);
}

int main()
{
    stack s = new_stack();
    add_stack_node(s,1);  
    add_stack_node(s,2);  
    add_stack_node(s,3);  
    add_stack_node(s,4);  
    extract_stack_node(s); //Elimina o 4
    printf("Pilha Final\n");
    destroy_stack(s);     
    return 0;
}