/*�����������Ϊ n ������ A1,A2,?6?6?6?6?6?6,An������Դ���ѡ�������� Ai �� Aj ( i ������ j )��Ȼ�� Ai �� Aj һǰһ��ƴ��һ���µ����������� 12 �� 345 ����ƴ�� 12345 �� 34512��ע�⽻�� Ai �� Aj ��˳�����Ǳ���Ϊ 2 ��ƴ���������� Ai=Aj ʱ��
��������ж�����ƴ������ƴ���������� K �ı�����
�������ʽ��
��һ�а��� 2 ������ n �� K��
�ڶ��а��� n ������ A1,A2,?6?6?6?6?6?6,An��
�������ʽ��
һ����������𰸡�
������������ģ��Լ����
���� 30% ������������1��n��1000,1��K��20,1��Ai��104��
������������������1��n��105��1��K��105��1��Ai��109��*/
#include<iostream>
#include<cmath>
using namespace std;
int n,k;
int num[100005];
int ans;
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>num[i];
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(num[i]%k==0 && num[j]%k==0)
            {
                ans+=2;
                continue;
            }
            int num_1=log10(num[i]),num_2=log10(num[j]);////�����������λ��
            long long num1=num[j]*pow(10,num_1+1)+num[i],num2=num[i]*pow(10,num_2+1)+num[j];
            if(num1%k==0)ans++;
            if(num2%k==0)ans++;
        }
    }
    cout<<ans;
    return 0;
}