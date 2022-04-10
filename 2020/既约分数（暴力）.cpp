/*如果一个分数的分子和分母的最大公约数是1，这个分数称为既约分数。
例如，3/4,5/2,1/8,7/1都是既约分数。请问，有多少个既约分数，分子和分母都是1到2020之间的整数（包括1和2020）*/
#include<iostream>
using namespace std;

//知识点：最大公约数判断（递归）
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
