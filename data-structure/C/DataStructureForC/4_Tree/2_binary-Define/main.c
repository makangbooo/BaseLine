#include <stdio.h>
#include "stdlib.h"
typedef char Elenment;

typedef struct TreeNode{
    Elenment element;
    struct TreeNode * left;
    struct TreeNode * right;
} * Node;


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
    printf("%c", a->left->left->element);
}
