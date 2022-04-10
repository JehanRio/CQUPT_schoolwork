#include<iostream>
#include<cmath>
using namespace std;
//画状态转移表 确定for的状态遍历方向
int n,m;
int dp[35][35];//次数、人数
int main()
{
    cin>>n>>m;//人数和次数
    dp[0][1]=1;//1个人 传0次
    for(int i=1;i<=m;i++)//次数
    {
        for(int j=1;j<=n;j++)//第几个人
        {
            int a=j-1,b=j+1;
            if(a==0)a=n;
            if(b==n+1)b=1;
            dp[i][j]=dp[i-1][a]+dp[i-1][b];
        }
    }
    cout<<dp[m][1];
}