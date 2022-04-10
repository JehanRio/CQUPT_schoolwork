/*
X 国王有一个地宫宝库。是 n x m 个格子的矩阵。每个格子放一件宝贝。每个宝贝贴着价值标签。

地宫的入口在左上角，出口在右下角。

小明被带到地宫的入口，国王要求他只能向右或向下行走。

走过某个格子时，如果那个格子中的宝贝价值比小明手中任意宝贝价值都大，小明就可以拿起它（当然，也可以不拿）。

当小明走到出口时，如果他手中的宝贝恰好是k件，则这些宝贝就可以送给小明。

请你帮小明算一算，在给定的局面下，他有多少种不同的行动方案能获得这k件宝贝。
输入
输入一行3个整数，用空格分开：n m k (1< =n,m< =50, 1< =k< =12)

接下来有 n 行数据，每行有 m 个整数 Ci (0< =Ci< =12)代表这个格子上的宝物的价值
输出
要求输出一个整数，表示正好取k个宝贝的行动方案数。该数字可能很大，输出它对 1000000007 取模的结果。
样例输入
2 3 2
1 2 3
2 1 5
样例输出
14
*/
#include<iostream>
#include<cstring>
using namespace std;
#define mod 1000000007
//https://blog.csdn.net/weixin_41232804/article/details/90266341?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164484367016780261967484%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164484367016780261967484&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-1-90266341.pc_search_result_cache&utm_term=%E5%9C%B0%E5%AE%AB%E5%8F%96%E5%AE%9D&spm=1018.2226.3001.4187
int dp[50][50][13][13];////比如dp[3][4][5][6]就是在（3，4）这个点时手里拥有5个宝物,最大价值为6 
int mp[50][50];//该坐标的宝贝价值大小
int m,n,k;

int dfs(int x,int y,int sum,int max)
{
    if(dp[x][y][sum][max]!=-1)//备忘录
        return dp[x][y][sum][max];
    if(x==n && y==m)//到达终点
    {
        if(sum==k || (sum==k-1 && mp[x][y]>max))//如果手中的宝物已经有k个则选择不拿终点的宝物 或者 手中的宝物有k-1个 
            return dp[x][y][sum][max+1]=1;//而此时终点的宝物价值大于max,便拿起终点的宝物(对终点宝物的拿与不拿)
        else return dp[x][y][sum][max+1]=0;//不符合就表示该方案不可行,返回0 
    }
    long long cnt=0;
    if(x+1<=n)//如果可以往下走
    {
        if(mp[x][y]>max)
            cnt=(cnt+dfs(x+1,y,sum+1,mp[x][y]))%mod;
        cnt=(cnt+dfs(x+1,y,sum,max))%mod;
    }
    if(y+1<=m)
    {
        if(max<mp[x][y])
            cnt=(cnt+dfs(x,y+1,sum+1,mp[x][y]))%mod;
        cnt=(cnt+dfs(x,y+1,sum,max))%mod;
    }
    dp[x][y][sum][max+1]=cnt;
    return cnt;
}
int main()
{
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));//全部初始化为-1
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mp[i][j];
    dfs(1,1,0,-1);
    cout<<dp[1][1][0][0];
    return 0;
}