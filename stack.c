#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct  Node* next;
}Node;
Node* push(Node* top,int value)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = top;
    return new_node;
}
Node* pop(Node* top)
{
    Node* temp = top;
    top = top->next;
    free(temp);
    return top;
}
int peek(Node* top)
{
    return top->data;
}
int main(void)
{
    Node* stack = NULL;
    stack = push(stack, 1);
    stack = push(stack, 2);
    stack = push(stack, 3);
    stack = pop(stack);
    stack = pop(stack);
    printf("%d\n",peek(stack));
    return 0;
}