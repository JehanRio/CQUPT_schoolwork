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
void dfs(int x,int y)//从左到右 从上往下
{
	if(y==m+1)//到y的边界了，搜索下一行 
	{
		dfs(x+1,1);
		return;
	}
	if(x==n+1)
	{
		mx=max(mx,ans);
		return;
	}
	if(vis[x][y]==0)//取该数 前提是这个数是可以访问的
	{
		ans+=map[x][y];
		for(int dx=0;dx<8;dx++)
		{
			vis[x+d[dx][0]][y+d[dx][1]]++;//标记该数字的附近
		}
		dfs(x,y+1); 

		for(int dx=0;dx<8;dx++)//回溯 
		{
			vis[x+d[dx][0]][y+d[dx][1]]--;
		}
		ans-=map[x][y];
	}
	dfs(x,y+1);//不取该数
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
// 	if(vis[x][y])return;//如果不可访问 则返回
// 	for(int dx=0;dx<8;dx++)
// 	{
// 		vis[x+d[dx][0]][y+d[dx][1]]++;//标记该数字的附近
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