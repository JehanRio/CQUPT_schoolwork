//https://www.luogu.com.cn/problem/P1189
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
char map[55][55];
int r,c;
int n;
int sx,sy;//���
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
vector<string> dir(1005);
bool vis[55][55][1005];//һ�����Ƿ���ĳʱ�߹�
void init()//�ҵ����
{
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
    {
        if(map[i][j]=='*')
        {
            sx=i;sy=j;break;
        }
    }
    map[sx][sy]='.';
}
bool check(int x,int y)//����Ƿ�Խ��
{
    return x<=r&&x>0&&y<=c&&y>0;
}
int hua(char x) 
{
    if(x == 'N')//�� 
        return 2;
    if(x == 'S')//�� 
        return 0;
    if(x == 'E')//�� 
        return 1;
    if(x == 'W')//�� 
        return 3;
}
void dfs(int x,int y,int s)//s:�ڼ����ƶ�
{
    if(vis[x][y][s])return;
    vis[x][y][s]=1;
    if(s==n+1)
    {
        map[x][y]='*';
        return;
    }
    else
    {
        int ex=x,ey=y,p;
        p=hua(dir[s][0]);
        ex+=dx[p];
        ey+=dy[p];
        while(check(ex,ey)&&map[ex][ey]!='X')
        {
            dfs(ex,ey,s+1);
            ex += dx[p];
            ey += dy[p];
        }
    }
}
int main()
{
    cin>>r>>c;
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
        cin>>map[i][j];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>dir[i];
    init();
    dfs(sx,sy,1);
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
            cout<<map[i][j];
        cout<<endl;
    }
    
    return 0;
}
