/*6x6�ķ������Ÿ��ӵı��߼����������֡�
Ҫ���������ֵ���״��ȫ��ͬ��**/
#include<iostream>
#include<cmath>
using namespace std;

//֪ʶ��:�����㷨������������������������س�

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
        if(!vis[dx][dy])//δ���ʹ�
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