/*��ʥatm�����������������ӣ����ǰ�����һ��������һ���ϱߣ���������ŤŤ��Ҫ�ݳɷ����塣
�������ڹ۲죬atm �������ȶ����ӵİ��أ���Щ���ֵ������Żụ���ų⣡
���������淶һ�����ӣ�1 �Ķ����� 4��2 �Ķ����� 5��3 �Ķ����� 6��
������ m �黥������ÿ���е����������ֵ��������һ�����ӾͲ����ȶ�����������
atm�����һ���ж����ֲ�ͬ�Ŀ��ܵ������ӷ�ʽ��
���������ӷ�ʽ��ͬ�����ҽ��������ַ�ʽ�ж�Ӧ�߶ȵ����ӵĶ�Ӧ���ֵĳ�����ͬ��
���ڷ��������ܹ��࣬�����ģ 10^9 + 7 �Ľ����

��ҪС���� atm ����������Ŷ��

�������ʽ��
��һ���������� n m
n��ʾ������Ŀ
������ m �У�ÿ���������� a b ����ʾ a �� b ���ֲ��ܽ�����һ��

�������ʽ��
һ��һ��������ʾ��ģ 10^9 + 7 �Ľ����

���������롹
2 1
1 2

�����������
544
*/
#include<iostream>
#define ll long long
const ll MOD=1e9+7;
ll n, m, sum=0;
using namespace std;
//���Ӷ�Ӧ��
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
		if(hc[up][down]) continue;	//�ų�������� 
		ans = (ans + dfs(op[down], cnt-1))%MOD;
	}
	return ans;
}

int main()
{
	init();
	cin>>n>>m;
//	������ 
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin>>a>>b;
		hc[a][b]=true;
		hc[b][a]=true;
	}
	
//	dfs�ݹ飬��һ�����ӿ�������ţ�û������
	for(int down=1; down<=6; down++)			//down:���µ�����
	{
		sum=(sum + dfs(op[down], n-1))%MOD;		//op[down]:���ϵ����� 
	} 											//cnt:δ�ݵ������� 
	
//	4�Ŀ����� 
	ll ans4=1;
	ll temp=4;
	ll p=n;  
	while(p!=0)
	{
		if(p&1) ans4 = (ans4 * temp)%MOD;
		temp = (temp * temp)%MOD;
		p >>= 1;
	}
//	�۳�
/*	ll ans4=1;
	for(int i=0; i<n; i++)
	ans4 = (ans4 * 4)%MOD; */
	cout<<(sum*ans4)%MOD;
	return 0;
}
