#include<iostream>
#include<set>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
set<pair<double,double>> ans;
#define   INF   999999999
long long map[2022][2022];
long long gcd(long long x,long long y)
{
    if(x==0)return y;
    return gcd(y%x,x);
}
int main()
{
    int i=1;
    long long ans=0;
    for(int i=1;i<=2021;i++)
    {
        for(int j=1;j<=2021;j++)
        {
            if(i==j)map[i][j]=0;
            else if(abs(i-j)>21)map[i][j]=map[j][i]=INF;//i与j之间的距离
            else map[i][j]=map[j][i]=i*j/gcd(i,j);//最小公倍数
        }
    }
    for(int k=1;k<=2021;k++)//第一个循环是中间变量
    for(int i=1;i<=2021;i++)
    for(int j=1;j<=2021;j++)
    {
        if(map[i][k]!=INF&&map[k][j]!=INF&&map[i][j]>map[i][k]+map[k][j])map[i][j]=map[i][k]+map[k][j];
    }
    cout<<map[1][2021];
}