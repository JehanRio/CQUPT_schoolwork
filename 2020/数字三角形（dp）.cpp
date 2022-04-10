#include <iostream>
#include<cmath>
using namespace std;
int map[105][105];
int n;
int summ=0;
void dfs(int l,int r,int x,int y,int cur)
{
    if(x==n)
    {
        if(abs(l-r)>1)return;
        summ=max(summ,cur);
        return;
    }
    dfs(l+1,r,x+1,y,cur+map[x+1][y]);//×ó±ß
    dfs(l,r+1,x+1,y+1,cur+map[x+1][y+1]);//ÓÒ±ß
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=i;j++)
        cin>>map[i][j];
  }
  dfs(0,0,1,1,map[1][1]);
  cout<<summ;
  return 0;
}