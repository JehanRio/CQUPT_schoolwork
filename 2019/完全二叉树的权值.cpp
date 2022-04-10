/*给定一棵包含 N 个节点的完全二叉树，树上每个节点都有一个权值，按从 上到下、从左到右的顺序依次是 A1, A2, · · · AN，
现在小明要把相同深度的节点的权值加在一起，他想知道哪个深度的节点 权值之和最大?如果有多个深度的权值和同为最大，请你输出其中最小的深度。
注:根的深度是 1。
输入
第一行包含一个整数 N。 第二行包含N个整数A1,A2,··· AN。
输出
输出一个整数代表答案。
样例输入
7
1 6 5 4 3 2 1
样例输出
2*/
#include<iostream>
using namespace std;
int maxleveltree(int n)
{
    int cur=0,max=0;
    int maxlevel;
    int level=1;
    for(int i=1;i<=n;i++)
    {
        if(level==1);
        else
            level*=2;
        int sum=0;//求当前层数的和
        for(int j=1;j<=level;j++)
        {
            cin>>cur;
            sum+=cur;
        }
        if(sum>max)
        {
            max=sum;
            maxlevel=i;
        }
    }
    return maxlevel;
}
int main()
{
    int n;cin>>n;
    cout<<maxleveltree(n);
    return 0;
}