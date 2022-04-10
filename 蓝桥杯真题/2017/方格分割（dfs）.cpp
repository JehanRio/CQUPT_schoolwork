/*6x6的方格，沿着格子的边线剪开成两部分。
要求这两部分的形状完全相同。**/
#include<iostream>
#include<cmath>
using namespace std;

//知识点:回溯算法，出口条件、访问数组与其回撤

int vis[7][7]={0};
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int ans=0;
void dfs(int x,int y)
{
    if(!x || !y || x==6 || y==6)
    {
        ans++;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int dx=x+dir[i][0],dy=y+dir[i][1];
        if(!vis[dx][dy])//未访问过
        {
            vis[dx][dy]=1;
            vis[6-dx][6-dy]=1;
            dfs(dx,dy);
            vis[dx][dy]=0;
            vis[6-dx][6-dy]=0;
        }
    }
}
int main()
{
    vis[3][3]=1;
    dfs(3,3);
    cout<<ans/4;
    return 0;
}