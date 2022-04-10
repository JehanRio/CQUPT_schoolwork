/*在平面上有一些二维的点阵。
这些点的编号就像二维数组的编号一样，从上到下依次为第 1 至第 n 行，从左到右依次为第 1 至第 m 列，每一个点可以用行号和列号来表示。
现在有个人站在第 1 行第 1 列，要走到第 n 行第 m 列。只能向右或者向下走。
注意，如果行号和列数都是偶数，不能走入这一格中。
问有多少种方案。
【输入格式】
输入一行包含两个整数 n, m。
【输出格式】
输出一个整数，表示答案。
【评测用例规模与约定】
对于所有评测用例，1≤n≤30,1≤m≤30。*/
#include<iostream>
using namespace std;
int n,m;
long long ans=0;
void dfs(int x,int y)
{
    if(x==n && y==m)
    {
        ans++;
        return;
    }
    if(x>n || y>m) return;
    if(x%2==0 && y%2==0)
        return;
    dfs(x+1,y);
    dfs(x,y+1);
}
int main()
{
    cin>>n>>m;//n行m列
    dfs(1,1);
    cout<<ans;
    return 0;
}