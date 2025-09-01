#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
/**
 *     队列：只允许在一端插入，在另一端删除的线性表（先进先出）（头出尾入）
 *        队头：只能出队
 *        队尾：只能入队
 * */

 /**一、顺序存储*/
/*定义*/
typedef struct{
    int data[MaxSize];          //用静态数组存放队列元素
    int front,rear;             //在rear处增加，front处删除
}SqQueue;
//判断队列是否为空
_Bool QueueEmpty(SqQueue Q){
    if(Q.rear==Q.front)
        return 1;
    else
        return 0;
}
//判断队列是否为满
_Bool QueueFill(SqQueue Q){
    if((Q.rear+1)%MaxSize==Q.front)     //这里对MaxSize 取模 而不是 加一，是因为要保证内存地址一致，使rear和front始终保持在MaxSize内存范围内“转圈移动”
        return 1;
    else
        return 0;
}

//入队
_Bool EnQueue(SqQueue *Q,int x){
    if(QueueFill(*Q))
        return 0;
    Q->data[Q->rear]=x;
    Q->rear=(Q->rear+1)%MaxSize;        //取模运算
    return 1;
}
//出队                                    //注意：这里的删除也只是逻辑上的删除，物理上仍然存在，循环队列的本质就是数据在内存上的反复覆盖。
_Bool DeQueue(SqQueue *Q,int *x){
    if(QueueEmpty(*Q))
        return 0;
    *x=Q->data[Q->front];
    Q->front=(Q->front+1)%MaxSize;
    return 1;
}

/**链式存储*/
//定义
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode,*Linklist;

typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

//初始化（带头结点）
void InitLinkQueue_head(LinkQueue *Q){
    Q->front=Q->rear=(LinkNode *)malloc(sizeof(LinkNode));      //rear和front都指向头节点。
    Q->front->next=NULL;    //front是指向头节点，队头元素为Q->front->next->data;
}
//初始化（不带头结点）
void InitLinkQueue(LinkQueue *Q){
    Q->rear=NULL;
    Q->front=NULL;
}
//判断队列是否为空
_Bool IsEmpty(LinkQueue Q){
    if(Q.front==NULL)
        return 1;
    else
        return 0;
}
//入队(带头结点)
void EnLinkQueue_head(LinkQueue *Q,int e){
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=e;
    s->next=NULL;
    Q->rear->next=s;
    Q->rear=s;
}
//入队（不带头结点）
void EnLinkQueue(LinkQueue *Q,int e){
    LinkNode  *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data=e;
    s->next=NULL;
    if(Q->front==NULL){             //在空队列中插入第一个元素
        Q->front=s;                 //修改队头队尾指针
        Q->rear=s;
    } else{
        Q->rear->next=s;
        Q->rear=s;
    }
}
//出队(带头结点)
_Bool DeLinkQueue(LinkQueue *Q,int *e){
    if(Q->front==Q->rear)
        return 0;
    LinkNode *p=Q->front->next;         //写成*e=Q->front->next->data;更容易理解
    *e=p->data;                         //其中Q->front为头节点
    Q->front->next=p->next;
    if(Q->rear==p)
        Q->rear=Q->front;
    free(p);
    return 1;
}





int main() {
    printf("Hello, World!\n");
    return 0;
}
