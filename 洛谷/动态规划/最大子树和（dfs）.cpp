#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int n,a[16005],f[16005];
vector<vector<int>>map(16005,vector<int>(0));//这样也可以表示一个二维数组
void dfs(int child,int dad)
{
    f[child]=a[child];//初始化
    for(int i=0;i<map[child].size();i++)
    {
        int tem=map[child][i];
        if(tem!=dad)
        {
            dfs(tem,child);//找到他的枝叶的总和
            if(f[tem]>0)
                f[child]+=f[tem];
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];//输入权值
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
       map[u].push_back(v);
       map[v].push_back(u);
    }
    dfs(1,0);//假设第一个结点的父亲是0
    int ans=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}