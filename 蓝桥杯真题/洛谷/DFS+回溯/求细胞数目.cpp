//https://www.luogu.com.cn/problem/P1451
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
char num[105][105];
int ans=0;
void dfs(int x,int y)
{
	if(x<1 || x>n || y<1 || y>m || num[x][y]=='0')return;
	num[x][y]='0';
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}
int main()
{
	cin>>n>>m;//n––m¡–
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)
	 	{
	 		cin>>num[i][j];
	 	}
	 }
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)
	 	{
	 		if(num[i][j]!='0')
	 		{
	 			ans++;
	 			dfs(i,j);
	 		}
	 	}
	 }
	 cout<<ans;
	 return 0;
}
