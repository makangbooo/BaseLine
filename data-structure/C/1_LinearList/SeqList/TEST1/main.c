#include <stdio.h>
#include <stdlib.h>
/**
 * ���Ա�-˳���洢�ṹ����ʼ������ɾ�Ĳ�Ĵ���ʵ��
 * */
//��ʼ��
typedef struct List{
    int * array;
    int capacity;
    int size;
}List,*ArrayList;

_Bool initList(ArrayList list){
    list->array = malloc(sizeof(int)*10);
    if(list->array==NULL) return 0;
    list->capacity = 10;
    list->size=0;
    return 1;
}
//����ɾ������
_Bool insert(ArrayList list,int element,int index){
    for (int i = list->size; i >index-1 ; --i)//ע��i = list->size��ʾ�����������һλ�ĺ�һλ
        list->array[i]=list->array[i-1];
    list->array[index-1] = element;
    list->size++;

}

void printList(ArrayList list){
    for (int i = 0; i < list->size; ++i)
        printf("%d",list->array[i]);
    printf("\n");
    
}

int main(){
    struct List list;
    if(initList(&list)){
        insert(&list,666,1);
        printList(&list);
        insert(&list,777,1);
        printList(&list);
        insert(&list,888,1);
        printList(&list);
    } else{
        printf("�����쳣���޷�����false");
    }

}


