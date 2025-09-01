#include <stdio.h>
#include <stdlib.h>
/**
 * 双链表 & 循环双链表
 *       一、定义和初始化
 *       二、插入
 * */

/**
 * 1、定义和解释
 * */
//官方定义
typedef struct DuNode{           //Double Node:DNode
    int data;
    struct DuNode *next;
    struct  DuNode *prior;
}DuNode,*DuLinkList;

/**
 * 2、初始化：双链表 & 循环链表
 * */
//双链表的初始化   双向链表
DuLinkList InitDuLinkList_n(DuLinkList L){
    L = (DuNode*) malloc(sizeof(DuNode));
    L->next=NULL;
    L->prior=NULL;
    return L;
};

//循环双链表初始化
DuLinkList InitDuLinkList(DuLinkList L){
    L=(DuNode *)malloc(sizeof(DuNode));
    if(L==NULL)
        return 0;
    L->prior = L;
    L->next = L;
    return L;
}
///双向链表长度(带头指针)
int Length(DuLinkList L){
    DuNode *p;
    p = L;
    if(p->next==L) {
        printf("长度为0");
        return 0;
    } else {
        int j = 0;
        while (p->next != L) {
            j++;
            p = p->next;
        }
        return j;
    }
}


/**
 * 3、插入、删除
 * */
//双链表 在p结点之后插入新节点s
_Bool InsertNextDuNode(DuNode *p,DuNode *s){
    if(p==NULL||s==NULL){
        return 0;
    }
    s->next=p->next;
    s->prior=p;
    p->next=s;
    return 1;
}

///在带头结点的双向链表L中查找第i个元素，返回结点的地址
DuNode* GetElemP_DuL(DuLinkList L,int i){
    int j = 1;
    DuNode *p;
    p = L->next;
    while (j<i){
        p=p->next;
        ++j;
    }
    return p;
}
///在带头结点的双向链表L中第i个位置之前插入元素e，i的合法值为1<=i<=表长+1 (循环双链表)
_Bool ListInsert_DuL(DuLinkList L,int i,int e){
    DuNode *s,*p;
    s = (DuNode*) malloc(sizeof (DuNode));
    s->data = e;
    if(!(p = GetElemP_DuL(L,i))) {  //在L中确定第i个元素的位置指针p
        return 0;
    }
    if(i==1){   //在双向链表的第一个元素上插入
        p = L->next;    //原先双向链表的第一个元素
        L->next = s;
        s->prior = L;
        s->next = p;
        p->prior = s;
    } else if(i == Length(L)){  //在双向链表的最后一个元素上插入
        p = L;
        while (p->next!=L)
            p = p->next;    //将p指向双向链表结尾
        p->next = s;
        s->prior = p;
        s->next = L;
    } else {
        s->next = p;
        s->prior = p->prior;
        p->prior->next = s;
        p->prior = s;
    }
    return 1;


}

///补充：循环单链表的初始化    跟单链表一样
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
_Bool InitLinkList_c(LinkList L){
    L = (LNode *) malloc(sizeof(LNode));
    if(L==NULL)
        return 0;
    L->next=L;
    return 1;
};
_Bool InitList_head(LinkList L){
    L=(LNode *)malloc(sizeof(LNode));       //生成新结点作为头结点，用头指针L指向头结点
    if(L==NULL)
        return 0;                           //分配失败
    L->next = NULL;                         //头结点的指针域置空
    return 1;
};
//判断循环单链表是否为空
_Bool isEmpty(LinkList L){
    if(L->next==L)
        return 1;
    else
        return 0;
}
//判断节点p是否为循环单链表的表尾节点
_Bool isTail(LinkList L,LNode *p){
    if(p->next==L)
        return 1;
    else
        return 0;
}



int main() {
    DuLinkList L = InitDuLinkList(L);
    if(ListInsert_DuL(L,1,99)){
        printf("插入成功！！！\n");
    } else{
        printf("插入失败！！！\n");
    };
    int a = Length(L);
    printf("表长为%d\n",a);
    printf("第一个元素值为：%d",L->next->data);


    return 0;
}
