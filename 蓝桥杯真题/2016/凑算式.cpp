/*
       B       DEF
A +    ��    +  ������ = 10
       C       GHI

�����ʽ��A����1-9�����֣���ͬ����ĸ����ͬ�����֡�
���磺
6+8/3+952/714 ����һ�ֽⷨ��
5+3/1+972/486 ����һ�ֽⷨ��
�����ʽһ���ж����ֽⷨ��
ע�⣺���ύӦ���Ǹ���������Ҫ��д�κζ�������ݻ�˵�������֡�
*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int num[9]={1,2,3,4,5,6,7,8,9};
int ans=0;
int main()
{
    do
    {
        if(fabs(num[0] + num[1]*1.0/num[2] + (num[3]*100.0+num[4]*10+num[5])/(num[6]*100+num[7]*10+num[8]) - 10)<=1e-5)//��һ�����־�Ҫ����1.0
            ans++;
    }while(next_permutation(num,num+9));
    cout<<ans;
    return 0;
}