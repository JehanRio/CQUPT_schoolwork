/*对于一个字符串 S，我们定义 S 的分值 f (S ) 为 S 中出现的不同的字符个
数。例如 f (”aba”) = 2， f (”abc”) = 3, f (”aaa”) = 1。
现在给定一个字符串 S [0::n ?6?1 1]（长度为 n），请你计算对于所有 S 的非空
子串 S [i:: j](0 ≤ i ≤ j < n)， f (S [i:: j]) 的和是多少。
【输入格式】
输入一行包含一个由小写字母组成的字符串S。
【输出格式】
输出一个整数表示答案。
【样例输入】
ababc
【样例输出】
28
【样例说明】
子串 f值
a 1
ab 2
aba 2
abab 2
ababc 3
b 1
ba 2
bab 2
babc 3
a 1
ab 2
abc 3
b 1
bc 2
c 1*/
#include<iostream>
#include<set>
#include<string>
using namespace std;
string s;
int ans=0;
void check(int i,int j)
{
    int m=0;
    set<char> st;
    for(int a=i;a<=j;a++)
    {
        if(st.find(s[a])==st.end())//字典中没有该字母
        {
            m++;
            st.insert(s[a]);
        }
    }
    ans+=m;
}
int main()
{
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            check(i,j);
        }
    }
    cout<<ans;
}