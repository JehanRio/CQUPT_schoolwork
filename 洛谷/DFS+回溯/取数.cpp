//https://www.luogu.com.cn/problem/P1123
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
const int d[8][2]={1,0,-1,0,0,1,0,-1,  1,1,1,-1,-1,1,-1,-1};
int vis[8][8];
int map[8][8];
int ans=0,mx=0;
int n,m;
void dfs(int x,int y)//������ ��������
{
	if(y==m+1)//��y�ı߽��ˣ�������һ�� 
	{
		dfs(x+1,1);
		return;
	}
	if(x==n+1)
	{
		mx=max(mx,ans);
		return;
	}
	if(vis[x][y]==0)//ȡ���� ǰ����������ǿ��Է��ʵ�
	{
		ans+=map[x][y];
		for(int dx=0;dx<8;dx++)
		{
			vis[x+d[dx][0]][y+d[dx][1]]++;//��Ǹ����ֵĸ���
		}
		dfs(x,y+1); 

		for(int dx=0;dx<8;dx++)//���� 
		{
			vis[x+d[dx][0]][y+d[dx][1]]--;
		}
		ans-=map[x][y];
	}
	dfs(x,y+1);//��ȡ����
}
// void dfs1(int x,int y)
// {
// 	if(y==m+1)
// 	{
// 		dfs1(x+1,1);
// 		return;
// 	}
// 	if(x==n+1)
// 	{
// 		mx=max(mx,ans);
// 		return;
// 	}
// 	if(vis[x][y])return;//������ɷ��� �򷵻�
// 	for(int dx=0;dx<8;dx++)
// 	{
// 		vis[x+d[dx][0]][y+d[dx][1]]++;//��Ǹ����ֵĸ���
// 	}
	//}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>map[i][j];
			}
		}
		mx=0;
		ans=0;
		dfs(1,1);
		cout<<mx<<endl;
	}
	return 0;
}