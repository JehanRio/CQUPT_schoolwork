#include<iostream>
#include<set>
using namespace std;
class DFS
{
public:
int vis[105];
int num[105];
int n;
set<int>ans;
void dfs(int x,int sum)
{
    if(sum!=0)
        ans.insert(sum);
    if(x==n+1)
    {
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(x+1,abs(sum+num[i]));
            dfs(x+1,abs(sum-num[i]));
            vis[i]=0;
        }
    }
}
void test()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    dfs(1,0);
    cout<<ans.size();
}
};

    int num[105];
    int n;
    int dp[105][10005];
    int main()
    {
        cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>num[i];
            sum+=num[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int w=1;w<=sum;w++)
            {
                dp[i][w]=dp[i-1][w];//先看能不能不用这个砝码凑出来
                if(dp[i][w]==0)
                {
                    if(num[i]>w)dp[i][w]=dp[i-1][num[i]-w];
                    else if(num[i]==w)dp[i][w]=1;
                    else if(num[i]<w)dp[i][w]=dp[i-1][w-num[i]];
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=sum;i++)
            if(dp[n][i])ans++;
        cout<<ans;
        return 0;
    }