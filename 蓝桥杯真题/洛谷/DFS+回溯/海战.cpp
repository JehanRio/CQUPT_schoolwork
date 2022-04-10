//https://www.luogu.com.cn/problem/P1331
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
char map[1005][1005]; 
int ans=0;
bool check(int x,int y)//如果不正确，那么一个2*2的格子里会只有3个#
{
	int c=0;
	if(map[x][y]=='#')c++;
	if(map[x+1][y]=='#')c++;
	if(map[x][y+1]=='#')c++;
	if(map[x+1][y+1]=='#')c++;
	if(c==3)return 0;
	return 1;
}
void dfs(int x,int y)
{
	if(x<1 || y<1 ||x>n || y>m || map[x][y]=='.')return;
	map[x][y]='.';
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y-1);
	dfs(x,y+1);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>map[i][j];
		}
	}
	for(int i=1;i<n;i++)//先判断是否正确 若不正确 就不用往下走了 
	{
		for(int j=1;j<m;j++)
		{
			if(!check(i,j))
			{
				cout<<"Bad placement";
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(map[i][j]=='#')//要判断再进入下面操作 
			{
				ans++;
				dfs(i,j);
			}
			
		}
	}
	 cout<<"There are "<<ans<<" ships.";
	 return 0; 
}

