#include <stdio.h>
#include <malloc.h>
#include "stdbool.h"

/**
 * 这里队列用到的链表和栈一样
 *           相同点是：都是在表头 （队头/栈顶） 取元素（出栈/出队）
 *           不同点是：栈是利用头插法插入新元素，队列是用尾插法插入新元素
 * */


typedef struct Node{
    int value;
    struct Node *next;
}* Node;

typedef struct Queue{
    Node front,rear;
}* LinkQueue;
//初始化
bool initQueue(LinkQueue queue){
    Node node = malloc(sizeof(struct Node));
    if(node == NULL)
        return false;
    //node->next = NULL;
    queue->rear = queue->front = node;
    return true;
}
//入队
bool offerQueue(LinkQueue queue,int e){
    Node node = malloc(sizeof(Node));
    node->value = e;
    //node->next = NULL;

    queue->rear->next = node;
    queue->rear = queue->rear->next;

/*    不能这样写
    queue->rear = queue->rear->next;
    queue->rear = node;*/

    return true;
};
//判空
bool isEmpty(LinkQueue queue){
    if(queue->rear == queue->front){
        return true;
    }else{
        return false;
    }
}
//出队
int pollQueue(LinkQueue queue){
    Node node = queue->front->next;
    int e = node->value;

    //这里需要判断是否为最后一个节点
    if(queue->front->next == queue->rear){
        queue->front = queue->rear;
    }else{
        queue->front->next = node->next;
    }
    //free(node);
    return e;
}
//打印队列
bool printQueue(LinkQueue queue){
    if(isEmpty(queue))
        return false;
    printf("<<<");
    Node p = queue->front;
    while(p != queue->rear){
        p = p->next;
        printf("%3d",p->value);
    }
    printf("<<<\n");
    return true;
}



int main() {
    struct Queue queue;
    initQueue(&queue);
    for (int i = 0; i < 3; ++i) {
        offerQueue(&queue,i);
    }
    printQueue(&queue);

    while (queue.rear!=queue.front){      ///这里注意，在一开始没有考虑到删除最后一个元素的情况，会把rear给删了，导致无限循环出错
        printf("%2d", pollQueue(&queue));
    }
    return 0;
}
