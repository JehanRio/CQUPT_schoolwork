/*2020年春节期间，有一个特殊的日期引起了大家的注意：2020年2月2日。因为如果将这个日期按“yyyymmdd”的格式写成一个8位数是20200202，恰好是一个回文数。我们称这样的日期是回文日期。有人表示20200202是“千年一遇”的特殊日子。对此小明很不认同，因为不到2年之后就是下一个回文日期：20211202即2021年12月2日。也有人表示20200202并不仅仅是一个回文日期，还是一个ABABBABA型的回文日期。对此小明也不认同，因为大约100年后就能遇到下一个ABABBABA型的回文日期：21211212即2121年12月12日。算不上“千年一遇”，顶多算“千年两遇”。给定一个8位数的日期，请你计算该日期之后下一个回文日期和下一个ABABBABA型的回文日期各是哪一天。
【输入格式】
输入包含一个八位整数N，表示日期。
【输出格式】
输出两行，每行1个八位数。第一行表示下一个回文日期，第二行表示下一个ABABBABA型的回文日期。
【样例输入】
20200202
【样例输出】
20211202
21211212
【评测用例规模与约定】
对于所有评测用例，10000101 <= N <= 89991231，保证N是一个合法日期的8位数表示。*/
#include<iostream>
using namespace std;
//改用int类型 否则加法太困难
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check1(int date)
{
    int year=date/10000,mon=date/100%100,day=date%100;
    if(mon<1||mon>12)return false;
    if(day==0 || (mon!=2&&day>month[mon]))return false;
    if(mon==2)
    {
        int run=(year%4&&year%100!=0)||year%400==0;
        if(day>month[mon]+run)return false;
    }
    return true;
}
bool check(int date)
{
    int year=date/10000,mon=(date/100)%100,day=date%100;
    if(mon<1 || mon>12)return false;
    if(day==0 || (mon!=2 && day>month[mon]))return false;
    if(mon==2)
    {
        int leap= year%4==0&&year%100!=0 || year%400==0;
        if(month[mon]+leap<day)return false;
    }
    return true;
}
int main()
{
    int n;cin>>n;
    int year=n/10000;
    for(int i=year;;i++)
    {
        int tem=i;
        int date1=i;
        for(int j=1;j<=4;j++)
        {
            date1=date1*10+tem%10;
            tem/=10;
        }
        if(date1>n && check1(date1))
        {
            cout<<date1<<endl;
            break;
        }
    }
    int ab=n/1000000;//前2个数字
    for(int i=ab;;i++)
    {
        int a=i/10;
        int b=i%10;
        int ba=b*10+a;
        int date2=i*1000000+i*10000+ba*100+ba;
        if(date2>n && check1(date2))
        {
            cout<<date2;
            break;
        }
    }
    return 0;
}