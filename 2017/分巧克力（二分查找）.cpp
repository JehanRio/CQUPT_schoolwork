/*8��ͯ��������KλС���ѵ�С�������͡�С���ó�����ص��ɿ����д�С�����ǡ�
С��һ����N���ɿ��������е�i����Hi x Wi�ķ�����ɵĳ����Ρ�
Ϊ�˹�ƽ�����С����Ҫ���� N ���ɿ������г�K���ɿ����ָ�С�����ǡ��г����ɿ�����Ҫ���㣺
1. ��״�������Σ��߳�������
2. ��С��ͬ
����һ��6x5���ɿ��������г�6��2x2���ɿ�������2��3x3���ɿ�����
��ȻС�����Ƕ�ϣ���õ����ɿ��������ܴ����ܰ�СHi��������ı߳��Ƕ���ô��
����
��һ�а�����������N��K��(1 <= N, K <= 100000)
����N��ÿ�а�����������Hi��Wi��(1 <= Hi, Wi <= 100000)
���뱣֤ÿλС���������ܻ��һ��1x1���ɿ�����
���
����г����������ɿ��������ܵı߳���
�������룺
2 10
6 5
5 6
���������
2*/
#include<iostream>
using namespace std;
struct cho
{
    int h,w;
}cho[100000];
int N,K;

bool check(int len)
{
    int m=0;
    for(int i=0;i<N;i++)
    {
        m+=cho[i].h/len * cho[i].w/len;
    }
    return m>=K;
}
//���ַ�
int solve(int left,int right)
{
    int mid;
    while(left!=right)
    {
        mid=left+(right-left)/2;//midÿһ��ѭ��Ҫ���¶�λ
        if(!check(mid))
            right=mid;
        else left=mid+1;//������֤��right�ǲ����������� left������������ ��left+1��֪���Ƿ��������� �����left=right ��ôleft-1���Ǵ�
    }
    return left-1;
}
int main()
{
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        cin>>cho[i].h>>cho[i].w;
    }
    cout<<solve(1,100000);
    return 0;
}