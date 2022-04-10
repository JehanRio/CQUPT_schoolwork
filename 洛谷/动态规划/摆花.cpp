#include <stdio.h>
#include <string.h>
#include<iostream>
#include <vector>
// #include <algorithm>
#include<climits>
using namespace std;
int num[105];//花的最多个数
int dp[105][105];//花的种类 花的总个数
const int mod=1e6+7;
int main()
{
    int n,m;cin>>n>>m;//花的种类和总数量
    for(int i=1;i<=n;i++)
        cin>>num[i];//一类花最多能拜访多少盆
    //要是一盆都不用，那么无法凑齐m盆花 除了0 0=1
    dp[0][0]=1;
    //画状态转移表
    for(int i=1;i<=n;i++)//从1开始 第一个种类  因为后面有i-1，所以得从1开始
    {
        for(int j=0;j<=m;j++)//从0开始，总共0盆
        {
            for(int k=0;k<=min(j,num[i]);k++)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}