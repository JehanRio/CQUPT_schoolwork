/*����һ���ַ��� S�����Ƕ��� S �ķ�ֵ f (S ) Ϊ S �г��ֵĲ�ͬ���ַ���
�������� f (��aba��) = 2�� f (��abc��) = 3, f (��aaa��) = 1��
���ڸ���һ���ַ��� S [0::n ?6?1 1]������Ϊ n������������������ S �ķǿ�
�Ӵ� S [i:: j](0 �� i �� j < n)�� f (S [i:: j]) �ĺ��Ƕ��١�
�������ʽ��
����һ�а���һ����Сд��ĸ��ɵ��ַ���S��
�������ʽ��
���һ��������ʾ�𰸡�
���������롿
ababc
�����������
28
������˵����
�Ӵ� fֵ
a 1
ab 2
aba 2
abab 2
ababc 3
b 1
ba 2
bab 2
babc 3
a 1
ab 2
abc 3
b 1
bc 2
c 1*/
#include<iostream>
#include<set>
#include<string>
using namespace std;
string s;
int ans=0;
void check(int i,int j)
{
    int m=0;
    set<char> st;
    for(int a=i;a<=j;a++)
    {
        if(st.find(s[a])==st.end())//�ֵ���û�и���ĸ
        {
            m++;
            st.insert(s[a]);
        }
    }
    ans+=m;
}
int main()
{
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            check(i,j);
        }
    }
    cout<<ans;
}