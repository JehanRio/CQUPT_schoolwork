//https://www.luogu.com.cn/problem/P1036
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k; 
int ans=0;
int num[25];
int Sum=0;
bool prime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)return false;
	}
	return true;
}
bool isprime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)return false;
	}
	return true;
}
void dfs(int start,int count,int Sum)
{
	if(count==k)
	{
		if(isprime(Sum))ans++;
		return;
	}
	for(int i=start;i<=n;i++)
	{
		dfs(i+1,count+1,Sum+num[i]);
	}
}
void dfs1(int count,int start)//回溯
{
	if(count==k)
		ans+=isprime(Sum);
	else
	{
		for(int i=start;i<=n;i++)
		{
			Sum+=num[i];
			count++;
			dfs1(count,i+1);
			Sum-=num[i];
			count--;
		}
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	//dfs(1,0,0);//当前0个数，从下标1开始 
	dfs1(0,1);
	cout<<ans;
	return 0;
} 