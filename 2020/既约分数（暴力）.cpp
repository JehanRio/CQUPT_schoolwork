/*���һ�������ķ��Ӻͷ�ĸ�����Լ����1�����������Ϊ��Լ������
���磬3/4,5/2,1/8,7/1���Ǽ�Լ���������ʣ��ж��ٸ���Լ���������Ӻͷ�ĸ����1��2020֮�������������1��2020��*/
#include<iostream>
using namespace std;

//֪ʶ�㣺���Լ���жϣ��ݹ飩
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
int gcd2(int x,int y)
{
    if(x==0)return y;
    return gcd2(y%x,x);
}
int gcd1(int x,int y)
{
    if(x%y==0)return y;
    return gcd1(y,x%y);
}
int main()
{
    int ans=0;
    for(int i=1;i<=2020;i++)
    {
        for(int j=1;j<=2020;j++)
        {
            if(gcd1(i,j)==1)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
