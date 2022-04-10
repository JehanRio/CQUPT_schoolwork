//https://www.luogu.com.cn/problem/P1091
#include <stdio.h>
#include <string.h>
#include<iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;
vector<int>height(105);
vector<vector<int>>dp(105,vector<int>(2,1));//一定要初始化全部为1
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        cin>>height[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)//从与i一样的地方开始
        {
            if(height[i]>height[j])
            {
                dp[i][0]=max(dp[i][0],dp[j][0]+1);
            }
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=n;j>=i;j--)//从与i一样的地方开始
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