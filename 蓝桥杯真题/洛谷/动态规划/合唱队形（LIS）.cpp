//https://www.luogu.com.cn/problem/P1091
#include <stdio.h>
#include <string.h>
#include<iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;
vector<int>height(105);
vector<vector<int>>dp(105,vector<int>(2,1));//һ��Ҫ��ʼ��ȫ��Ϊ1
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        cin>>height[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)//����iһ���ĵط���ʼ
        {
            if(height[i]>height[j])
            {
                dp[i][0]=max(dp[i][0],dp[j][0]+1);
            }
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=n;j>=i;j--)//����iһ���ĵط���ʼ
        {
            if(height[i]>height[j])
            {
                dp[i][1]=max(dp[i][1],dp[j][1]+1);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,(dp[i][0]+dp[i][1]-1));
    }
    cout<<n-ans;
    return 0;
}