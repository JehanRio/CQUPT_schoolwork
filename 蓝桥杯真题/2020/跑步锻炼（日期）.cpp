/*小蓝每天都锻炼身体。正常情况下，小蓝每天跑1千米。如果某天是周一或者月初（1日），为了激励自己，小蓝要跑2千米。
如果同时是周一或月初，小蓝也是跑2千米。小蓝跑步已经坚持了很长时间，从2000年1月1日周六（含）到2020年10月1日周四（含）。请问这段时间小蓝总共跑步多少千米？*/
#include<iostream>
using namespace std;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool run(int a)
{
    if((a%4==0 && a%100!=0) || a%400==0)
    return true;
    else return false;
}
int main()
{
    int day1=6;
    int ans=0;
    int mon;
    for(int year=2000;year<=2020;year++)
    {
        if(run(year))month[2]=29;
        else month[2]=28;
        if(year==2020)mon=9;
        else mon=12;
        for(int m=1;m<=mon;m++)
        {
            for(int day=1;day<=month[m];day++)
            {
                if(day==1 || day1==1)
                    ans++;
                ans++;
                day1++;
                day1%=7;
            }
        }
    }
    ans+=2;
    cout<<ans;
    return 0;
}