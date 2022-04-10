/*把 2019分解成 3个各不相同的正整数之和，并且要求每个正整数都不包
含数字2和4，一共有多少种不同的分解方法？
注意交换 3个整数的顺序被视为同一种方法，例如 1000+1001+18和
1001+1000+18被视为同一种。*/
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
        for(int b=a+1;b<2019-a-b;b++)////2019-a-b表示第三个数 b要比第三个数小 3个数要各不相同  这样能保证 三个数的大小固定（a<b<c） 不会出现重复
        {
            if(judge(b) && judge(2019-a-b))
            ans++;
        }
    }
    cout<<ans;
}