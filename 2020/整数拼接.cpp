/*给定义个长度为 n 的数组 A1,A2,?6?6?6?6?6?6,An。你可以从中选出两个数 Ai 和 Aj ( i 不等于 j )，然后将 Ai 和 Aj 一前一后拼成一个新的整数。例如 12 和 345 可以拼成 12345 或 34512。注意交换 Ai 和 Aj 的顺序总是被视为 2 种拼法，即便是 Ai=Aj 时。
请你计算有多少种拼法满足拼出的整数是 K 的倍数。
【输入格式】
第一行包含 2 个整数 n 和 K。
第二行包含 n 个整数 A1,A2,?6?6?6?6?6?6,An。
【输出格式】
一个整数代表答案。
【评测用例规模与约定】
对于 30% 的评测用例，1≤n≤1000,1≤K≤20,1≤Ai≤104。
对于所有评测用例，1≤n≤105，1≤K≤105，1≤Ai≤109。*/
#include<iostream>
#include<cmath>
using namespace std;
int n,k;
int num[100005];
int ans;
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>num[i];
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(num[i]%k==0 && num[j]%k==0)
            {
                ans+=2;
                continue;
            }
            int num_1=log10(num[i]),num_2=log10(num[j]);////求出两个数的位数
            long long num1=num[j]*pow(10,num_1+1)+num[i],num2=num[i]*pow(10,num_2+1)+num[j];
            if(num1%k==0)ans++;
            if(num2%k==0)ans++;
        }
    }
    cout<<ans;
    return 0;
}