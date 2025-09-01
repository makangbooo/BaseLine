#include <stdio.h>
#include <malloc.h>
/**
 *栈:只允许在一端插入和删除的线性表（后进先出）
 *      栈顶：允许插入删除的一端
 *      栈底：不允许插入删除的一端
 * */

/**
 * 1、顺序存储（自动分配 直接data[MaxSize]）
 * */
#define MaxSize 10          //定义栈中元素的最大个数
typedef struct SqStack {
    int data[MaxSize];     //静态数组存放栈中元素
    int top;               //栈顶指针
} SqStack;                  //sq : sequence 顺序

//初始化
void InitSqStack(SqStack *S) {
    S->top = -1;              //初始化栈顶指针,这里也可能是栈顶元素的下一位，可以为-1也可以为0；
}

//入栈
_Bool Push(SqStack *s, int x) {
    if (s->top == MaxSize - 1)   //表示栈满
        return 0;
    s->top++;               //指针先后移一位
    s->data[s->top] = x;      //新元素入栈     和上一句可合并为：   S->data[++S->top]=x;
    return 1;
}

//出栈                        这里并不是物理删除，而是逻辑删除，因为并没有对原栈顶元素清除，还是残留在内存的，只是指针下移
_Bool Pop(SqStack *s, int *x) {
    if (s->top == -1)
        return 0;
    *x = s->data[s->top];
    s->top--;
    return 1;
}

//读取栈顶元素
_Bool GetTop(SqStack *s, int *x) {
    if (s->top == -1)
        return 0;
    *x = s->data[s->top];
    return 1;
}

/**
 * 2、手动分配的顺序存储（需要mallo）
 * */
typedef struct Stack {
    int top;
    int *array;
    int capacity;
} Stack;

//初始化
Stack initStack(Stack *stack) {
    stack->top = -1;    //这里需要特别留意
    stack->capacity = 10;
    stack->array = malloc(sizeof(int) * 10);
    return *stack;
}

//入栈
_Bool PushStack(Stack *stack, int e) {

    //首先要判断栈是否满了
    if (stack->top + 1 >= stack->capacity) {    //现有数据大于等于容量
        //开始扩容 ()
        /* realloc函数可以做到控制动态内存开辟的大小，重新申请的内存空间大小就是我们指定新的大小，
         * 并且原有的数据也会放到新申请的空间中， 所以非常地方便。当然如果因为内存不足之类的原因导
         * 致的内存空间申请失败，那么会返回NULL，所以别忘了进行判断    */
        int newCapacity = stack->capacity + (stack->capacity >> 1);   //1.5倍  >>1 : 右移一位就是除以2的意思
        int *newArray = realloc(stack->array, newCapacity * sizeof(int));
        if (newArray == NULL) return 0;
        stack->array = newArray;
        stack->capacity = newCapacity;
        printf("扩容成功，当前容量为%d\n", stack->capacity);
    }

    //入栈操作
    stack->top++;
    stack->array[stack->top] = e;
    return 1;
}

//判断是否为空
_Bool isEmpty(Stack stack) {
    if (stack.top == -1) {
        return 1;
    } else {
        return 0;
    }
    //一句喝成：  return stack.top == -1;
}

//出栈
int popStack(Stack *stack) {
    int a = stack->array[stack->top];
    stack->top--;
    return a;
}

//打印栈
void PrintStack(Stack stack) {
    for (int i = 0; i < stack.top + 1; ++i) {
        printf("\n%3d\n", stack.array[i]);
    }
}


/**
 * 3、共享栈、
 */
typedef struct {
    int data[MaxSize];
    int top0;               //0号栈栈顶指针
    int top1;               //1号栈栈顶指针
} ShareStack;

//初始化
void InitShareStack(ShareStack *S) {
    S->top0 = -1;
    S->top1 = MaxSize;        //这里指向MaxSize就是栈外和-1一样
}


/**
 * 3、链式存储   链栈中的 top指针 就是 头指针
 */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkStack;

//初始化
void InitStack(LinkStack stack) {
    stack->next = NULL;
}

//入栈
_Bool pushLinkStack(LinkStack stack, int e) {  //头插法建立链栈
    LNode *node = malloc(sizeof(struct LNode));
    node->data = e;
    node->next = stack->next;
    stack->next = node;
    return 1;
}

//出栈
int popLinkStack(LinkStack stack) {
    LNode *p = stack->next;
    int e = p->data;
    stack->next = stack->next->next;
    return e;
}

//打印（从栈顶->栈底打印）
void PrintLinkStack(LinkStack stack) {
    LNode *p = stack->next;
    while (p != NULL) {
        printf("%3d", p->data);
        p = p->next;
    }

}


int main() {
    ///顺序栈
    Stack stack;
    stack = initStack(&stack);
    //入栈测试
    for (int i = 0; i < 11; ++i) {
        PushStack(&stack, i * 10);
    }
    PrintStack(stack);
    //出栈测试
    while (!isEmpty(stack)) {   //要考虑到是否为空
        printf("\n栈顶出栈：%d\n", popStack(&stack));
    }
    PrintStack(stack);

    ///链栈
    struct LNode LinkStack;
    InitStack(&LinkStack);
    //入栈
    for (int i = 0; i < 11; ++i) {
        pushLinkStack(&LinkStack, i * 10);
    }

    PrintLinkStack(&LinkStack);
    //出栈
    while (LinkStack.next != NULL)
        printf("链栈栈顶出战%3d", popLinkStack(&LinkStack));
    return 0;

}
