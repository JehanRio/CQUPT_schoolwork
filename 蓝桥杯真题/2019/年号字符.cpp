/*С������ĸ A��Ӧ���� 1��B��Ӧ 2���Դ����ƣ��� Z��Ӧ 26������ 27���ϵ����֣�С������λ�����λ���ַ�������Ӧ������ AA��Ӧ27��AB��
Ӧ28��AZ��Ӧ52��LQ��Ӧ329��
����2019��Ӧ���ַ�����ʲô��*/
#include<iostream>
#include<stack>
using namespace std;

//֪ʶ�㣺����ת��
int main()
{
    int n=2019;
    stack<char> stk;
    while(n)
    {
        stk.push('A'+n%26-1);//�ǵü�1
        n/=26;
    }
    while(!stk.empty())
    {
        cout<<stk.top();
        stk.pop();
    }
    return 0;
}