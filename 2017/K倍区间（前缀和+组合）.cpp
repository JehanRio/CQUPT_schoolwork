/*����һ������ΪN�����У�A1, A2, �� AN���������һ��������������Ai, Ai+1, �� Aj(i <= j)֮����K�ı��������Ǿͳ��������[i, j]��K�����䡣
��������������ܹ��ж��ٸ�K��������
����
��һ�а�����������N��K��(1 <= N, K <= 100000)
����N��ÿ�а���һ������Ai��(1 <= Ai <= 100000)
���
���һ������������K���������Ŀ��
���磬
���룺
5 2
1
2
3
4
5
����Ӧ�������
6*/
#include<iostream>
#include<cmath>
using namespace std;
//https://blog.csdn.net/qq_40563761/article/details/107116983?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164552486416780264036537%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164552486416780264036537&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-4-107116983.pc_search_result_cache&utm_term=K%E5%80%8D%E5%8C%BA%E9%97%B4&spm=1018.2226.3001.4187
//֪ʶ�㣺ǰ׺�ͣ�ǰN��ĺͣ����Cn2 : a[i]*(a[i]-1)/2;

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
    long long ans=0;//�ǵó�ʼ��
    for(int i=0;i<k;i++)
    {
        ans+=yushu[i]*(yushu[i]-1)/2;
    }
    ans+=yushu[0];//���ս������ǰ׺��ģkΪ0�����䣨�����������k�����䣬������ϣ� 
    cout<<ans;
    return 0;
}