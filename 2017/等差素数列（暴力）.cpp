/**2,3,5,7,11,13,…是素数序列。
类似：7,37,67,97,127,157 这样完全由素数组成的等差数列，叫等差素数数列。
上边的数列公差为30，长度为6。
2004年，格林与华人陶哲轩合作证明了：存在任意长度的素数等差数列。
这是数论领域一项惊人的成果！
有这一理论为基础，请你借助手中的计算机，满怀信心地搜索：
长度为10的等差素数列，其公差最小值是多少？
注意：需要提交的是一个整数，不要填写任何多余的内容和说明文字。*/
#include<iostream>
#include<cmath>
using namespace std;

//知识点：素数的判断方法、暴力穷举

bool isprime(int a)
{
    for(int i=2;i*i<=a;i++)//素数判断 如果平方以下的数字都没有能整除的 就是素数
    {
        if(a%i==0)
            return false;
    }
    return true;
}
int prime[100009];
int main()
{
    for(int i=2;i<=100009;i++)
    {
        if(isprime(i))
            prime[i]=1;//素数打表
    }
    for(int i=2;i<=1000;i++)//枚举公差
    {
        for(int j=2;j<=10000;j++)//枚举第一项
        {
            int flag=0;
            if(prime[j]==0)continue;
            for(int k=1;k<=9;k++)//后面9项
            {
                if(prime[j+i*k]==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}