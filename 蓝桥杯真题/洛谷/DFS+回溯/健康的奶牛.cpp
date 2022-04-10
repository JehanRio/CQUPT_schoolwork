//https://www.luogu.com.cn/problem/P1460
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<cmath>
using namespace std;
int ans[1000];//这个数组是来存储解的。 
int a[1000];//表示牛每天需要的每种维他命的最小量。 
int b[1000][1000];//每种饲料包含的各种维他命的量的多少。
int c[1000];//每次搜索选的饲料编号 
int n,m,minn=100000000;
bool pd(int x)//这是判断每次选的那些饲料中的维生素之和是不是都大于等于牛每天需要的每种维他命的最小量的函数 
{
	for(int i=1; i<=n; i++)
	{
		int sum=0;
		for(int j=1; j<=x; j++)
		sum+=b[c[j]][i];//用一个sum累加 
		if(sum<a[i]) return false;//如果有一项维生素比牛需要的维生素要少，直接返回false 
	}
	return true;
}
void search(int t,int s)//搜索的函数 
{
	if(t>m)//边界
	{
		if(pd(s))//必须得满足条件
		{
			if(s<minn)//判断选的饲料的总数小于以前的最优解
			{
				minn=s;//替换掉
				for(int i=1; i<=minn; i++)
				{
					ans[i]=c[i];//答案的数组也要被替换
				}
			}
		}
		return; //返回
	}
	c[s+1]=t;//把t放在数组里
	search(t+1,s+1);//搜索一步
	c[s+1]=0;//回溯一步
	search(t+1,s);//如果不选第t种饲料的操作
}
int main()//主函数部分
{
	cin>>n;//读入
	for(int i=1; i<=n; i++)
	cin>>a[i];//读入
	cin>>m;//读入
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		cin>>b[i][j];//还是读入
	}
	search(1,0);//调用搜索函数
	cout<<minn<<' ';//输出
	for(int i=1; i<=minn; i++)
	cout<<ans[i]<<' ';//还是输出
	return 0;//结束程序
}