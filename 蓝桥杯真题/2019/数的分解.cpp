/*�� 2019�ֽ�� 3��������ͬ��������֮�ͣ�����Ҫ��ÿ��������������
������2��4��һ���ж����ֲ�ͬ�ķֽⷽ����
ע�⽻�� 3��������˳����Ϊͬһ�ַ��������� 1000+1001+18��
1001+1000+18����Ϊͬһ�֡�*/
#include<iostream>
using namespace std;
bool judge(int a)
{
    while(a)
    {
        if(a%10==2 || a%10==4)
            return false;
        a/=10;
    }
    return true;
}
int main()
{
    int ans=0;
    for(int a=1;a<2019;a++)
    {
        if(judge(a))
        for(int b=a+1;b<2019-a-b;b++)////2019-a-b��ʾ�������� bҪ�ȵ�������С 3����Ҫ������ͬ  �����ܱ�֤ �������Ĵ�С�̶���a<b<c�� ��������ظ�
        {
            if(judge(b) && judge(2019-a-b))
            ans++;
        }
    }
    cout<<ans;
}