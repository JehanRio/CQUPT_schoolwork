/*��12������һ���12��Ф����Ʊ��������Ҫ���м���5������Ҫ����������ŵġ�����������һ���ǲ���������
������㣬һ���ж����ֲ�ͬ�ļ�ȡ������*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int vis[3][4];//����ȷ�������ظ�����
int g[3][4];//���ڴ���ļ�������ѡȡ
int cur=0;//���ڹۿ��м���������һƬ
int num[5];//���ڴ�����ѡȡ������
int ans=0;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y)
{
    vis[x][y]=1;//��ֹ�ظ�ѡȡ
    cur++;
    for(int i=0;i<4;i++)
    {
        int dx=x+dir[i][0],dy=y+dir[i][1];//�µĺ�������
        if(dx>=0 && dx<3 && dy>=0 && dy<4 && vis[dx][dy]==0 && g[dx][dy]==1)
            dfs(dx,dy);
    }
    
}
void check(int step,int k)
{
    if(step==5)//�������������
    {
        int x,y;
        for(int i=0;i<5;i++)//����������в���
        {
            x=(num[i]-1)/4;//������
            y=(num[i]-1)%4;//������
            g[x][y]=1;//�������ѱ�ѡȡ
        }
        dfs((num[0]-1)/4,(num[0]-1)%4);//�Ե�һ���������ж�
        if(cur==5)
            ans++;
        cur=0;//���������
        memset(vis,0,sizeof(vis));
        memset(g,0,sizeof(g));
        return;
    }
    for(int i=k;i<=12;i++)
    {
        num[step]=i;//���ڴ�ŵ�һ�����ڶ�����������������
        check(step+1,i+1);//step+1��ʾ����һ����������k=i ��һ�εڶ��������Ǵ�2��ʼ
    }
}
int main()
{
    check(0,1);
    cout<<ans;
    return 0;
}