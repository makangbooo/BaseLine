#include <stdio.h>
#include <malloc.h>
/**
 *ջ:ֻ������һ�˲����ɾ�������Ա�����ȳ���
 *      ջ�����������ɾ����һ��
 *      ջ�ף����������ɾ����һ��
 * */

/**
 * 1��˳��洢���Զ����� ֱ��data[MaxSize]��
 * */
#define MaxSize 10          //����ջ��Ԫ�ص�������
typedef struct SqStack {
    int data[MaxSize];     //��̬������ջ��Ԫ��
    int top;               //ջ��ָ��
} SqStack;                  //sq : sequence ˳��

//��ʼ��
void InitSqStack(SqStack *S) {
    S->top = -1;              //��ʼ��ջ��ָ��,����Ҳ������ջ��Ԫ�ص���һλ������Ϊ-1Ҳ����Ϊ0��
}

//��ջ
_Bool Push(SqStack *s, int x) {
    if (s->top == MaxSize - 1)   //��ʾջ��
        return 0;
    s->top++;               //ָ���Ⱥ���һλ
    s->data[s->top] = x;      //��Ԫ����ջ     ����һ��ɺϲ�Ϊ��   S->data[++S->top]=x;
    return 1;
}

//��ջ                        ���ﲢ��������ɾ���������߼�ɾ������Ϊ��û�ж�ԭջ��Ԫ����������ǲ������ڴ�ģ�ֻ��ָ������
_Bool Pop(SqStack *s, int *x) {
    if (s->top == -1)
        return 0;
    *x = s->data[s->top];
    s->top--;
    return 1;
}

//��ȡջ��Ԫ��
_Bool GetTop(SqStack *s, int *x) {
    if (s->top == -1)
        return 0;
    *x = s->data[s->top];
    return 1;
}

/**
 * 2���ֶ������˳��洢����Ҫmallo��
 * */
typedef struct Stack {
    int top;
    int *array;
    int capacity;
} Stack;

//��ʼ��
Stack initStack(Stack *stack) {
    stack->top = -1;    //������Ҫ�ر�����
    stack->capacity = 10;
    stack->array = malloc(sizeof(int) * 10);
    return *stack;
}

//��ջ
_Bool PushStack(Stack *stack, int e) {

    //����Ҫ�ж�ջ�Ƿ�����
    if (stack->top + 1 >= stack->capacity) {    //�������ݴ��ڵ�������
        //��ʼ���� ()
        /* realloc���������������ƶ�̬�ڴ濪�ٵĴ�С������������ڴ�ռ��С��������ָ���µĴ�С��
         * ����ԭ�е�����Ҳ��ŵ�������Ŀռ��У� ���Էǳ��ط��㡣��Ȼ�����Ϊ�ڴ治��֮���ԭ��
         * �µ��ڴ�ռ�����ʧ�ܣ���ô�᷵��NULL�����Ա����˽����ж�    */
        int newCapacity = stack->capacity + (stack->capacity >> 1);   //1.5��  >>1 : ����һλ���ǳ���2����˼
        int *newArray = realloc(stack->array, newCapacity * sizeof(int));
        if (newArray == NULL) return 0;
        stack->array = newArray;
        stack->capacity = newCapacity;
        printf("���ݳɹ�����ǰ����Ϊ%d\n", stack->capacity);
    }

    //��ջ����
    stack->top++;
    stack->array[stack->top] = e;
    return 1;
}

//�ж��Ƿ�Ϊ��
_Bool isEmpty(Stack stack) {
    if (stack.top == -1) {
        return 1;
    } else {
        return 0;
    }
    //һ��ȳɣ�  return stack.top == -1;
}

//��ջ
int popStack(Stack *stack) {
    int a = stack->array[stack->top];
    stack->top--;
    return a;
}

//��ӡջ
void PrintStack(Stack stack) {
    for (int i = 0; i < stack.top + 1; ++i) {
        printf("\n%3d\n", stack.array[i]);
    }
}


/**
 * 3������ջ��
 */
typedef struct {
    int data[MaxSize];
    int top0;               //0��ջջ��ָ��
    int top1;               //1��ջջ��ָ��
} ShareStack;

//��ʼ��
void InitShareStack(ShareStack *S) {
    S->top0 = -1;
    S->top1 = MaxSize;        //����ָ��MaxSize����ջ���-1һ��
}


/**
 * 3����ʽ�洢   ��ջ�е� topָ�� ���� ͷָ��
 */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkStack;

//��ʼ��
void InitStack(LinkStack stack) {
    stack->next = NULL;
}

//��ջ
_Bool pushLinkStack(LinkStack stack, int e) {  //ͷ�巨������ջ
    LNode *node = malloc(sizeof(struct LNode));
    node->data = e;
    node->next = stack->next;
    stack->next = node;
    return 1;
}

//��ջ
int popLinkStack(LinkStack stack) {
    LNode *p = stack->next;
    int e = p->data;
    stack->next = stack->next->next;
    return e;
}

//��ӡ����ջ��->ջ�״�ӡ��
void PrintLinkStack(LinkStack stack) {
    LNode *p = stack->next;
    while (p != NULL) {
        printf("%3d", p->data);
        p = p->next;
    }

}


int main() {
    ///˳��ջ
    Stack stack;
    stack = initStack(&stack);
    //��ջ����
    for (int i = 0; i < 11; ++i) {
        PushStack(&stack, i * 10);
    }
    PrintStack(stack);
    //��ջ����
    while (!isEmpty(stack)) {   //Ҫ���ǵ��Ƿ�Ϊ��
        printf("\nջ����ջ��%d\n", popStack(&stack));
    }
    PrintStack(stack);

    ///��ջ
    struct LNode LinkStack;
    InitStack(&LinkStack);
    //��ջ
    for (int i = 0; i < 11; ++i) {
        pushLinkStack(&LinkStack, i * 10);
    }

    PrintLinkStack(&LinkStack);
    //��ջ
    while (LinkStack.next != NULL)
        printf("��ջջ����ս%3d", popLinkStack(&LinkStack));
    return 0;

}
