/*X星球居民小区的楼房全是一样的，并且按矩阵样式排列。其楼房的编号为1,2,3…
当排满一行时，从下一行相邻的楼往反方向排号。
比如：当小区排号宽度为6时，开始情形如下：
1 2 3 4 5 6
12 11 10 9 8 7
13 14 15 …
我们的问题是：已知了两个楼号m和n，需要求出它们之间的最短移动距离（不能斜线方向移动）

输入为3个整数w m n，空格分开，都在1到10000范围内
w为排号宽度，m,n为待计算的楼号。
要求输出一个整数，表示m n 两楼间最短移动距离。

例如：
用户输入：
6 8 2
则，程序应该输出：
4

再例如：
用户输入：
4 7 20
则，程序应该输出：
5
*/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int w,m,n;
int ans=0;
int rm=0,cm=0,rn=0,cn=0;//用于记录m和n的下标分别是多少
int main()
{
    cin>>w>>m>>n;
    int maxone=max(m,n);
    vector<vector<int>> num(maxone/w+1,vector<int>(w));
    int r=num.size(),c=num[0].size();//行和列
    int tag=0;
    int a=1;
    for(int i=0;i<r;i++)//先将矩阵数字附上去
    {
        if(tag%2==0)//如果为偶数，执行从左到右排列
        {
            for(int j=0;j<c;j++)
            {
                num[i][j]=a;
                if(a==m){rm=i;cm=j;}
                if(a==n){rn=i;cn=j;}
                a++;
            }
            tag++;
        }
        else
        {
            for(int j=c-1;j>=0;j--)
            {
                num[i][j]=a;
                if(a==m){rm=i;cm=j;}
                if(a==n){rn=i;cn=j;}
                a++;
            }
            tag++;
        }
    }
    ans=abs(rm-rn)+abs(cm-cn);
    cout<<ans;
    
    
    return 0;
}