#include <stdio.h>
#include "stdlib.h"
typedef char Elenment;

typedef struct TreeNode{
    Elenment element;
    struct TreeNode * left;
    struct TreeNode * right;
} * Node;

///1���������-�ݹ�
void preOrder(Node root){
    if(root == NULL)
        return;
    printf("%c",root->element);
    preOrder(root->left);
    preOrder(root->right);
}
//�о�����
void inOrder(Node root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%c",root->element);
    inOrder(root->right);
}

///2���������-�ǵݹ�     ����ջ
typedef struct StackNode{
    Node node;
    struct StackNode * next;
}* Stack;
//��ʼ��ջ
void initStack(Stack stack){
    stack->next = NULL;
}
//��ջ
_Bool push(Stack stack,struct TreeNode * treeNode){
    //ͷ�巨
    struct StackNode *Snode = malloc(sizeof(struct StackNode));
    Snode->node = treeNode;
    Snode->next = stack->next;
    stack->next = Snode;
    return 1;
}
//��ջ
Node pop(Stack stack){
    if(stack->next){    //ջ�ǿգ�����дʡȥ�ˣ��ж�ɾ�������һ��Ԫ���鷳�Ĳ���
        Node p;
        p = stack->next->node;
        stack->next = stack->next->next;
        return p;
    }
}
//�п�
_Bool isEmpty(struct StackNode stack){
    return stack.next == NULL;
}

//���ȳ�ʼ��һ��ջ���Ӹ��ڵ㿪ʼ����Ԫ�ز�ΪNULLʱ��ѹ��ջ�в���ӡԪ�أ�����ָ��rootָ�����������ظ�������
// ֱ���Ӹ��ڵ����������������������ϣ�����rootָ��ΪNULLʱ���������ڲ�whileѭ����ִ�г�ջ������root���գ�������rootָ�����ƣ���
// ����rootָ�������������ظ�����������ֱ��rootΪNULL��ջ��ʱ��������������

void preOrder_2(Node root){

    struct StackNode stack;
    initStack(&stack);
    while(root || !isEmpty(stack)){
        while(root){
            push(&stack,root);
            printf("%c",root->element);
            root = root->left;
        }
        root = pop(&stack);
        root = root->right;
    }
}



int main() {
    Node a = malloc(sizeof(struct TreeNode));
    Node b = malloc(sizeof(struct TreeNode));
    Node c = malloc(sizeof(struct TreeNode));
    Node d = malloc(sizeof(struct TreeNode));
    Node e = malloc(sizeof(struct TreeNode));

    a->element = 'A';
    b->element = 'B';
    c->element = 'C';
    d->element = 'D';
    e->element = 'E';

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = c->right = NULL;
    d->left = d->right = NULL;
    e->left = e->right = NULL;

    printf("����-�ݹ飺\n");
    preOrder(a);
    printf("\n����-�ǵݹ飺\n");
    preOrder_2(a);
    printf("\n����-�ݹ飺\n");
    inOrder(a);


}
