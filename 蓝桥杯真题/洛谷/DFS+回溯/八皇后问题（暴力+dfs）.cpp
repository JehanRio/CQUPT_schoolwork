//https://www.luogu.com.cn/problem/P1219
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int record[14];
int total=0;
int k=0;
bool isvalid(int i,int j)//需要看[0,i-1]行
{
    for(int k=0;k<i;k++)
    {
        if(j==record[k] || abs(j-record[k])==abs(i-k))
            return false;
    }
    return true;
}
int process(int i,int n)//当前在i行
{
    if(i==n)//终止行
    {
        if(total<=2)//前三个答案就是字典序前三的序列
        {
            for(int j=0;j<n;j++)
                cout<<record[j]+1<<" ";
            cout<<endl;
        }
        total++;
        return 1;
    }
    int res=0;
    for(int j=0;j<n;j++)
    {
        if(isvalid(i,j))
        {
            record[i]=j;//第i行在第j列
            res+=process(i+1,n);
        }
    }
    return res;
}
int main()
{
    int n;cin>>n;
    cout<<process(0,n);
    return 0;
}