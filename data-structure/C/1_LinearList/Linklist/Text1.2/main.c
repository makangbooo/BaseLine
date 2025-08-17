#include <stdio.h>
#include <stdlib.h>
/**
 * �������Ա�-��ʽ�洢
 *      1���������
 *      2����ʼ��
 *      3�����롢ɾ��
 * */


/**
 * 1������ͽ���
 * */
//�ٷ�����
typedef struct LNode{
    int data;       //������
    struct LNode *next;     //����ָ����
}LNode,*LinkList;       //LinkListΪָ��ṹ��LNode��ָ������

/**���Ͷ���:

                            struct LNode{
                                ElemType data;                      //ÿ���ڵ���һ������Ԫ��
                                struct LNode *next;                 //ָ����һ���ڵ�
                            };
                            typedef struct LNode LNode;             //�ڵ�
                            typedef struct LNode * LinkList;        //ָ��

                            ���ϣ���˿�����������ͷָ��L�ķ�ʽ
                                LNode *L;                           //��*����ָ��
                                LinkList L;                         //LinkList�������ָ��
 */


/**
 * 2����ʼ������ͷ��� & ����ͷ���
 *      ����ĳ�ʼ��������ָ����һ������   ���������� = ��ʼ�� + ͷ�巨/β�巨
 * */
//1������ͷ�ڵ�
LinkList InitList(LinkList L){
    L = NULL; //�������û��,ȷʵû��
    return L;
};

//2����ͷ��㣨Ĭ�ϣ�
_Bool InitList_head(LinkList L){
/*    L = malloc(sizeof(LNode));       //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
    if(L==NULL)
        return 0;       */                    //����ʧ��
    L->next = NULL;                         //ͷ����ָ�����ÿ�
    return 1;
};
    ///������Ҫע��!!!!!!!!!!!!!!!!!!!!!!
    void Init(LinkList L){
        L->next = NULL;     //�����������ĳ�ʼ��ֻ��һ��Ϳ�
    }

    _Bool init_2(LinkList L) {  //�˴��벻������
        L = malloc(sizeof(LNode));    ///����֮���Իᱨ���������Ϊ����Ķ����L�봫���ָ��L��ͻ�����´����L��Ч����������������
        if(L==NULL)
            return 0;
        L->next = NULL;
        return 1;
    }
    /*���������룬�ǲ��ǿ���������⣬������main�ﶨ��һ������ָ��L��Ȼ��L���˸�ר�����ڴ��ַ��mainͨ�������ַȥ��ӦL��
     Ȼ���ҵڶ��ֳ�ʼ���Ļ��ں��������¸�L��һ�ε�ַ����һ�ٲ�������main�ﻹ������ԭ�ȶ���ʱ�ĵ�ַָ��L����main��L�Ļ���ַһֱû�䡣
     ������Ȼ�Ҵ��˸�ָ�뵫Ч�������β�û�иı�ʵ�Ρ�*/

    _Bool init_3(LinkList L){
        LinkList s;
        s = malloc(sizeof(LNode));
        s->data = 9999;
        s->next = NULL;
        *L = *s;    //����������п�������Ϊ������L����ָ�룬*L��*s�����㣬���ڵ�ֵs��ֵ����L�������Ǹ�L���·���ָ��
        return 1;
    }



/**
 * 3�����롢ɾ��
 * */
