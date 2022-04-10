/*给定三个整数数组
A = [A1, A2, … AN],
B = [B1, B2, … BN],
C = [C1, C2, … CN]，
请你统计有多少个三元组(i, j, k) 满足：
1 <= i, j, k <= N
Ai < Bj < Ck
【输入格式】
第一行包含一个整数N。
第二行包含N个整数A1, A2, … AN。
第三行包含N个整数B1, B2, … BN。
第四行包含N个整数C1, C2, … CN。
对于30%的数据，1 <= N <= 100
对于60%的数据，1 <= N <= 1000
对于100%的数据，1 <= N <= 100000 0 <= Ai, Bi, Ci <= 100000
例如：
3
1 1 1
2 2 2
3 3 3*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100005//定义数据最大规模
int A[N];//定义三个数组中最小的那个
int B[N];//定义三个中中间的那个
int C[N];//定义三个中最大的那个
int t[N];//定义t数组用来保存在数组a中小于b数组中某个元素的元素个数
void test()//三层暴力递归
{
    int n;cin>>n;
    vector<int> A(n),B(n),C(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>C[i];
    }
    unsigned long long ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(A[i]<B[j] && B[j]<C[k])ans++;
            }
        }
    }
    cout<<ans;
}
void test2()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>C[i];
    }
    unsigned long long ans=0;
    sort(A,A+n);sort(B,B+n);sort(C,C+n);//全部排序先
    int i=n-1,j=n-1;//A和B从右边开始
    while(i>=0 && j>=0)
    {
        if(A[i]<B[j])
        {
            t[j]=i+1;
            j--;
        }
        else i--;
    }
    i=0,j=0;
    while(i<n && j<n)
    {
        if(C[j]>B[i])
        {
            ans+=(n-j)*t[i];
            i++;
        }
        else j++;
    }
    cout<<ans;
}
int main()
{
    test2();
    return 0;
}