#include <stdio.h>

///由n个节点可以构造出多少种二叉树
int main() {
    int size;
    scanf("%d",&size);  //输入结点数
    int dp[size+1]; //初始化一个数组，记录下标为节点数时所能组成的二叉树种类
    dp[0] = dp[1] = 1;  //没有节点或是只有一个节点

    for (int i = 2; i <= size; ++i) {
        dp[i] = 0;  //先将数据初始化为0，以免脏数据导致出错

        for (int j = 0; j < i; ++j) {   //内存循环是为了计算所有情况，比如i等于3，那么就从j=0开始，计算dp[0]到dp[2]的结果，再计算dp[1]和dp[1]
            dp[i] = dp[j]*dp[i-j-1] + dp[i];    ///记住这种算法写法
            //以此类推：
            //dp[3] = dp[0]*dp[2]+dp[1]*dp[1]+dp[2]*dp[0]
            //dp[4] = dp[0]*dp[3]+dp[1]*dp[2]+dp[2]*dp[1]+dp[3]*dp[0]
        }
    }

    printf("%d",dp[size]);
    return 0;
}