///1��β�巨(��ͷ���)   O(n)
LinkList List_TailInsert(LinkList L){      //�û��ں���������
    int x;
    L=malloc(sizeof(LNode));      //����ͷ�ڵ�     ��Ȼ˵��LinkList L ������ĵ���һ��L������ָ�� ���ﵥ����LΪ���
    LNode *s,*r=L;  //sָ��������㣬rΪβָ��
    scanf("%d",&x);
    while (x!=9999){    //�û�����9999�����������
        s=(LNode *) malloc(sizeof(LNode));
        s->data=x;
        r->next=s;      //��ָ��ԭ������һ��Ԫ��ָ����ָ�������ڵ�
        r=s;            //Ȼ��βָ��r�����һλ
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}
///2��ͷ�巨����(��ʵ���Ƕ�ͷ�ڵ�L����β�巨)
LinkList List_HeadInsert(LinkList L){
    LNode *s;
    int x;
    scanf("%d",&x);
    while(x!=9999){     //�û�����9999�����������
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;    //���½ڵ�s����Ϊ��һ��Ԫ��
        L->next=s;      //ͷ�ڵ�Lָ����ָ��s
        scanf("%d",&x);     //�û�������һ��������x
    }
    return L;
}//             Ӧ���� ����һ���������Դ���������һȡ��ֵȻ������ͷ�巨����һ���µ�����

///3������     ListInsert(&L,i,e)
_Bool ListInsert(LinkList L,int i,int e){
    if(i<1)
        return 0;   //����iֵ������
    LNode *p;   //����ָ��p����ָ�������λ��ǰһ���
    int j=0;
    p=L;    //����p���ָ��ͷ�ڵ�                                    ���⣬ֻ�ܸı�L��ָ�룬��������
    while (p!=NULL&&j<i-1) {    //����ѭ����pָ�������λ��ǰһ�����
        p = p->next;
        j++;
    }
    if(p==NULL)
        return 0;   //iֵ������
    LNode *s = (LNode *)malloc(sizeof(LNode));  //�ڵ�sΪ������ڵ�
    s->data=e;  //��������������ʵ��
    s->next=p->next;
    p->next=s;
    return 1;
}
///4��ָ���ڵ�ĺ�����   O��1��
_Bool InsertNextNode(LNode *p,int e){
    if(p==NULL)
        return 0;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL)
        return 0;   //�ڴ����ʧ��
    s->data=e;
    s->next=p->next;    //���½ڵ�s����������p����
    p->next=s;
    return 1;
}
///5��ָ���ڵ��ǰ�����
_Bool InsertPriorNode(LNode *p,int e){  //ʱ�临�Ӷ�ΪO(1),û��ѭ��
    if(p==NULL)
        return 0;
    LNode *s = (LNode *)malloc(sizeof(LNode));  //Ϊ�½ڵ����ռ�
    if(s==NULL)
        return 0;   //����ʧ��
    s->next=p->next;
    p->next=s;  //���½ڵ����������
    s->data=p->data;
    p->data=e;  //���½ڵ���p��㽻��������ʵ���߼��ϵ�ǰ�����
    return 1;

}
/**
 * ɾ�������
 * */
 ///1����λ��ɾ��  ListDelete(&L,i,e)
