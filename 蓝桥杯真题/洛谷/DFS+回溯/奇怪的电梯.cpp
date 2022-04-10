//https://www.luogu.com.cn/problem/P1135
#include<iostream>
//#include<climits>
#include<cmath>
using namespace std;
int n,a,b;
int k[205];//每一层的数字
bool vis[205];//不能老在同一层打转转
int ans=0x7fffffff;
class dfs
{
public:
void dfs2(int x,int step)
{
    if(x<1 || x>200 || vis[x])return;
    if(x==b)
    {
        ans=min(ans,step);
        return;
    }
    vis[x]=1;
    dfs2(x+k[x],step+1);
    dfs2(x-k[x],step+1);
    vis[x]=0;//回溯 相当于没来过这层
}
void dfs1(int x,int step)
{
    if(x<1||x>200||vis[x])return;
    if(x==b)
    {
        if(step<ans)ans=step;
        return;
    }
    vis[x]=1;
    dfs1(x+k[x],step+1);
    dfs1(x-k[x],step+1);
    vis[x]=0;//回溯
}
void test()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
        cin>>k[i];
    dfs1(a,0);
    if(ans!=0x7fffffff)
        cout<<ans;
    else cout<<"-1";
}
};
class Floyd
{
public:
    int f[201][201],n,a,b,x;
    Floyd()
    {
        cin>>n>>a>>b;
        for(int i=1;i<=n;i++)   
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)f[i][j]=1e5;
                else f[i][j]=0;//初始化皆为不联通，自己到自己为0。
            }
        }
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(i+x<=n)f[i][i+x]=1;
            if(i-x>0)f[i][i-x]=1;
        }

        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i!=j)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }
        if(f[a][b]!=1e5)cout<<f[a][b];
        else cout<<"-1";
    }
};
int main()
{
    dfs s1;
    s1.test();
    return 0;
}
