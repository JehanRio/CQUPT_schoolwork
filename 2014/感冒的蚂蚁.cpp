/*题目描述
长100厘米的细长直杆子上有n只蚂蚁。它们的头有的朝左，有的朝右。 每只蚂蚁都只能沿着杆子向前爬，速度是1厘米/秒。当两只蚂蚁碰面时，它们会同时掉头往相反的方向爬行。这些蚂蚁中，有1只蚂蚁感冒了。并且在和其它蚂蚁碰面时，会把感冒传染给碰到的蚂蚁。请你计算，当所有蚂蚁都爬离杆子时，有多少只蚂蚁患上了感冒。
【数据格式】
第一行输入一个整数n (1 < n < 50), 表示蚂蚁的总数。
接着的一行是n个用空格分开的整数 Xi (-100 < Xi < 100), Xi的绝对值，表示蚂蚁离开杆子左边端点的距离。正值表示头朝右，负值表示头朝左，数据中不会出现0值，也不会出现两只蚂蚁占用同一位置。其中，第一个数据代表的蚂蚁感冒了。
要求输出1个整数，表示最后感冒蚂蚁的数目。
例如，输入：
3
5 -2 8
程序应输出：
1
再例如，输入：
5
-10 8 -20 12 25
程序应输出：
3
*/
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
//https://blog.csdn.net/qq_36238595/article/details/54428316?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164482224916780261966105%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164482224916780261966105&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-1-54428316.pc_search_result_cache&utm_term=%E8%9A%82%E8%9A%81%E6%84%9F%E5%86%92&spm=1018.2226.3001.4187
bool compare(int a,int b)
{
	return fabs(a)<fabs(b);
}
int main()
{
	int num[51];
	//getchar();//不需要 这个和2013错误票据那题不一样
	int n;cin>>n;//输入蚂蚁的个数
	int flag=0,ans=1;//要初始化
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	int ill=num[0];

	sort(num,num+n,compare);//按绝对值从小到大排序
	for(int i=0;i<n;i++)
	{
		if(num[i]==ill)
		{
			ill=i;//现在ill用来记录生病的坐标
			break;//结束for循环
		}	
	}
	for(int i=0;i<ill;i++)//排除最左边的
	{
		if(num[i]>0) break;//说明向右移动，故不能排除最左边的
		else num[i]=0;
	}
	for(int i=n-1;i>ill;i--)//排除最右边的
	{
		if(num[i]<0) break;//说明向左移动，故不能排除最右边的
		else num[i]=0;
	}
	if(num[ill]<0)//向左边走
	{
		for(int i=ill-1;i>=0;i--)
		{
			if(num[i]==0) break;//说明生病蚂蚁左边全是往左边走的
			if(num[i]>0)//凡是往右边走的都会被感染
			{
				ans++;
				flag=1;
			}
		}
		if(flag)//说明从左往右的蚂蚁又感染的，正向右边袭来
		{
			for(int i=ill+1;i<n;i++)
			{
				if(num[i]==0) break;
				if(num[i]<0) ans++;//向左边走的也会被感染
			}
		}
	}
	else////感冒蚂蚁是向右走的
	{
		for(int i=ill+1;ill<n;ill++)
		{
			if(num[i]==0)break;
			if(num[i]<0)
			{
				ans++;
				flag=1;
			}
		}
		if(flag)
		{
			for(int i=ill-1;i>=0;i--)
			{
				if(num[i]==0) break;
				if(num[i]>0) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}