#include <stdio.h>
#include <stdlib.h>
/**
 * ˫���� & ѭ��˫����
 *       һ������ͳ�ʼ��
 *       ��������
 * */

/**
 * 1������ͽ���
 * */
//�ٷ�����
typedef struct DuNode{           //Double Node:DNode
    int data;
    struct DuNode *next;
    struct  DuNode *prior;
}DuNode,*DuLinkList;

/**
 * 2����ʼ����˫���� & ѭ������
 * */
//˫����ĳ�ʼ��   ˫������
DuLinkList InitDuLinkList_n(DuLinkList L){
    L = (DuNode*) malloc(sizeof(DuNode));
    L->next=NULL;
    L->prior=NULL;
    return L;
};

//ѭ��˫�����ʼ��
DuLinkList InitDuLinkList(DuLinkList L){
    L=(DuNode *)malloc(sizeof(DuNode));
    if(L==NULL)
        return 0;
    L->prior = L;
    L->next = L;
    return L;
}
///˫��������(��ͷָ��)
int Length(DuLinkList L){
    DuNode *p;
    p = L;
    if(p->next==L) {
        printf("����Ϊ0");
        return 0;
    } else {
        int j = 0;
        while (p->next != L) {
            j++;
            p = p->next;
        }
        return j;
    }
}


/**
 * 3�����롢ɾ��
 * */
//˫���� ��p���֮������½ڵ�s
_Bool InsertNextDuNode(DuNode *p,DuNode *s){
    if(p==NULL||s==NULL){
        return 0;
    }
    s->next=p->next;
    s->prior=p;
    p->next=s;
    return 1;
}

///�ڴ�ͷ����˫������L�в��ҵ�i��Ԫ�أ����ؽ��ĵ�ַ
DuNode* GetElemP_DuL(DuLinkList L,int i){
    int j = 1;
    DuNode *p;
    p = L->next;
    while (j<i){
        p=p->next;
        ++j;
    }
    return p;
}
///�ڴ�ͷ����˫������L�е�i��λ��֮ǰ����Ԫ��e��i�ĺϷ�ֵΪ1<=i<=��+1 (ѭ��˫����)
_Bool ListInsert_DuL(DuLinkList L,int i,int e){
    DuNode *s,*p;
    s = (DuNode*) malloc(sizeof (DuNode));
    s->data = e;
    if(!(p = GetElemP_DuL(L,i))) {  //��L��ȷ����i��Ԫ�ص�λ��ָ��p
        return 0;
    }
    if(i==1){   //��˫������ĵ�һ��Ԫ���ϲ���
        p = L->next;    //ԭ��˫������ĵ�һ��Ԫ��
        L->next = s;
        s->prior = L;
        s->next = p;
        p->prior = s;
    } else if(i == Length(L)){  //��˫����������һ��Ԫ���ϲ���
        p = L;
        while (p->next!=L)
            p = p->next;    //��pָ��˫�������β
        p->next = s;
        s->prior = p;
        s->next = L;
    } else {
        s->next = p;
        s->prior = p->prior;
        p->prior->next = s;
        p->prior = s;
    }
    return 1;


}

///���䣺ѭ��������ĳ�ʼ��    ��������һ��
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
_Bool InitLinkList_c(LinkList L){
    L = (LNode *) malloc(sizeof(LNode));
    if(L==NULL)
        return 0;
    L->next=L;
    return 1;
};
_Bool InitList_head(LinkList L){
    L=(LNode *)malloc(sizeof(LNode));       //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
    if(L==NULL)
        return 0;                           //����ʧ��
    L->next = NULL;                         //ͷ����ָ�����ÿ�
    return 1;
};
//�ж�ѭ���������Ƿ�Ϊ��
_Bool isEmpty(LinkList L){
    if(L->next==L)
        return 1;
    else
        return 0;
}
//�жϽڵ�p�Ƿ�Ϊѭ��������ı�β�ڵ�
_Bool isTail(LinkList L,LNode *p){
    if(p->next==L)
        return 1;
    else
        return 0;
}



int main() {
    DuLinkList L = InitDuLinkList(L);
    if(ListInsert_DuL(L,1,99)){
        printf("����ɹ�������\n");
    } else{
        printf("����ʧ�ܣ�����\n");
    };
    int a = Length(L);
    printf("��Ϊ%d\n",a);
    printf("��һ��Ԫ��ֵΪ��%d",L->next->data);


    return 0;
}
