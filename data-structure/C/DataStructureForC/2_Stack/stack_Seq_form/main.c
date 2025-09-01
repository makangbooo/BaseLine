#include <stdio.h>
#include "stdbool.h"

#define MaxSize 10

typedef int Element;

typedef struct Stack{
    int top;
    Element array[MaxSize];
}Stack;

//��ʼ��
void InitStack(Stack * stack){
    stack->top = -1;
}
//��ջ
bool Push(Stack * stack,Element e){
    //�ж��Ƿ����
    if(stack->top+1 == MaxSize)
        return false;
    stack->top++;
    stack->array[stack->top] = e;
    return 1;
}
//��ջ
Element Pop(Stack *stack){
    if(stack->top == -1){
        printf("ջ�գ���");
    }else{
        Element e = stack->array[stack->top];
        stack->top--;
        return e;
    }
}
//��ӡջ
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
