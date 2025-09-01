#include <stdio.h>
#include "stdbool.h"

#define MaxSize 10

typedef int Element;

typedef struct Stack{
    int top;
    Element array[MaxSize];
}Stack;

//≥ı ºªØ
void InitStack(Stack * stack){
    stack->top = -1;
}
//»Î’ª
bool Push(Stack * stack,Element e){
    //≈–∂œ «∑Ò¥Ê¬˙
    if(stack->top+1 == MaxSize)
        return false;
    stack->top++;
    stack->array[stack->top] = e;
    return 1;
}
//≥ˆ’ª
Element Pop(Stack *stack){
    if(stack->top == -1){
        printf("’ªø’£°£°");
    }else{
        Element e = stack->array[stack->top];
        stack->top--;
        return e;
    }
}
//¥Ú”°’ª
void Print(Stack stack){
    while(stack.top!=-1){
        printf("%3d",stack.array[stack.top]);
        stack.top--;
    }
    printf("\n");
}

int main() {
    Stack stack;
    InitStack(&stack);
    for (int i = 0; i < 3; ++i) {
        Push(&stack,i*10);
    }
    Print(stack);
    Pop(&stack);

    Print(stack);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    return 0;
}
