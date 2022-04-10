/*四平方和定理，又称为拉格朗日定理：
每个正整数都可以表示为至多4个正整数的平方和。
如果把0包括进去，就正好可以表示为4个数的平方和。比如：
5 = 0^2 + 0^2 + 1^2 + 2^2
7 = 1^2 + 1^2 + 1^2 + 2^2
（^符号表示乘方的意思）
对于一个给定的正整数，可能存在多种平方和的表示法。
要求你对4个数排序：
0 <= a <= b <= c <= d
并对所有的可能表示法按 a,b,c,d 为联合主键升序排列，最后输出第一个表示法
程序输入为一个正整数N (N<5000000)
要求输出4个非负整数，按从小到大排序，中间用空格分开
例如，输入：
5
则程序应该输出：
0 0 1 2
再例如，输入：
12
则程序应该输出：
0 2 2 2
再例如，输入：
773535
则程序应该输出：
1 1 267 838
*/
#include<iostream>
#include<cmath>
#include<map>
using namespace std;
//a^2 + b^2 <=N/2
//c^2 <=N/2 c^2+d^2<=N
//空间换时间 降低时间复杂度 用哈希表
int main()
{
    int N;
    cin>>N;
    map<int,int>cache;
    for(int c=0;c*c<=N/2;c++)
    {
        for(int d=c;d*d+c*c<=N;d++)
        {
            if(cache.find(c*c+d*d)==cache.end())//c^2+d^2没有
                cache[c*c+d*d]=c;//用较小的数储存
        }
    }
    for(int a=0;a*a<=N/4;a++)
    {
        for(int b=a;a*a+b*b<=N/2;b++)
        {
            if(cache.find(N-a*a-b*b)!=cache.end())//如果找到了
            {
                int c=cache[N-a*a-b*b];
                int d=(sqrt(N-a*a-b*b-c*c));
                cout<<a<<" "<<b<<" "<<c<<" "<<d;
                return 0;
            }
        }
    }
    cout<<"未找到";
    return 0;
}

