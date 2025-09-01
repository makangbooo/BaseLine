#include <stdio.h>
#include <stdlib.h>
/**
 * 二、线性表-链式存储
 *      1、定义解释
 *      2、初始化
 *      3、插入、删除
 * */


/**
 * 1、定义和解释
 * */
//官方定义
typedef struct LNode{
    int data;       //数据域
    struct LNode *next;     //结点的指针域
}LNode,*LinkList;       //LinkList为指向结构体LNode的指针类型

/**解释定义:

                            struct LNode{
                                ElemType data;                      //每个节点存放一个数据元素
                                struct LNode *next;                 //指向下一个节点
                            };
                            typedef struct LNode LNode;             //节点
                            typedef struct LNode * LinkList;        //指针

                            以上，因此可有两种声明头指针L的方式
                                LNode *L;                           //加*代表指针
                                LinkList L;                         //LinkList本身就是指针
 */


/**
 * 2、初始化：带头结点 & 不带头结点
 *      这里的初始化并不是指建立一个链表。   建立单链表 = 初始化 + 头插法/尾插法
 * */
//1、不带头节点
LinkList InitList(LinkList L){
    L = NULL; //这里好像没用,确实没用
    return L;
};

//2、带头结点（默认）
_Bool InitList_head(LinkList L){
/*    L = malloc(sizeof(LNode));       //生成新结点作为头结点，用头指针L指向头结点
    if(L==NULL)
        return 0;       */                    //分配失败
    L->next = NULL;                         //头结点的指针域置空
    return 1;
};
    ///这里需要注意!!!!!!!!!!!!!!!!!!!!!!
    void Init(LinkList L){
        L->next = NULL;     //这里对于链表的初始化只需一句就可
    }

    _Bool init_2(LinkList L) {  //此代码不能运行
        L = malloc(sizeof(LNode));    ///这里之所以会报错可能是因为这里的定义的L与传入的指针L冲突，导致传入的L无效！！！！！！！！
        if(L==NULL)
            return 0;
        L->next = NULL;
        return 1;
    }
    /*接上述代码，是不是可以这样理解，就是在main里定义一个链表指针L，然后L有了个专属的内存地址，main通过这个地址去对应L。
     然后我第二种初始化的话在函数里重新给L了一段地址，并一顿操作，但main里还是用他原先定义时的地址指向L，在main里L的基地址一直没变。
     导致虽然我传了个指针但效果还是形参没有改变实参。*/

    _Bool init_3(LinkList L){
        LinkList s;
        s = malloc(sizeof(LNode));
        s->data = 9999;
        s->next = NULL;
        *L = *s;    //这里可以运行可能是因为，单独L代表指针，*L和*s代表结点，将节点值s的值赋给L，而不是给L重新分配指针
        return 1;
    }



/**
 * 3、插入、删除
 * */
///1、尾插法(带头结点)   O(n)
LinkList List_TailInsert(LinkList L){      //用户在函数内输入
    int x;
    L=malloc(sizeof(LNode));      //建立头节点     虽然说是LinkList L 但这里的单独一个L并不是指针 这里单独的L为结点
    LNode *s,*r=L;  //s指向待插入结点，r为尾指针
    scanf("%d",&x);
    while (x!=9999){    //用户输入9999结束插入操作
        s=(LNode *) malloc(sizeof(LNode));
        s->data=x;
        r->next=s;      //是指将原表的最后一个元素指针域指向新增节点
        r=s;            //然后尾指针r向后移一位
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}
///2、头插法建表(其实就是对头节点L进行尾插法)
LinkList List_HeadInsert(LinkList L){
    LNode *s;
    int x;
    scanf("%d",&x);
    while(x!=9999){     //用户输入9999结束插入操作
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;    //将新节点s设置为第一个元素
        L->next=s;      //头节点L指针域指向s
        scanf("%d",&x);     //用户输入下一个待插入x
    }
    return L;
}//             应用如 逆置一个链表，可以从链表中逐一取出值然后在用头插法建立一个新的链表

///3、插入     ListInsert(&L,i,e)
_Bool ListInsert(LinkList L,int i,int e){
    if(i<1)
        return 0;   //输入i值不合理
    LNode *p;   //定义指针p用来指向待插入位置前一结点
    int j=0;
    p=L;    //定义p最初指向头节点                                    留意，只能改变L的指针，！！！！
    while (p!=NULL&&j<i-1) {    //采用循环将p指向待插入位置前一个结点
        p = p->next;
        j++;
    }
    if(p==NULL)
        return 0;   //i值不合理
    LNode *s = (LNode *)malloc(sizeof(LNode));  //节点s为待插入节点
    s->data=e;  //具体插入操作代码实现
    s->next=p->next;
    p->next=s;
    return 1;
}
///4、指定节点的后插操作   O（1）
_Bool InsertNextNode(LNode *p,int e){
    if(p==NULL)
        return 0;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL)
        return 0;   //内存分配失败
    s->data=e;
    s->next=p->next;    //将新节点s插入链表中p结点后
    p->next=s;
    return 1;
}
///5、指定节点的前插操作
_Bool InsertPriorNode(LNode *p,int e){  //时间复杂度为O(1),没有循环
    if(p==NULL)
        return 0;
    LNode *s = (LNode *)malloc(sizeof(LNode));  //为新节点分配空间
    if(s==NULL)
        return 0;   //分配失败
    s->next=p->next;
    p->next=s;  //将新节点加入链表中
    s->data=p->data;
    p->data=e;  //将新节点与p结点交换数据域实现逻辑上的前插操作
    return 1;

}
/**
 * 删除与查找
 * */
 ///1、按位序删除  ListDelete(&L,i,e)
