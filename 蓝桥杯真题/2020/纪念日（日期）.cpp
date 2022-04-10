/*2020 年 7 月 1 日是中国 共 产 党 成立 99 周年纪念日。
中国 共 产 党 成立于 1921 年 7 月 23 日。
请问从 1921 年 7 月 23 日中午 12 时到 2020 年 7 月 1 日中午 12 时一共包含多少分钟？
题目分析
先计算1922年到2020 年一共多少天，然后减去多余的天数
*/
#include<iostream>
using namespace std;
int year(int a)
{
    if((a%4==0 && a%100!=0) || a%400==0)
        return 366;
    return 365;
}
int main()
{
    int sum=0;
    for(int i=1922;i<=2020;i++)
    {
        sum+=year(i);
    }
    sum-=22;
    cout<<sum*24*60<<endl;
    cout<<"52038720";
    return 0;
}