//https://www.lanqiao.cn/problems/98/learning/
#include <iostream>
using namespace std;
//知识点：最大公约数的求法；完全背包问题

int n;
int num[105];
int dp[100005];
int gcd(int x,int y)
{
  if(x==0)return y;
  return gcd(y%x,x);
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>num[i];
  int g=num[1];
  for(int i=2;i<=n;i++)
  {
    g=gcd(g,num[i]);
  }
  if(g!=1)
  {
    cout<<"INF";
    return 0;
  }
  dp[0]=1;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=1e5;j++)//当前背包容量
    {
      if(j-num[i]>=0)dp[j]+=dp[j-num[i]];
    }
  }
  int ans=0;
  for(int i=1;i<=1e5;i++)
  {
    if(dp[i]==0)ans++;
  }
  cout<<ans;
  return 0;
}