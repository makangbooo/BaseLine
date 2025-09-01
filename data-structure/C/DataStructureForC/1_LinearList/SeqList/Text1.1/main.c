#include <stdio.h>
#include <stdlib.h>
/**
 * ����
 *
 * һ�����Ա�-˳��洢
 *      1����ʼ�� ��̬����˳���
 *      2��˳���Ĳ��롢ɾ������
 *      3�����ң���ֵ����λ
 * ��Ƶ�� 2.2.1 - 2.2.2
 * */

/**
 * 1������ͽ���
 * */
/*ע����̬���䶨��*/
#define MaxSize1 50
typedef struct{
    int data[MaxSize1];
    int length;
}SqList;


/*ע����̬���䶨��*/
#define InitSize 5
typedef struct SeqList{
    int *data;  //����ַ   ��������ö��壬���Ƕ������ַ��ָ������
    int MaxSize;
    int length;
}SeqList;
/**
 * 2����ʼ��
 * */
void InitList(struct SeqList *L){
    L->data=(int *)malloc(InitSize*sizeof(int));        //�����ʼ���ռ�Ϊ10��int
    //����֮���Ժ������в�һ��������Ϊ�����з������L�õ�ַ�ռ䣬�ᱨ���������Ǹ�L�е�data�������ռ�
    L->length=0;
    L->MaxSize=5;
}
//�������Ӷ�̬����ĳ��ȿռ�   ����������������������������������������������
void IncreaseSize(struct SeqList * L,int len){
    int *p=L->data;     //��ָ��pָ��ԭ�����飩��
    L->data=(int*)malloc((L->MaxSize+len)*sizeof(int));     //��L���·���һ������Ŀռ�
    for (int i = 0; i < L->length; ++i) {   //��p��ָ���ֵ������Ƹ���L;
        L->data[i]=p[i];
    }
    L->MaxSize+=len;
    free(p);    //�����Ȼ˵���������鳤�ȣ�Ȼ�����¿���һƬ����������ռ䣬����p��ָ�������飬Ȼ��֮ǰ�Ŀռ��е�����ת�ƹ��������ͷ�p��
}

                                ///��ɾ�Ĳ�
/**
 * ����:ListInsert(&L,i,e)
 * */
_Bool ListInsert(struct SeqList *L,int i,int e){
    if(i<1||i>L->length+1) {
        printf("�������ݲ��Ϸ�������\n");
        return 0;
    }
    if(L->length == L->MaxSize) {
        printf("��ǰ�洢�ռ�������������\n");
        return 0;
    }
    for (int j = L->length; j >= i; --j) {  //�����Ǵӱ�β��ʼһ��������Ų
        L->data[j]=L->data[j-1];
    }
    L->data[i-1]=e; //���±�Ϊi-1��λ��Ų��������ֵe
    L->length++;
    return 1;
}
/**
 ����̨ ��������(��β)
 */
void ListInsert_crtl(SeqList *L){
    int x=0;
    scanf("%d",&x); //�ӿ���̨���벢��ֵ��x
    while (x!=9999){    //������9999ʱ����whileѭ��
        L->data[L->length]=x;   //�ڱ�β���в��룬�±�Ϊlength-1
        L->length++;    //����1
        if(L->length == L->MaxSize) {   //������ർ�±���������ѭ��
            printf("��ǰ�洢�ռ�������������\n");
            return;
        }
        scanf("%d",&x); //��x���¸�ֵ
    }
}
/**
 * ɾ��    ListDelete(&L,i,&e)
 * */
_Bool ListDelete(struct SeqList *L,int i,int *e){
    if(i<1||i>L->length) {
        printf("iֵ���Ϸ���������");
        return 0;
    };
    *e=L->data[i-1];  //ע��Ϊɶ����Ҫ��*����L���ô�����������������������
    for (int j = i; j <= L->length-1; ++j) {    //j��ʾ��ɾԪ�غ�һλ��j-1Ϊ��ɾԪ��
        L->data[j-1]=L->data[j];
    }
    L->length--;    //����1
    return 1;
}

/**
 * ��ֵ����    LocateElem(L,e)
 **/
int LocateElem(struct SeqList *L,int e){
    for (int i = 0; i < L->length; ++i) {
        if(L->data[i]==e){
            printf("ֵΪ%d��Ԫ���ڵ�%dλ\n",e,i+1);
            return i+1;
        };
    };
    printf("û��ֵΪ%d��Ԫ��\n",e);
    return 0;
}
/**
 * ��λ����    GetElem(L,i)
 **/
int GetElem(SeqList L,int i){         //����SeqListǰû��struct����Ϊ�ڶ���SeqListǰtypedef���˵���SeqList��
    if(i<1||i>L.length) {
        printf("���Ա���û�е�%dλ\n",i);
        return 0;
    }
    printf("���Ա��е�%dλ��ֵλ%d\n",i,L.data[i-1]);
    return L.data[i-1];
}
/**
 * �������      PrintList(L)
 */
void PrintList(SeqList L){
    for (int i = 0; i < L.length; ++i) {
        printf("%3d",L.data[i]);
    }
    return;
}

/**
 * �пղ���   Empty(L)
 **/
_Bool Empty_L(SeqList L){
    if(L.length==0)
        return 1;
    else
        return 0;
}

/**
 * ���        LengthList(L)
 **/
int LengthList(SeqList L){
    return L.length;
}
//���ٲ���      DestoryList(&L)


int main(){
    /*һ����̬����˳����ʼ��*/
    printf("__________________________________________1����ʼ��__________________________________________________\n");
        SeqList L;
        InitList(&L);
        printf("��ʼ�����Ա���Ϊ%d���������Ϊ%d\n",L.length,L.MaxSize);
    printf("__________________________________________2�����Ӷ�̬����ĳ��ȿռ�_____________________________________\n");
        IncreaseSize(&L,5);
        printf("���ݺ����Ա���Ϊ%d���������Ϊ%d\n",L.length,L.MaxSize);

    /*����˳���Ĳ��롢ɾ������*/
    printf("\n_________________________________________3������____________________________________________________\n");
    printf("\n����1:\n");
    ListInsert(&L,1,1);
    PrintList(L);
    printf("\n����2:\n");
    ListInsert(&L,2,2);
    PrintList(L);

    printf("\n________________________________________4������̨��������____________________________________________\n");
    ListInsert_crtl(&L);
    PrintList(L);

    printf("\n________________________________________5��ɾ��____________________________________________________\n");
    int a=0;
    ListDelete(&L,3,&a);
    printf("\nɾ���ĵ�����Ԫ�ص�ֵΪ:%d\nɾ��������Ԫ�غ�:\n",a);
    PrintList(L);

    printf("\n________________________________________6����ֵ����_________________________________________________\n");
    int *b=0;
    LocateElem(&L,9);

    printf("\n________________________________________7����λ����_________________________________________________\n");
    GetElem(L,3);
    GetElem(L,10);

    printf("\n________________________________________8����____________________________________________________\n");
    printf("��ʱ��Ϊ��%d", LengthList(L));
    return 0;



}