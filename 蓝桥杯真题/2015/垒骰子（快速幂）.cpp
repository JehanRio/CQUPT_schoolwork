/*赌圣atm晚年迷恋上了垒骰子，就是把骰子一个垒在另一个上边，不能歪歪扭扭，要垒成方柱体。
经过长期观察，atm 发现了稳定骰子的奥秘：有些数字的面贴着会互相排斥！
我们先来规范一下骰子：1 的对面是 4，2 的对面是 5，3 的对面是 6。
假设有 m 组互斥现象，每组中的那两个数字的面紧贴在一起，骰子就不能稳定的垒起来。
atm想计算一下有多少种不同的可能的垒骰子方式。
两种垒骰子方式相同，当且仅当这两种方式中对应高度的骰子的对应数字的朝向都相同。
由于方案数可能过多，请输出模 10^9 + 7 的结果。

不要小看了 atm 的骰子数量哦～

「输入格式」
第一行两个整数 n m
n表示骰子数目
接下来 m 行，每行两个整数 a b ，表示 a 和 b 数字不能紧贴在一起。

「输出格式」
一行一个数，表示答案模 10^9 + 7 的结果。

「样例输入」
2 1
1 2

「样例输出」
544
*/
#include<iostream>
#define ll long long
const ll MOD=1e9+7;
ll n, m, sum=0;
using namespace std;
//骰子对应面
int op[7];
bool hc[7][7]={false};
void init(void)
{
	op[1]=4;
	op[4]=1;
	op[2]=5;
	op[5]=2;
	op[3]=6;
	op[6]=3;
} 

ll dfs(int up, ll cnt)
{
	if(cnt==0) return 1;
	ll ans=0;
	for(int down=1; down<=6; down++)
	{
		if(hc[up][down]) continue;	//排除互斥的面 
		ans = (ans + dfs(op[down], cnt-1))%MOD;
	}
	return ans;
}

int main()
{
	init();
	cin>>n>>m;
//	互斥面 
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin>>a>>b;
		hc[a][b]=true;
		hc[b][a]=true;
	}
	
//	dfs递归，第一个骰子可以任意放，没有限制
	for(int down=1; down<=6; down++)			//down:朝下的数字
	{
		sum=(sum + dfs(op[down], n-1))%MOD;		//op[down]:朝上的数字 
	} 											//cnt:未垒的骰子数 
	
//	4的快速幂 
	ll ans4=1;
	ll temp=4;
	ll p=n;  
	while(p!=0)
	{
		if(p&1) ans4 = (ans4 * temp)%MOD;
		temp = (temp * temp)%MOD;
		p >>= 1;
	}
//	累乘
/*	ll ans4=1;
	for(int i=0; i<n; i++)
	ans4 = (ans4 * 4)%MOD; */
	cout<<(sum*ans4)%MOD;
	return 0;
}
