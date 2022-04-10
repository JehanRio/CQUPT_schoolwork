/*小明被劫持到X赌城，被迫与其他3人玩牌。
一副扑克牌（去掉大小王牌，共52张），均匀发给4个人，每个人13张。
这时，小明脑子里突然冒出一个问题：
如果不考虑花色，只考虑点数，也不考虑自己得到的牌的先后顺序，自己手里能拿到的初始牌型组合一共有多少种呢？
请填写该整数，不要填写任何多余的内容或说明文字。
*/
#include<iostream>
#include<set>
#include<cstring>
using namespace std;
//递归回溯
int ans=0;
int n=0;//记录当前手牌数量
void dfs(int num)//num 哪一种类型的牌
{
    if(n>13 || num>13) return;//大于13张牌 不行
        if(n==13)//当前手牌为13张
        {
             ans++;
            return;
        }
    for(int i=0;i<=4;i++)//回溯操作
    {
        n+=i;//手牌加i张
        dfs(num+1);//卡牌个数往下继续搜索
        n-=i;//消除
    }
}
int main()
{
    dfs(0);
    cout<<ans;
    return 0;

}