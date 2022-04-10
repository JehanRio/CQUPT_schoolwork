/*有12张连在一起的12生肖的邮票。现在你要从中剪下5张来，要求必须是连着的。（仅仅连接一个角不算相连）
请你计算，一共有多少种不同的剪取方法。*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int vis[3][4];//用于确保不会重复搜索
int g[3][4];//用于存放哪几个数被选取
int cur=0;//用于观看有几个数连成一片
int num[5];//用于存放五个选取的数字
int ans=0;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y)
{
    vis[x][y]=1;//防止重复选取
    cur++;
    for(int i=0;i<4;i++)
    {
        int dx=x+dir[i][0],dy=y+dir[i][1];//新的横纵坐标
        if(dx>=0 && dx<3 && dy>=0 && dy<4 && vis[dx][dy]==0 && g[dx][dy]==1)
            dfs(dx,dy);
    }
    
}
void check(int step,int k)
{
    if(step==5)//凑齐了五个数字
    {
        int x,y;
        for(int i=0;i<5;i++)//对五个数进行操作
        {
            x=(num[i]-1)/4;//横坐标
            y=(num[i]-1)%4;//纵坐标
            g[x][y]=1;//该坐标已被选取
        }
        dfs((num[0]-1)/4,(num[0]-1)%4);//对第一个数进行判断
        if(cur==5)
            ans++;
        cur=0;//用完后置零
        memset(vis,0,sizeof(vis));
        memset(g,0,sizeof(g));
        return;
    }
    for(int i=k;i<=12;i++)
    {
        num[step]=i;//用于存放第一个、第二个、···等数字
        check(step+1,i+1);//step+1表示多了一个数，参数k=i 下一次第二个数就是从2开始
    }
}
int main()
{
    check(0,1);
    cout<<ans;
    return 0;
}