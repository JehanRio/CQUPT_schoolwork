//https://www.luogu.com.cn/problem/P1460
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<cmath>
using namespace std;
int ans[1000];//������������洢��ġ� 
int a[1000];//��ʾţÿ����Ҫ��ÿ��ά��������С���� 
int b[1000][1000];//ÿ�����ϰ����ĸ���ά���������Ķ��١�
int c[1000];//ÿ������ѡ�����ϱ�� 
int n,m,minn=100000000;
bool pd(int x)//�����ж�ÿ��ѡ����Щ�����е�ά����֮���ǲ��Ƕ����ڵ���ţÿ����Ҫ��ÿ��ά��������С���ĺ��� 
{
	for(int i=1; i<=n; i++)
	{
		int sum=0;
		for(int j=1; j<=x; j++)
		sum+=b[c[j]][i];//��һ��sum�ۼ� 
		if(sum<a[i]) return false;//�����һ��ά���ر�ţ��Ҫ��ά����Ҫ�٣�ֱ�ӷ���false 
	}
	return true;
}
void search(int t,int s)//�����ĺ��� 
{
	if(t>m)//�߽�
	{
		if(pd(s))//�������������
		{
			if(s<minn)//�ж�ѡ�����ϵ�����С����ǰ�����Ž�
			{
				minn=s;//�滻��
				for(int i=1; i<=minn; i++)
				{
					ans[i]=c[i];//�𰸵�����ҲҪ���滻
				}
			}
		}
		return; //����
	}
	c[s+1]=t;//��t����������
	search(t+1,s+1);//����һ��
	c[s+1]=0;//����һ��
	search(t+1,s);//�����ѡ��t�����ϵĲ���
}
int main()//����������
{
	cin>>n;//����
	for(int i=1; i<=n; i++)
	cin>>a[i];//����
	cin>>m;//����
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		cin>>b[i][j];//���Ƕ���
	}
	search(1,0);//������������
	cout<<minn<<' ';//���
	for(int i=1; i<=minn; i++)
	cout<<ans[i]<<' ';//�������
	return 0;//��������
}