_Bool ListDelete(LinkList L,int i,int *e){
    if(i<1)
        return 0;       //����iֵ���Ϸ�
    LNode *p,*q;       //������ ����һ��ָ��
    p = L;              //pָ��ͷ�ڵ�
    int j=0;        //������ǵ�ǰλ��
    while(p!=NULL&&j<i-1){      //��pָ��ɾ���ǰһλ
        p=p->next;
        j++;
    };
    if(p==NULL||p->next==NULL)
        return 0;   //iֵ���Ϸ�
    q=p->next;//qָ���ɾ�����
    *e=q->data;
    p->next=q->next;//�ı�ɾ�����ǰ������ָ����
    free(q);//�ͷ�ɾ�����Ŀռ�
    return 1;
}
///2��ɾ��ָ���ڵ�p                     ��3��࣬���������bug
_Bool DeleteNode(LNode *p){
    if(p==NULL)
        return 0;
    LNode *q=p->next;    //����q��һ��ָ��
    p->data=q->data;    //������bug����Ϊ���q�����һ�����Ļ���q��ָ����������ΪNULL
    p->next=q->next;
    free(q);
    return 1;
}
///3����λ����       GetElem(L,i)
LNode *GetElem(LinkList L,int i){          //����ע�⣬��iֵ���������巶Χʱ��Ҳ�᷵��NULL����������������Ϊ��װ�����Թ���������ʹ�ã�
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
///4����ֵ����    LocateElem(L,e)
LNode *LocateElem(LinkList L,int e){    //�ڴ�ͷ���ĵ�����L�в���ֵΪe��Ԫ��
    LNode *p = L->next;
    while(p!=NULL&&p->data!=e){     //while(p!=NULL)���滻��while(p)    ˳�������ɨ�裬ֱ��pΪ�ջ�p��ָ�������������e
        p=p->next;
    }
    return p;//���ҳɹ�����ֵΪe�Ľ���ַp������ʧ��pΪNULL
}
///ע8�����  Length(L)
int LenthList(LinkList L){
    int len = 0;
    LNode *p = L;
    while (p->next!=NULL){
        p=p->next;
        len++;
    }
    return len;//���г���
}

///�������      PrintList(L)
void PrintList(LinkList L){
    while (L->next!=NULL){
        L=L->next;
        printf("%3d",L->data);
    }
}

//                                          test
int main() {
/*    LinkList L1 = NULL;
    InitList(L1);   //���д������ã��������β��޷��ı�ʵ��*/


    //����ע���ڶ���һ��Lʱ������Ҫ����ָ��ָ��
    LNode L3;
    InitList_head(&L3);
        //                                  ע��������������������������������������
            /*LinkList L;
            InitList_head(L);   //��ʼ��������ΪL���Ȿ����һ��ָ�룬��InitList_head�д������Ȼ��ָ�뵫��ʼ���������ĸ���L����������ȻΪ��ָ��  ���е���  */
    LNode L;
    InitList_head(&L);

    printf("-------------------------------1��ͷ�巨����������---------------------------------\n");
    List_HeadInsert(&L);
    List_HeadInsert(&L3);
    //L= List_TailInsert(L);
    PrintList(&L);
    PrintList(&L3);

    /**
    printf("\n-------------------------------2���ڵ�����λ�ò���88-------------------------------\n");
    ListInsert(L,3,88);
    PrintList(L);

    printf("\n-------------------------------3����88�������99------------------------------------\n");
    LNode *p=L;
    int i=0;
    while(i<3){
        p=p->next;
        i++;
    }
    InsertNextNode(p,99);
    PrintList(L);

    printf("\n-------------------------------4����LocateElem�����ҽ��88������ǰ����77------------------------------------\n");
    LNode *q= LocateElem(L,88);
    InsertPriorNode(q,77);
    PrintList(L);

    printf("\n-------------------------------5��ɾ����5��Ԫ��------------------------------------\n");
    int x;
    ListDelete(L,5,&x);
    printf("��ɾԪ��ֵΪ��%d\n",x);
    PrintList(L);

    printf("\n-------------------------------6��ɾ��ָ�����3------------------------------------\n");
    LNode *z= LocateElem(L,3);
    DeleteNode(z);
    PrintList(L);

    printf("\n-------------------------------7����λ���ҵ�2��Ԫ��------------------------------------\n");
    LNode *a= GetElem(L,2);
    printf("�ڶ���Ԫ�ص�ֵΪ��%d\n",a->data);

    printf("\n-------------------------------8����ֵ���� LocateElem(L,e)------------------------------------\n");
    LNode *b= LocateElem(L,4);

    if(b!=NULL) {
        printf("ֵΪ4��b������L��\n");
    }else {
        printf("û��ֵΪ4��Ԫ�أ���");
    }

    LNode *c = LocateElem(L,8);
    if(c!=NULL){
        printf("ֵΪ8��c������L��\n");
    }else{
        printf("û��ֵΪ8��Ԫ�أ���");
    }
    printf("\n-------------------------------9����ֵ���� LocateElem(L,e)------------------------------------\n");

    printf("\n-------------------------------x����ʱ����------------------------------------\n");
    printf("��ʱ��Ϊ��%d", LenthList(L));
     */

    return 0;
}


/**
 * ���䣺=��==
 *          1��=Ϊ��ֵ�����
 *          2��==Ϊ�߼������
 *
 *      ע��if(x=1)��if(x==1)
 *              if(x=1)���κ�����¶�Ϊtrue,�ǽ�1��ֵΪx,���������� ��0��1 �ʾ����������¶�Ϊtrue
 *              if(x==1)�������ж�,���x����1��Ϊtrue,����false
 *         ��һ���ϸ�ĳ���Ա��������ڡ� ���� ��=�� ���� ��==��
 * */
