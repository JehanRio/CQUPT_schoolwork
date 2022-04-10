/*
       B       DEF
A +    —    +  ——— = 10
       C       GHI

这个算式中A代表1-9的数字，不同的字母代表不同的数字。
比如：
6+8/3+952/714 就是一种解法，
5+3/1+972/486 是另一种解法。
这个算式一共有多少种解法？
注意：你提交应该是个整数，不要填写任何多余的内容或说明性文字。
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
        if(fabs(num[0] + num[1]*1.0/num[2] + (num[3]*100.0+num[4]*10+num[5])/(num[6]*100+num[7]*10+num[8]) - 10)<=1e-5)//第一个数字就要乘以1.0
            ans++;
    }while(next_permutation(num,num+9));
    cout<<ans;
    return 0;
}