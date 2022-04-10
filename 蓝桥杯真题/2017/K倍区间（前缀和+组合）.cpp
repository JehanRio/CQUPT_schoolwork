/*给定一个长度为N的数列，A1, A2, … AN，如果其中一段连续的子序列Ai, Ai+1, … Aj(i <= j)之和是K的倍数，我们就称这个区间[i, j]是K倍区间。
你能求出数列中总共有多少个K倍区间吗？
输入
第一行包含两个整数N和K。(1 <= N, K <= 100000)
以下N行每行包含一个整数Ai。(1 <= Ai <= 100000)
输出
输出一个整数，代表K倍区间的数目。
例如，
输入：
5 2
1
2
3
4
5
程序应该输出：
6*/
#include<iostream>
#include<cmath>
using namespace std;
//https://blog.csdn.net/qq_40563761/article/details/107116983?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164552486416780264036537%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164552486416780264036537&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-4-107116983.pc_search_result_cache&utm_term=K%E5%80%8D%E5%8C%BA%E9%97%B4&spm=1018.2226.3001.4187
//知识点：前缀和：前N项的和；组合Cn2 : a[i]*(a[i]-1)/2;

int main()
{
    int n,k;
    int x;
    long long sum=0;
    int yushu[100000];
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        sum+=x;
        yushu[sum%k]++;
    }
    long long ans=0;//记得初始化
    for(int i=0;i<k;i++)
    {
        ans+=yushu[i]*(yushu[i]-1)/2;
    }
    ans+=yushu[0];//最终结果加上前缀和模k为0的区间（区间自身就是k倍区间，无需组合） 
    cout<<ans;
    return 0;
}