#include <stdio.h>

/// 1539����k��ȱʧ��������

//����㷨��˼����ǽ�һ�����д� 1-n ���кã�i������û��ȱʧ������������ȱʧ��k��-1��j�������������е��ƶ���i��j�����k�ͻ�-1��
// ��k��Ϊ0ʱ����ʱjǡ��ָ���k��ȱʧ��������ûȱʧ�ľͻ�����ָ�������ƣ�����ȱʧ��ֻ��j������
int findKthPositive2(int* arr, int arrSize, int k){
    int i = 0,j = 1;
    while(i<arrSize){
        if(arr[i] == j){
            i++;
        } else{
            if(!--k) return j;
        }
        j++;
    }
    return j+k-1;
}




int findKthPositive(int* arr, int arrSize, int k){
    int a[arr[arrSize-1]*2];
    for (int i = 0; i < arr[arrSize-1]*2; ++i) {  //����һ���� 1-���Ԫ�� ������.����Ҫ���õĴ�һЩ����Ϊ������arr={1��3}��k=5�Ļ��ͻ᲻�ṻ��
        a[i] = i+1;
    }
    int j = 0;
    for (int i = 0; i < arr[arrSize-1]; ++i) {
        if(a[i] == arr[j]) {
            a[i] = 9999;
            j++;
        }
    }
    int p = 0;
    for (int i = 0; i < arr[arrSize-1]*2; ++i) {
        if(a[i]!=9999){
            a[p] = a[i];
            p++;
        }
    }
    return a[k-1];
}

///��������arr���ȣ�             sizeof(arr) / sizeof(int);

int main() {
    int arr[2]={1,3};
    printf("ԭ����arr����Ϊ%d",sizeof(arr)/sizeof(int));
    int k = 5;
    printf("\n��%d��ȱʧ��Ԫ��Ϊ%d",k, findKthPositive2(arr,sizeof(arr)/sizeof(int),k));
    return 0;
}
