/*С��ÿ�춼�������塣��������£�С��ÿ����1ǧ�ס����ĳ������һ�����³���1�գ���Ϊ�˼����Լ���С��Ҫ��2ǧ�ס�
���ͬʱ����һ���³���С��Ҳ����2ǧ�ס�С���ܲ��Ѿ�����˺ܳ�ʱ�䣬��2000��1��1��������������2020��10��1�����ģ��������������ʱ��С���ܹ��ܲ�����ǧ�ף�*/
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