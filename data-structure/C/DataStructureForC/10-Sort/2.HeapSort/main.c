#include <stdio.h>
#include <malloc.h>
#include "stdbool.h"

/**大根堆*/

typedef int E;

typedef struct Heap{
    E * arr;    //动态数组
    int size;   //当前元素个数
    int capacity;   //最大容量
} * MaxHeap;
//初始化
bool initMaxHeap(MaxHeap heap){
    heap->size = 0;
    heap->capacity = 10;
    heap->arr = malloc(sizeof(E)*heap->capacity);
    return heap->arr != NULL;
}
//插入
bool insertHeap(MaxHeap heap,E e){
    if(heap->size >= heap->capacity) return false; //堆满了
    int index = ++heap->size;   //先找出待插入位置，注意数组第一个位置不储存元素，下标从1开始，因此待插入位置为 arr[++heap->size]
    //然后开始向上堆化，知道符合规则位置
    while(index>1 && e > heap->arr[index/2]){
        heap->arr[index] = heap->arr[index/2];
        index /= 2;
    }
    //现在得到的index就是最终位置了
    heap->arr[index] = e;
    return true;
}
//删除    本质是出队操作（删除最大的元素）
E DeHeap(MaxHeap heap){
    E max = heap->arr[1] , e = heap->arr[heap->size--];  //第一步：取出 堆顶元素和堆尾元素，并将堆内存数减一
    int index = 1;
    while(index * 2 <= heap->size){ //保证当前index的结点至少有一个子节点
        int child = index * 2;  //先找到左孩子
        //看看右孩子和左孩子哪个大，先选一个大的出来
        if(child < heap->size && heap->arr[child] < heap->arr[child+1]){    //哪个孩子大，用那个孩子顶替，谁大谁顶上
            child += 1;
        }
        if(e >= heap->arr[child]) break;    //堆尾元素大于此时元素，就跳出循环，并将堆尾元素插入到index处
        else heap->arr[index] = heap->arr[child];
        index = child;  //更新index的值
    }
    heap->arr[index] = e;
    return max;
};

//打印堆
void PrintHeap(MaxHeap heap){
    for (int i = 1; i <= heap->size; ++i) {
        printf("%3d",heap->arr[i]);
    }
};

int main() {
    struct Heap heap;
    initMaxHeap(&heap);
    insertHeap(&heap,5);
    insertHeap(&heap,2);
    insertHeap(&heap,3);
    insertHeap(&heap,7);
    insertHeap(&heap,6);
    PrintHeap(&heap);
    printf("\n");
    DeHeap(&heap);
    PrintHeap(&heap);
    return 0;
}
