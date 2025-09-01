#include <stdio.h>
#include "stdlib.h"

/**汉诺塔结构*/
typedef struct Hanoi{
    struct Node* start; //第一个杆子
    struct Node* mid; //第二个杆子
    struct Node* end; //第三个杆子
}Hanoi;

/**结点*/
typedef struct Node{
    int n;  //表示方块大小
    struct Node *next;
}Node;

/**打印汉诺塔*/
void PrintList(Node* head){
    if(head->next!=NULL){
        Node* pMove = head->next;
        while (pMove){
            printf("%d",pMove->n);
            pMove = pMove->next;
        }
    }
    printf("\n");
}


/**初始化汉诺塔*/
Hanoi * initHanoi(int n){
    if(n<0){
        return NULL;
    }

    Hanoi *myHanoi = (Hanoi*)malloc(sizeof(Hanoi));

    /**初始化汉诺塔就是给第一个杆子A赋值*/
    myHanoi->start = (Node*)malloc(sizeof(Node));
    myHanoi->start->n = 113;    //A的ASCII值
    myHanoi->start->next = NULL;
    for (int i = n; i > 0; --i) {   //本质是以start为头指针利用头插法建立单链表
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->n = i;
        temp->next = myHanoi->start->next;
        myHanoi->start->next = temp;
    }

    /**B杆*/
    myHanoi->mid = (Node*)malloc(sizeof(Node));
    myHanoi->mid->n = 114;  //B的ASCII值
    myHanoi->mid->next = NULL;

    /**C杆*/
    myHanoi->end = (Node*) malloc(sizeof(Node));
    myHanoi->end->n = 115;  //C的ASCII值
    myHanoi->end->next = NULL;

    return myHanoi;
}


int main() {
    Hanoi *myHanoi = initHanoi(2);
    PrintList(myHanoi->start);
    return 0;
}
