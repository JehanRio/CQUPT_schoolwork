/*��Ŀ����
��100���׵�ϸ��ֱ��������nֻ���ϡ����ǵ�ͷ�еĳ����еĳ��ҡ� ÿֻ���϶�ֻ�����Ÿ�����ǰ�����ٶ���1����/�롣����ֻ��������ʱ�����ǻ�ͬʱ��ͷ���෴�ķ������С���Щ�����У���1ֻ���ϸ�ð�ˡ������ں�������������ʱ����Ѹ�ð��Ⱦ�����������ϡ�������㣬���������϶��������ʱ���ж���ֻ���ϻ����˸�ð��
�����ݸ�ʽ��
��һ������һ������n (1 < n < 50), ��ʾ���ϵ�������
���ŵ�һ����n���ÿո�ֿ������� Xi (-100 < Xi < 100), Xi�ľ���ֵ����ʾ�����뿪������߶˵�ľ��롣��ֵ��ʾͷ���ң���ֵ��ʾͷ���������в������0ֵ��Ҳ���������ֻ����ռ��ͬһλ�á����У���һ�����ݴ�������ϸ�ð�ˡ�
Ҫ�����1����������ʾ����ð���ϵ���Ŀ��
���磬���룺
3
5 -2 8
����Ӧ�����
1
�����磬���룺
5
-10 8 -20 12 25
����Ӧ�����
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
	//getchar();//����Ҫ �����2013����Ʊ�����ⲻһ��
	int n;cin>>n;//�������ϵĸ���
	int flag=0,ans=1;//Ҫ��ʼ��
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	int ill=num[0];

	sort(num,num+n,compare);//������ֵ��С��������
	for(int i=0;i<n;i++)
	{
		if(num[i]==ill)
		{
			ill=i;//����ill������¼����������
			break;//����forѭ��
		}	
	}
	for(int i=0;i<ill;i++)//�ų�����ߵ�
	{
		if(num[i]>0) break;//˵�������ƶ����ʲ����ų�����ߵ�
		else num[i]=0;
	}
	for(int i=n-1;i>ill;i--)//�ų����ұߵ�
	{
		if(num[i]<0) break;//˵�������ƶ����ʲ����ų����ұߵ�
		else num[i]=0;
	}
	if(num[ill]<0)//�������
	{
		for(int i=ill-1;i>=0;i--)
		{
			if(num[i]==0) break;//˵�������������ȫ��������ߵ�
			if(num[i]>0)//�������ұ��ߵĶ��ᱻ��Ⱦ
			{
				ans++;
				flag=1;
			}
		}
		if(flag)//˵���������ҵ������ָ�Ⱦ�ģ������ұ�Ϯ��
		{
			for(int i=ill+1;i<n;i++)
			{
				if(num[i]==0) break;
				if(num[i]<0) ans++;//������ߵ�Ҳ�ᱻ��Ⱦ
			}
		}
	}
	else////��ð�����������ߵ�
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