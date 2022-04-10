/*����������������
A = [A1, A2, �� AN],
B = [B1, B2, �� BN],
C = [C1, C2, �� CN]��
����ͳ���ж��ٸ���Ԫ��(i, j, k) ���㣺
1 <= i, j, k <= N
Ai < Bj < Ck
�������ʽ��
��һ�а���һ������N��
�ڶ��а���N������A1, A2, �� AN��
�����а���N������B1, B2, �� BN��
�����а���N������C1, C2, �� CN��
����30%�����ݣ�1 <= N <= 100
����60%�����ݣ�1 <= N <= 1000
����100%�����ݣ�1 <= N <= 100000 0 <= Ai, Bi, Ci <= 100000
���磺
3
1 1 1
2 2 2
3 3 3*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100005//������������ģ
int A[N];//����������������С���Ǹ�
int B[N];//�����������м���Ǹ�
int C[N];//���������������Ǹ�
int t[N];//����t������������������a��С��b������ĳ��Ԫ�ص�Ԫ�ظ���
void test()//���㱩���ݹ�
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
    sort(A,A+n);sort(B,B+n);sort(C,C+n);//ȫ��������
    int i=n-1,j=n-1;//A��B���ұ߿�ʼ
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