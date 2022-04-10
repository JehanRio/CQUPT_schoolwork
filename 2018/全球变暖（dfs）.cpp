/**你有一张某海域NxN像素的照片，".“表示海洋、”#"表示陆地，如下所示：
其中"上下左右"四个方向上连在一起的一片陆地组成一座岛屿。例如上图就有2座岛屿。
由于全球变暖导致了海面上升，科学家预测未来几十年，岛屿边缘一个像素的范围会被海水淹没。具体来说如果一块陆地像素与海洋相邻(上下左右四个相邻像素中有海洋)，它就会被淹没。
7
.......
.##....
.##....
....##.
..####.
...###.
.......  
例如上图中的海域未来会变成如下样子：
.......
.......
.......
.......
....#..
.......
.......
请你计算：依照科学家的预测，照片中有多少岛屿会被完全淹没。
【输入格式】
第一行包含一个整数N。 (1 <= N <= 1000)
以下N行N列代表一张海域照片。
照片保证第1行、第1列、第N行、第N列的像素都是海洋。
【输出格式】
一个整数表示答案。
【输入样例】
7*/
#include<iostream>
#define N 1005
using namespace std;
int n;
int ans=0;
int endnum=0;
char matrix[N][N];
int mar[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs1(int x,int y)//统计岛屿数量
{
    if(x<0 || x>=n || y<0 || y>=n )
        return;
    if(matrix[x][y]!='#')//？？？？？？？？？？？？？？？？？？？？？？？？ if(matrix[x][y]=='.')
    {
        return;             //因为下面会把岛屿变成1 所以不能判断是否等于‘.’
    }
    matrix[x][y]='1';//将岛屿标记为1
    dfs1(x+1,y);
    dfs1(x-1,y);
    dfs1(x,y+1);
    dfs1(x,y-1);
}
void dfs2(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=n )
        return;
    if(matrix[x][y]=='.')//如果是海水
    {
        return;
    }
    if(matrix[x+1][y]=='1' && matrix[x-1][y]=='1' && matrix[x][y+1]=='1' && matrix[x][y-1]=='1')//四周都是岛屿
    {
        matrix[x][y]='2';
    }
}
void dfs3(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=n )
        return;
    if(matrix[x][y]=='.')return;
    matrix[x][y]='.';
    dfs3(x+1,y);
    dfs3(x-1,y);
    dfs3(x,y+1);
    dfs3(x,y-1);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%s",&matrix[i]);//这样实现输入二维矩阵
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]=='#')
            {
                ans++;
                dfs1(i,j);//先把岛屿变成1 总过有ans个岛屿
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]=='1')
            {
                dfs2(i,j);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]=='2')
            {
                endnum++;
                dfs3(i,j);//剩余多少
            }
        }
    }
    cout<<ans-endnum;
    return 0;
}
