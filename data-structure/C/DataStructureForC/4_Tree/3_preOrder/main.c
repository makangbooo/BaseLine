#include <stdio.h>
#include "stdlib.h"
typedef char Elenment;

typedef struct TreeNode{
    Elenment element;
    struct TreeNode * left;
    struct TreeNode * right;
} * Node;

///1、先序遍历-递归
void preOrder(Node root){
    if(root == NULL)
        return;
    printf("%c",root->element);
    preOrder(root->left);
    preOrder(root->right);
}
//列举中序
void inOrder(Node root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%c",root->element);
    inOrder(root->right);
}

///2、先序遍历-非递归     借用栈
typedef struct StackNode{
    Node node;
    struct StackNode * next;
}* Stack;
//初始化栈
void initStack(Stack stack){
    stack->next = NULL;
}
//入栈
_Bool push(Stack stack,struct TreeNode * treeNode){
    //头插法
    struct StackNode *Snode = malloc(sizeof(struct StackNode));
    Snode->node = treeNode;
    Snode->next = stack->next;
    stack->next = Snode;
    return 1;
}
//出栈
Node pop(Stack stack){
    if(stack->next){    //栈非空，这样写省去了，判断删除是最后一个元素麻烦的步骤
        Node p;
        p = stack->next->node;
        stack->next = stack->next->next;
        return p;
    }
}
//判空
_Bool isEmpty(struct StackNode stack){
    return stack.next == NULL;
}

//首先初始化一个栈，从根节点开始：当元素不为NULL时，压入栈中并打印元素，而后将指针root指向其左子树重复操作，
// 直到从根节点出发的所有左子树遍历完毕（即当root指向为NULL时），跳出内层while循环，执行出栈操作用root接收（本质是root指针上移），
// 并让root指向其右子树，重复上述操作，直到root为NULL且栈空时完成先序遍历操作

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

    printf("先序-递归：\n");
    preOrder(a);
    printf("\n先序-非递归：\n");
    preOrder_2(a);
    printf("\n中序-递归：\n");
    inOrder(a);


}
