/*小明刚刚看完电影《第39级台阶》，离开电影院的时候，他数了数礼堂前的台阶数，恰好是39级！站在台阶前，他突然又想着一个问题：
如果我每一步只能迈上1个或2个台阶，先迈左脚，然后左右交替，最后一步是迈右脚，也就是说一共要走偶数步。那么，上完39级台阶，有多少种不同的上法呢？
请你利用计算机的优势，帮助小明寻找答案。要求提交的是一个整数。
*/
#include<iostream>
using namespace std;
int ans=0;
void dp(int num,int foot)
{
    if(num>39) return;
    if(num==39)//该走右脚，并且剩余步数为1步或者2步
        {
            if(foot%2==0)
                ans++;
            return;
        }
    dp(num+1,foot+1);
    dp(num+2,foot+1);
}
int main()
{
    dp(1,1);
    dp(2,1);
    cout<<"答案是"<<ans;
    return 0;
}