#include<iostream>
#include<cmath>
using namespace std;
//��״̬ת�Ʊ� ȷ��for��״̬��������
int n,m;
int dp[35][35];//����������
int main()
{
    cin>>n>>m;//�����ʹ���
    dp[0][1]=1;//1���� ��0��
    for(int i=1;i<=m;i++)//����
    {
        for(int j=1;j<=n;j++)//�ڼ�����
        {
            int a=j-1,b=j+1;
            if(a==0)a=n;
            if(b==n+1)b=1;
            dp[i][j]=dp[i-1][a]+dp[i-1][b];
        }
    }
    cout<<dp[m][1];
}