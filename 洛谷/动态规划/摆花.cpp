#include <stdio.h>
#include <string.h>
#include<iostream>
#include <vector>
// #include <algorithm>
#include<climits>
using namespace std;
int num[105];//����������
int dp[105][105];//�������� �����ܸ���
const int mod=1e6+7;
int main()
{
    int n,m;cin>>n>>m;//���������������
    for(int i=1;i<=n;i++)
        cin>>num[i];//һ�໨����ܰݷö�����
    //Ҫ��һ�趼���ã���ô�޷�����m�軨 ����0 0=1
    dp[0][0]=1;
    //��״̬ת�Ʊ�
    for(int i=1;i<=n;i++)//��1��ʼ ��һ������  ��Ϊ������i-1�����Եô�1��ʼ
    {
        for(int j=0;j<=m;j++)//��0��ʼ���ܹ�0��
        {
            for(int k=0;k<=min(j,num[i]);k++)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}