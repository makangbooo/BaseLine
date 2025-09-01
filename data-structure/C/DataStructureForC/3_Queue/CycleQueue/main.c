#include <stdio.h>
#include <malloc.h>

///这里说的循环队列是只针对顺序存储的，链式存储绝大多数情况下不需要担心内存，不用通过循环链表去控制内存

typedef struct Queue {
    int *array;
    int capacity;
    int front, rear;
} Queue;

//初始化
_Bool initQueue(Queue *queue) {
    queue->array = malloc(sizeof(int) * 10); //这里开辟的内存，sizeof中的是类型，不是指针，有时再给一个结构体开辟内存时容易写成指针！！
    if (queue->array == NULL)
        return 0;
    queue->capacity = 10;
    queue->front = queue->rear = 0;
    return 1;
}

//入队
_Bool offerQueue(Queue *queue, int e) {
    //先判断队列是否已经满了
    if ((queue->rear + 1) % queue->capacity == queue->front)
        return 0;
    //rear先后移 再插入
    queue->rear = (queue->rear + 1) % queue->capacity;    //环形队列
    queue->array[queue->rear] = e;
    return 1;
}
//判空
_Bool isEmpty(Queue queue) {
    if (queue.rear == queue.front) {
        return 1;
    }else{
        return 0;
    }
}
//出队    只是逻辑上删除了，真正的队头元素是front的下一位
int pollQueue(Queue *queue){
    queue->front = (queue->front+1)%queue->capacity;
    return queue->array[queue->front];
}

//打印(重要！！)
_Bool printQueue(Queue queue) {
    if(isEmpty(queue))
        return 0;
    printf("<<<");
    int pos = queue.front;  //要记住front下标的值并没有值，真正的队头是front的下一个下标，也就是front+1
    do {
        pos = (pos + 1) % queue.capacity;
        printf("%3d", queue.array[pos]);
    } while (pos != queue.rear);
    printf("  <<<\n");
    return 1;
}


int main() {
    Queue queue;
    initQueue(&queue);
    for (int i = 0; i < 3; ++i) {
        offerQueue(&queue,i);
    }
    printQueue(queue);
    do{
        printf("%3d",pollQueue(&queue));
    }while(queue.front!=queue.rear);
    printQueue(queue);
    return 0;
}
