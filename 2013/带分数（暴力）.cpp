/*100可以表示为带分数的形式：100=3+69258/714，还可以表示为：100=82+3546/197，注意特征：
带分数中，数字1~9分别出现且只出现一次（不包含0）。类似这样的带分数，100有11种表示法。
题目要求：从标准输入读入一个正整数N（N<1000*1000）程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。注意：不要求输出每个表示，只统计有多少表示法！
例如，用户输入：100
程序输出：11
再例如，用户输入：105
程序输出：6
*/
#include<iostream>
#include<algorithm>
using namespace std;
int num[9]={1,2,3,4,5,6,7,8,9};
int change(int a,int b)
{
    int sum=0;
    for(int i=a;i<=b;i++)
    sum=sum*10+num[i];
    return sum;
}
int main()
{
    int ans=0;
    int n;cin>>n;//输入数字
    long long a,b,c;
    do
    {
        for(int i=0;i<7;i++)
        {
            for(int j=i+1;j<8;j++)
            {
                a=change(0,i);
                b=change(i+1,j);
                c=change(j+1,8);
                if(c*n==a*c+b)
                    ans++;
            }
        }
    }while(next_permutation(num,num+9));
    cout<<ans;
    return 0;
}
