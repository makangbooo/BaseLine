#include <stdio.h>
typedef int Elemtype;

/** 交换排序--快速排序 ：其实就是对冒泡排序的一种升级, 但快速排序不稳定，冒泡是稳定的
 *
 *          冒泡排序是相邻两个元素进行交换，
 *          快速排序是从两边开始向中间进行（或者是从一端开始，对大于枢纽或小于枢纽元素进行交换，本质是打破相邻）
 * */


void quickSort(int arr[], int start, int end){

    if(start >= end) return;    //递归终止条件 范围不可能无限制的划分下去

    int left = start, right = end, pivot = arr[left];   //pivot为枢纽元素的数值

    while(left < right){    //只要两个指针没有相遇，就一直循环下面的操作，
        while(left < right && arr[right] >= pivot) right--; //从右向左看，直到遇见比枢纽小的
        arr[left] = arr[right]; //遇到比基准小的，就丢到左边
        /**
         * 这里空间运用的很巧妙，始终有一个位置是空的（while循环开始时，其实最左边的位置是可以利用的，因为最左侧元素的值已经交给pivot）
         * 第一轮：
         *  1、从最右侧开始寻找到第一个比枢纽值小的元素时，放到最左边，此时右边又出现了一个可利用位置
         *  2、从最左侧开始寻找到第一个比枢纽值大的元素时，就放到右边（不是最右，而是right处）
         * */
        while (left < right && arr[left] <= pivot) left++;  //从左往右看，直到遇见比枢纽大的
        arr[right] = arr[left]; //遇到比基准大的，就丢到右边
    }
    arr[left] = pivot;    //此时枢纽元素的位置已经确定，从这可知，快速排序每轮确定一个中间位置的元素
    quickSort(arr,start,left-1);
    quickSort(arr,left+1,end);


}


int main() {
    int arr[] = {3,5,7,2,9,5,3,1,10,4};
    quickSort(arr,0,9);
    for (int i = 0; i < 10; ++i) {
        printf("%3d",arr[i]);
    }
    return 0;
}
