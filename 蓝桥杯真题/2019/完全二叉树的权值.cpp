/*����һ�ð��� N ���ڵ����ȫ������������ÿ���ڵ㶼��һ��Ȩֵ������ �ϵ��¡������ҵ�˳�������� A1, A2, �� �� �� AN��
����С��Ҫ����ͬ��ȵĽڵ��Ȩֵ����һ������֪���ĸ���ȵĽڵ� Ȩֵ֮�����?����ж����ȵ�Ȩֵ��ͬΪ����������������С����ȡ�
ע:��������� 1��
����
��һ�а���һ������ N�� �ڶ��а���N������A1,A2,������ AN��
���
���һ����������𰸡�
��������
7
1 6 5 4 3 2 1
�������
2*/
#include<iostream>
using namespace std;
int maxleveltree(int n)
{
    int cur=0,max=0;
    int maxlevel;
    int level=1;
    for(int i=1;i<=n;i++)
    {
        if(level==1);
        else
            level*=2;
        int sum=0;//��ǰ�����ĺ�
        for(int j=1;j<=level;j++)
        {
            cin>>cur;
            sum+=cur;
        }
        if(sum>max)
        {
            max=sum;
            maxlevel=i;
        }
    }
    return maxlevel;
}
int main()
{
    int n;cin>>n;
    cout<<maxleveltree(n);
    return 0;
}