_Bool ListDelete(LinkList L,int i,int *e){
    if(i<1)
        return 0;       //输入i值不合法
    LNode *p,*q;       //本质是 定义一个指针
    p = L;              //p指向头节点
    int j=0;        //用来标记当前位置
    while(p!=NULL&&j<i-1){      //让p指向被删结点前一位
        p=p->next;
        j++;
    };
    if(p==NULL||p->next==NULL)
        return 0;   //i值不合法
    q=p->next;//q指向待删除结点
    *e=q->data;
    p->next=q->next;//改变删除结点前驱结点的指针域
    free(q);//释放删除结点的空间
    return 1;
}
///2、删除指定节点p                     和3差不多，但这里会有bug
_Bool DeleteNode(LNode *p){
    if(p==NULL)
        return 0;
    LNode *q=p->next;    //这里q是一个指针
    p->data=q->data;    //这里有bug，因为如果q是最后一个结点的话，q所指向结点无意义为NULL
    p->next=q->next;
    free(q);
    return 1;
}
///3、按位查找       GetElem(L,i)
LNode *GetElem(LinkList L,int i){          //经典注意，当i值超过所定义范围时，也会返回NULL；此条函数可以作为封装函数以供其他函数使用；
    if(i<0)
        return NULL;
    LNode *p;
    int j=0;
    p=L;
    while (p!=NULL&&j<i){
        p = p->next;
        j++;
    }
    return p;
}
///4、按值查找    LocateElem(L,e)
LNode *LocateElem(LinkList L,int e){    //在带头结点的单链表L中查找值为e的元素
    LNode *p = L->next;
    while(p!=NULL&&p->data!=e){     //while(p!=NULL)可替换成while(p)    顺链域向后扫描，直到p为空或p所指结点的数据域等于e
        p=p->next;
    }
    return p;//查找成功返回值为e的结点地址p，查找失败p为NULL
}
///注8、求表长  Length(L)
int LenthList(LinkList L){
    int len = 0;
    LNode *p = L;
    while (p->next!=NULL){
        p=p->next;
        len++;
    }
    return len;//题中长度
}

///输出操作      PrintList(L)
void PrintList(LinkList L){
    while (L->next!=NULL){
        L=L->next;
        printf("%3d",L->data);
    }
}

//                                          test
int main() {
/*    LinkList L1 = NULL;
    InitList(L1);   //此行代码无用，本质是形参无法改变实参*/


    //这里注意在定义一个L时尽量不要定义指针指针
    LNode L3;
    InitList_head(&L3);
        //                                  注：！！！！！！！！！！！！！！！！！！
            /*LinkList L;
            InitList_head(L);   //初始化错误，因为L在这本质是一个指针，而InitList_head中传入的虽然是指针但初始化的是它的复制L，它自身仍然为空指针  碟中谍？  */
    LNode L;
    InitList_head(&L);

    printf("-------------------------------1、头插法建立单链表---------------------------------\n");
    List_HeadInsert(&L);
    List_HeadInsert(&L3);
    //L= List_TailInsert(L);
    PrintList(&L);
    PrintList(&L3);

    /**
    printf("\n-------------------------------2、在第三个位置插入88-------------------------------\n");
    ListInsert(L,3,88);
    PrintList(L);

    printf("\n-------------------------------3、在88结点后插入99------------------------------------\n");
    LNode *p=L;
    int i=0;
    while(i<3){
        p=p->next;
        i++;
    }
    InsertNextNode(p,99);
    PrintList(L);

    printf("\n-------------------------------4、用LocateElem函数找结点88，并在前插入77------------------------------------\n");
    LNode *q= LocateElem(L,88);
    InsertPriorNode(q,77);
    PrintList(L);

    printf("\n-------------------------------5、删除第5个元素------------------------------------\n");
    int x;
    ListDelete(L,5,&x);
    printf("被删元素值为：%d\n",x);
    PrintList(L);

    printf("\n-------------------------------6、删除指定结点3------------------------------------\n");
    LNode *z= LocateElem(L,3);
    DeleteNode(z);
    PrintList(L);

    printf("\n-------------------------------7、按位查找第2个元素------------------------------------\n");
    LNode *a= GetElem(L,2);
    printf("第二个元素的值为：%d\n",a->data);

    printf("\n-------------------------------8、按值查找 LocateElem(L,e)------------------------------------\n");
    LNode *b= LocateElem(L,4);

    if(b!=NULL) {
        printf("值为4的b存在于L中\n");
    }else {
        printf("没有值为4的元素！！");
    }

    LNode *c = LocateElem(L,8);
    if(c!=NULL){
        printf("值为8的c存在于L中\n");
    }else{
        printf("没有值为8的元素！！");
    }
    printf("\n-------------------------------9、按值查找 LocateElem(L,e)------------------------------------\n");

    printf("\n-------------------------------x、此时表长：------------------------------------\n");
    printf("此时表长为：%d", LenthList(L));
     */

    return 0;
}


/**
 * 补充：=和==
 *          1、=为赋值运算符
 *          2、==为逻辑运算符
 *
 *      注：if(x=1)和if(x==1)
 *              if(x=1)在任何情况下都为true,是将1赋值为x,各类语言中 非0即1 故绝大多数情况下都为true
 *              if(x==1)是条件判断,如果x等于1则为true,否则false
 *         在一名合格的程序员眼里，’等于‘ 不是 ’=‘ 而是 ’==‘
 * */
