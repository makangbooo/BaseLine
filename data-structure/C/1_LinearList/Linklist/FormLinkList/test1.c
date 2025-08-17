#include <stdio.h>
#include "stdbool.h"
#include "stdlib.h"

typedef int E;
typedef struct Node{
    E data;
    struct Node *next;
}List,*LinkList;
//初始化
bool InitList(LinkList L){
    L->next = NULL;
    return 1;
}
//插入（头插法）
bool Insert_head(LinkList L,E e){
    struct Node * node = malloc(sizeof(struct Node));
    if(node == NULL)
        return 0;
    node->next = L->next;
    node->data = e;
    L->next = node;
    return 1;
}
//插入（尾插法）
bool Insert_tail(LinkList L,E e){
    struct Node *node = malloc(sizeof(struct Node));    //node代表待插入结点
    if(node == NULL)
        return 0;
    node->data = e;
    struct Node *p; //p代表位置辅助指针
    p = L;
    while(p->next != NULL)
        p = p->next;
    node->next = p->next;
    p->next = node;
    return 1;
}
//在第i个位置插入
bool InsertList_(LinkList L,int i,E e){
    struct Node *node = malloc(sizeof(struct Node));
    if(node == NULL)
        return 0;
    node->data = e;

    struct Node *p; int n = 1;
    p = L;
    while(n<i && p->next!=NULL){
        n++;
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    return 1;

}
//打印
void PrintList(LinkList L){
    struct Node *p;
    p = L->next;
    while(p != NULL){
        printf("%d",p->data);
        p = p->next;
    }
}

int test() {
    List L;
    InitList(&L);
    E x;

    //测试尾插法
    scanf("%d",&x);
    while(x!=9999){
        Insert_tail(&L,x);
        scanf("%d",&x);
    }
    PrintList(&L);
    //
    // //测试头插法
    // scanf("%d",&x);
    // while(x!=9999){
    //     Insert_head(&L,x);
    //     scanf("%d",&x);
    // }
    // PrintList(&L);
    //
    // //在第i个位置插入
    // InsertList_(&L,4,0);
    // PrintList(&L);

    return 0;
}
