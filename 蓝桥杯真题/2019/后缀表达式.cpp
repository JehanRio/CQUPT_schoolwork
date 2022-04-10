/*
给定 N 个加号、M 个减号以及 N + M + 1 个整数 A 1 ,A 2 ,··· ,A N+M+1 ，小
明想知道在所有由这 N 个加号、M 个减号以及 N + M +1 个整数凑出的合法的
后缀表达式中，结果最大的是哪一个？
请你输出这个最大的结果。
例如使用1 2 3 + -，则 “2 3 + 1 -” 这个后缀表达式结果是 4，是最大的。
【输入格式】
第一行包含两个整数 N 和 M。
第二行包含 N + M + 1 个整数 A 1 ,A 2 ,··· ,A N+M+1 。
【输出格式】
输出一个整数，代表答案。
【样例输入】
1 1
1 2 3
【样例输出】
4
最大结果就是 最大值 - 最小值 + 剩余的绝对值 至于为什么要最大值减去最小值，只要假设全部为负号，最多也就是4-(1-2-3)而无法达到4-(-1-2-3)来解决.*/
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int main()
{
    cin>>n>>m;
    long long num[100005];
    for(int i=0;i<n+m+1;i++)
        cin>>num[i];
    long long sum=0;
    if(m==0)
    {
        for(int i=0;i<n+m+1;i++)
        {
            sum+=num[i];
        }
        cout<<sum;
        return 0;
    }
    sort(num,num+n+m+1);
    sum+=num[n+m];
    sum-=num[0];
    for(int i=1;i<m+n;i++)
    sum+=abs(num[i]);
    cout<<sum;
    return 0;
}