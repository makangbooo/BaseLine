#include <stdio.h>

/// 1539、第k个缺失的正整数

//这个算法的思想就是将一个数列从 1-n 排列好，i用来计没有缺失的数，当遇见缺失的k会-1，j用来计完整数列的移动，i和j不相等k就会-1，
// 当k减为0时，此时j恰好指向第k个缺失数，遇见没缺失的就会两个指针往后移，遇见缺失的只有j往后移
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
    for (int i = 0; i < arr[arrSize-1]*2; ++i) {  //建立一个从 1-最大元素 的数组.这里要设置的大一些，因为，例如arr={1，3}，k=5的话就会不会够用
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

///计算数组arr长度：             sizeof(arr) / sizeof(int);

int main() {
    int arr[2]={1,3};
    printf("原数组arr长度为%d",sizeof(arr)/sizeof(int));
    int k = 5;
    printf("\n第%d个缺失的元素为%d",k, findKthPositive2(arr,sizeof(arr)/sizeof(int),k));
    return 0;
}
