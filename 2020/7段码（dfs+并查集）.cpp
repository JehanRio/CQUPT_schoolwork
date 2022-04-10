/*上图给出了七段码数码管的一个图示，数码管中一共有 7 段可以发光的二
极管，分别标记为 a, b, c, d, e, f, g。
小蓝要选择一部分二极管（至少要有一个）发光来表达字符。在设计字符的表达时，要求所有发光的二极管是连成一片的。
例如：b 发光，其他二极管不发光可以用来表达一种字符。
例如：c 发光，其他二极管不发光可以用来表达一种字符。这种方案与上一行的方案可以用来表示不同的字符，尽管看上去比较相似。
例如：a, b, c, d, e 发光，f, g 不发光可以用来表达一种字符。
例如：b, f 发光，其他二极管不发光则不能用来表达一种字符，因为发光的二极管没有连成一片。请问，小蓝可以用七段码数码管表达多少种不同的字符？*/
#include<iostream>
using namespace std;
#define N 10
int vis[N];//判断灯泡亮不亮
int map[N][N];
int f[N];//自己的大哥
int ans=0;
int find(int x)
{
    return f[x]==x?x:(f[x]=find(f[x]));//找到大哥
}
void dfs(int d)
{
    if(d>7)//7个灯泡都进行了操作
    {
        for(int i=1;i<=7;i++)f[i]=i;//自己是自己的大哥
        for(int i=1;i<=7;i++)//遍历所有边集
        for(int j=1;j<=7;j++)
        {
            if(map[i][j] && vis[i] && vis[j])//连通 并且两个都亮了
            {
                int fx=find(i),fy=find(j);
                if(fx!=fy)f[fx]=fy;//如果不在同一个集合 则合并
            }
        }
        int k=0;
        for(int i=1;i<=7;i++)
        {
            if(vis[i] && f[i]==i)//找到一个集合 k+1
                k++;
        }
        if(k==1)//如果只有一个集合 
            ans++;
        return;
    }
    vis[d]=1;//打开d这个灯，继续开关下一个灯
    dfs(d+1);
    vis[d]=0;//关闭d这个灯，继续开关下一个灯
    dfs(d+1);

}
int main()
{
    map[1][2]=map[1][6]=1;
    map[2][1]=map[2][3]=map[2][7]=1;
    map[3][2]=map[3][7]=map[3][4]=1;
    map[4][3]=map[4][5]=1;
    map[5][4]=map[5][7]=map[5][6]=1;
    map[6][1]=map[6][5]=map[6][7]=1;
    map[7][2]=map[7][3]=map[7][5]=map[7][6]=1;
    dfs(1);
    cout<<ans;
    return 0;
}