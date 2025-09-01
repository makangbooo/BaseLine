#include <stdio.h>
#include <stdlib.h>
/**
 * 王道
 *
 * 一、线性表-顺序存储
 *      1、初始化 动态分配顺序表
 *      2、顺序表的插入、删除操作
 *      3、查找：按值、按位
 * 视频课 2.2.1 - 2.2.2
 * */

/**
 * 1、定义和解释
 * */
/*注：静态分配定义*/
#define MaxSize1 50
typedef struct{
    int data[MaxSize1];
    int length;
}SqList;


/*注：动态分配定义*/
#define InitSize 5
typedef struct SeqList{
    int *data;  //基地址   对于数组得定义，都是定义基地址带指针类型
    int MaxSize;
    int length;
}SeqList;
/**
 * 2、初始化
 * */
void InitList(struct SeqList *L){
    L->data=(int *)malloc(InitSize*sizeof(int));        //这里初始化空间为10个int
    //这里之所以和链表中不一样，是因为链表中分配得是L得地址空间，会报错，而这里是给L中的data数组分配空间
    L->length=0;
    L->MaxSize=5;
}
//附：增加动态数组的长度空间   ！！！！！！！！！！！！！！！！！！！！！！！
void IncreaseSize(struct SeqList * L,int len){
    int *p=L->data;     //用指针p指向原表（数组），
    L->data=(int*)malloc((L->MaxSize+len)*sizeof(int));     //给L重新分配一个更大的空间
    for (int i = 0; i < L->length; ++i) {   //将p所指向的值逐个复制给新L;
        L->data[i]=p[i];
    }
    L->MaxSize+=len;
    free(p);    //这里，虽然说是增加数组长度，然而是新开辟一片更大的连续空间，借用p来指向老数组，然后将之前的空间中的数据转移过来，并释放p。
}

                                ///增删改查
/**
 * 插入:ListInsert(&L,i,e)
 * */
_Bool ListInsert(struct SeqList *L,int i,int e){
    if(i<1||i>L->length+1) {
        printf("插入数据不合法！！！\n");
        return 0;
    }
    if(L->length == L->MaxSize) {
        printf("当前存储空间已满！！！！\n");
        return 0;
    }
    for (int j = L->length; j >= i; --j) {  //这里是从表尾开始一个个往后挪
        L->data[j]=L->data[j-1];
    }
    L->data[i-1]=e; //将下标为i-1的位置挪出来并赋值e
    L->length++;
    return 1;
}
/**
 控制台 连续插入(表尾)
 */
void ListInsert_crtl(SeqList *L){
    int x=0;
    scanf("%d",&x); //从控制台输入并赋值给x
    while (x!=9999){    //当输入9999时跳出while循环
        L->data[L->length]=x;   //在表尾进行插入，下标为length-1
        L->length++;    //表长加1
        if(L->length == L->MaxSize) {   //插入过多导致表满，跳出循环
            printf("当前存储空间已满！！！！\n");
            return;
        }
        scanf("%d",&x); //给x重新赋值
    }
}
/**
 * 删除    ListDelete(&L,i,&e)
 * */
_Bool ListDelete(struct SeqList *L,int i,int *e){
    if(i<1||i>L->length) {
        printf("i值不合法！！！！");
        return 0;
    };
    *e=L->data[i-1];  //注：为啥这里要带*，而L不用带！！！！！！！！！！！
    for (int j = i; j <= L->length-1; ++j) {    //j表示被删元素后一位，j-1为被删元素
        L->data[j-1]=L->data[j];
    }
    L->length--;    //表长减1
    return 1;
}

/**
 * 按值查找    LocateElem(L,e)
 **/
int LocateElem(struct SeqList *L,int e){
    for (int i = 0; i < L->length; ++i) {
        if(L->data[i]==e){
            printf("值为%d的元素在第%d位\n",e,i+1);
            return i+1;
        };
    };
    printf("没有值为%d的元素\n",e);
    return 0;
}
/**
 * 按位查找    GetElem(L,i)
 **/
int GetElem(SeqList L,int i){         //这里SeqList前没有struct是因为在定义SeqList前typedef成了单独SeqList。
    if(i<1||i>L.length) {
        printf("线性表中没有第%d位\n",i);
        return 0;
    }
    printf("线性表中第%d位的值位%d\n",i,L.data[i-1]);
    return L.data[i-1];
}
/**
 * 输出操作      PrintList(L)
 */
void PrintList(SeqList L){
    for (int i = 0; i < L.length; ++i) {
        printf("%3d",L.data[i]);
    }
    return;
}

/**
 * 判空操作   Empty(L)
 **/
_Bool Empty_L(SeqList L){
    if(L.length==0)
        return 1;
    else
        return 0;
}

/**
 * 求表长        LengthList(L)
 **/
int LengthList(SeqList L){
    return L.length;
}
//销毁操作      DestoryList(&L)


int main(){
    /*一、动态分配顺序表初始化*/
    printf("__________________________________________1、初始化__________________________________________________\n");
        SeqList L;
        InitList(&L);
        printf("初始化线性表长度为%d、最大容量为%d\n",L.length,L.MaxSize);
    printf("__________________________________________2、增加动态数组的长度空间_____________________________________\n");
        IncreaseSize(&L,5);
        printf("扩容后线性表长度为%d、最大容量为%d\n",L.length,L.MaxSize);

    /*二、顺序表的插入、删除操作*/
    printf("\n_________________________________________3、插入____________________________________________________\n");
    printf("\n插入1:\n");
    ListInsert(&L,1,1);
    PrintList(L);
    printf("\n插入2:\n");
    ListInsert(&L,2,2);
    PrintList(L);

    printf("\n________________________________________4、控制台连续插入____________________________________________\n");
    ListInsert_crtl(&L);
    PrintList(L);

    printf("\n________________________________________5、删除____________________________________________________\n");
    int a=0;
    ListDelete(&L,3,&a);
    printf("\n删除的第三个元素的值为:%d\n删除第三个元素后:\n",a);
    PrintList(L);

    printf("\n________________________________________6、按值查找_________________________________________________\n");
    int *b=0;
    LocateElem(&L,9);

    printf("\n________________________________________7、按位查找_________________________________________________\n");
    GetElem(L,3);
    GetElem(L,10);

    printf("\n________________________________________8、表长____________________________________________________\n");
    printf("此时表长为：%d", LengthList(L));
    return 0;



}