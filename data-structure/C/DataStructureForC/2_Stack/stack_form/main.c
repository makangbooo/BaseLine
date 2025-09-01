#include <stdio.h>
#include <stdbool.h>
#include "stdlib.h"

typedef int Element;

typedef struct Node{
    Element date;
    struct Node *next;
}theStack,*Stack;

void Init_stack(Stack stack){
    stack->next = NULL;
}

//入栈
bool Push(Stack stack,Element e){
    struct Node * node = malloc(sizeof(Element));
    if(node == NULL)
        return false;
    node->date = e;
    node->next = stack->next;
    stack->next = node;
    return true;
}

Element Pop(Stack stack){
    struct Node * p;
    p = stack->next;
    int e = p->date;
    stack->next = stack->next->next;
    return e;
}
//打印
void Print(Stack stack){
    struct Node *p;
    p = stack->next;
    while(p != NULL){
        printf("%2d",p->date);
        p=p->next;
    }
    printf("\n");
}

int main() {
    theStack stack;
    Init_stack(&stack);
    for (int i = 1; i < 4; ++i) {
        Push(&stack,i*10);
    }
    Print(&stack);
    Pop(&stack);
    Print(&stack);
    return 0;
}
