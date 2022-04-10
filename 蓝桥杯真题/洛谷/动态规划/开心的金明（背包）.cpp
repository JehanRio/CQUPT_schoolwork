//https://www.luogu.com.cn/problem/P1060
#include<iostream>
using namespace std;
int n,m;
int val[30],w[30];
int dp[30][30005];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>val[i]>>w[i];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=30000;j++)
        {
            if(j-val[i]<0)
                dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-val[i]]+val[i]*w[i]);
            }
        }
    }
    cout<<dp[m][n];
}