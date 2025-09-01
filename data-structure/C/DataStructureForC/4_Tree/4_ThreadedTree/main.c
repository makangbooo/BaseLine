#include <stdio.h>
#include "stdlib.h"

typedef char E;
typedef struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int leftTag,rightTag;   //标志位，如果为1表示这一边指针指向的是线索，不为1就是正常的孩子结点
}* Node;
//初始化结点
Node creatNode(E element){
    Node node = malloc(sizeof(struct TreeNode));
    node->element = element;
    node->left = NULL;
    node->right = NULL;
    node->leftTag = 0;
    node->rightTag = 0;
    return node;
}

///线索化  本质步骤：其实就是进行了一次(先/中/后)序遍历

//先码出其先序遍历
void preOrderThreaded_1(Node root){
    if(root == NULL) return;
    preOrderThreaded_1(root->left);
    preOrderThreaded_1(root->right);
}

//补全线索化代码
Node pre = NULL;    //工具指针 pre用来指向当前线索化的节点的上一个结点
void preOrderThreaded(Node root){
    if(root == NULL) return;

    if(root->left == NULL){
        root->left = pre;
        root->leftTag = 1;
    };
    if(pre && pre->right == NULL){  //pre不能为NULL且其右子树为空
        pre->right = root;
        pre->rightTag = 1;
    }
    pre = root; //

    if(root->leftTag == 0)
        preOrderThreaded(root->left);
    if(root->rightTag == 0)
        preOrderThreaded(root->right);
}

//在线索化之后再去遍历就不用借助栈了
void inOrder(Node root){
    while(root!=NULL){
        printf("%c",root->element);
        if(root->leftTag == 0)
            root = root->left;
        else
            root = root->right;
    }
}


int main() {
    Node a = creatNode('A');
    Node b = creatNode('B');
    Node c = creatNode('C');
    Node d = creatNode('D');
    Node e = creatNode('E');

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    preOrderThreaded(a);

    inOrder(a);

    return 0;
}
