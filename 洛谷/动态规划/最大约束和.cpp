#include<iostream>
#include<cmath>
using namespace std;
int nums[1005];
int dp[1005];
//ע�⣬Ҫ����ȫ�֣������ں����У����ܻ����
int find(int x)
{
    int ans=0;
    for(int i=1;i<=x/2;i++)
    {
        if(x%i==0)ans+=i;
    }
    return ans;
}
int main()
{
    int n;cin>>n;

    for(int i=1;i<=n;i++)
        nums[i]=find(i);
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
        {
            dp[j]=max(dp[j],dp[j-i]+nums[i]);
        }
    }
    cout<<dp[n];
    return 0;
}