/*小明对数位中含有 2、0、1、9 的数字很感兴趣（不包括前导 0） ，在 1 到
40 中这样的数包括 1、2、9、10 至 32、39 和 40，共 28 个，他们的和是 574。
请问，在 1 到 n 中，所有这样的数的和是多少？
【输入格式】
输入一行包含两个整数 n。
【输出格式】
输出一行，包含一个整数，表示满足条件的数的和。
【样例输入】
40
【样例输出】
574*/
#include<iostream>
using namespace std;
int ans=0;
bool judge(int a)
{
    while(a)
    {
        if(a%10==2 || a%10==0 || a%10==1 || a%10==9)
            return true;
        a/=10;
    }
    return false;
}
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(judge(i))
        ans+=i;
    }
    cout<<ans;
    return 0;
}