/**小明维护着一个程序员论坛。现在他收集了一份"点赞"日志，日志共有N行。其中每一行的格式是：
ts id
表示在ts时刻编号id的帖子收到一个"赞"。
现在小明想统计有哪些帖子曾经是"热帖"。如果一个帖子曾在任意一个长度为D的时间段内收到不少于K个赞，小明就认为这个帖子曾是"热帖"。
具体来说，如果存在某个时刻T满足该帖在[T, T+D)这段时间内(注意是左闭右开区间)收到不少于K个赞，该帖就曾是"热帖"。
给定日志，请你帮助小明统计出所有曾是"热帖"的帖子编号。
【输入格式】
第一行包含三个整数N、D和K。
以下N行每行一条日志，包含两个整数ts和id。
对于50%的数据，1 <= K <= N <= 1000
对于100%的数据，1 <= K <= N <= 100000 0 <= ts <= 100000 0 <= id <= 100000
【输出格式】
按从小到大的顺序输出热帖id。每个id一行。
【输入样例】
7 10 2
0 1
0 10
10 10
10 1
9 1
100 3
100 3
【输出样例】
1
3
**/
#include<algorithm>
#include<iostream>
using namespace std;
pair<int,int> map[100000];
int cnt[100000];//用于存储某个帖子时间段内的个数
bool judge[100000];//用来判断是否为热帖
int n,d,k;
int main()
{
    cin>>n>>d>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&map[i].first,&map[i].second);
    }
    sort(map,map+n);//pair 默认对first升序，当first相同时对second升序；
    for(int i=0,j=0;i<n;i++)
    {
        int tem=map[i].second;
        cnt[tem]++;//该帖子加一
        while(map[i].first-map[j].first >= d)//超过时间段 滑动窗口
        {
            cnt[map[j].second]--;        
            j++;
        }
        if(cnt[tem]>=k)judge[tem]=1;
    }
    for(int i=0;i<100000;i++)
    {
        if(judge[i])cout<<i<<endl;
    }
    return 0;
}