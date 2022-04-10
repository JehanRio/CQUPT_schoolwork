/*8儿童节那天有K位小朋友到小明家做客。小明拿出了珍藏的巧克力招待小朋友们。
小明一共有N块巧克力，其中第i块是Hi x Wi的方格组成的长方形。
为了公平起见，小明需要从这 N 块巧克力中切出K块巧克力分给小朋友们。切出的巧克力需要满足：
1. 形状是正方形，边长是整数
2. 大小相同
例如一块6x5的巧克力可以切出6块2x2的巧克力或者2块3x3的巧克力。
当然小朋友们都希望得到的巧克力尽可能大，你能帮小Hi计算出最大的边长是多少么？
输入
第一行包含两个整数N和K。(1 <= N, K <= 100000)
以下N行每行包含两个整数Hi和Wi。(1 <= Hi, Wi <= 100000)
输入保证每位小朋友至少能获得一块1x1的巧克力。
输出
输出切出的正方形巧克力最大可能的边长。
样例输入：
2 10
6 5
5 6
样例输出：
2*/
#include<iostream>
using namespace std;
struct cho
{
    int h,w;
}cho[100000];
int N,K;

bool check(int len)
{
    int m=0;
    for(int i=0;i<N;i++)
    {
        m+=cho[i].h/len * cho[i].w/len;
    }
    return m>=K;
}
//二分法
int solve(int left,int right)
{
    int mid;
    while(left!=right)
    {
        mid=left+(right-left)/2;//mid每一次循环要重新定位
        if(!check(mid))
            right=mid;
        else left=mid+1;//这样保证了right是不满足条件的 left是满足条件的 但left+1不知道是否满不满足 若最后left=right 那么left-1就是答案
    }
    return left-1;
}
int main()
{
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        cin>>cho[i].h>>cho[i].w;
    }
    cout<<solve(1,100000);
    return 0;
}