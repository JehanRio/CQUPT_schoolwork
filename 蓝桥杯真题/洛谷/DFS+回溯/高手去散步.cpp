//https://www.luogu.com.cn/problem/P1294
#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
int map[25][25];
int vis[25];
int n,m;
int ans=0;
int an;
void dfs(int x,int sm)
{
    ans=max(ans,sm);
    for(int i=1;i<=n;i++)
    {
        if(map[x][i]!=0 && vis[i]==0)//有路并且没走过
        {
            vis[i]=1;
            dfs(i,sm+map[x][i]);
            vis[i]=0;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        map[a][b]=c;
        map[b][a]=c;
    }
    for(int i=1;i<=n;i++)//从结点i开始走
    {
        vis[i]=1;
        dfs(i,0);
        an=max(an,ans);
        memset(vis,0,sizeof(vis));
    }
    cout<<an;
    return 0;
}