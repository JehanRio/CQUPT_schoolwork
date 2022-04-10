/*小明正在整理一批历史文献。这些历史文献中出现了很多日期。小明知道这些日期都在1960年1月1日至2059年12月31日。
令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。
更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。
比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。
给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？
输入
一个日期，格式是"AA/BB/CC"。 (0 <= A, B, C <= 9)
输出
输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。
样例输入
02/03/04
样例输出
2002-03-04
2004-02-03
2004-03-02*/
#include<iostream>
#include<algorithm>
using namespace std;

//知识点：sort重定义排序方式；结构体的创建（也可以用多维数组实现）


typedef struct
{
    int year,month,day;
}date;
//重新定义sort排序方式、判断是不是闰年、打印、check日期是否正确
bool compare(date &d1,date &d2)
{
    if(d1.year!=d2.year)
        return d1.year<d2.year;
    if(d1.month!=d2.month)
        return d1.month<d2.month;
    return d1.day<d2.day;
}
bool isleapyear(int y)
{
    return ((y%4==0&&y%100!=0)||y%400==0);//不能被100整除并且能被400整除 或者 能被4整除
}
void Print(date &d)
{
    printf("%02d-%02d-%02d",d.year,d.month,d.day); //%2d要求输出数据为两位，大于两位则原样输出，小于两位则补空格
    //%02d:默认情况下，数据数据宽度不够2位是用空格填补的，但是因为2d前面有0，表示，数据宽度不足时用0填补，例如%03d输出 12，那么实际输出到屏幕的是012.
    cout<<endl;
}
bool check(const date &d)
{
    int month_day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(isleapyear(d.year)) month_day[1]=29;
    if(d.year<1960 || d.year>2059)return false;
    if(d.month<1 || d.month>12)return false;
    if(d.day<1 || d.day>month_day[d.month])return false;
    return true;
}
int main()
{
    int aa,bb,cc;
    scanf("%d/%d/%d",&aa,&bb,&cc);
    date d[6]={
        {2000+aa,bb,cc},
        {1900+aa,bb,cc},
        {2000+cc,aa,bb},
        {1900+cc,aa,bb},
        {2000+cc,bb,aa},
        {1900+cc,bb,aa}
    };
    sort(d,d+6,compare);
    for(int i=0;i<6;i++)
    {
        if(check(d[i]))
            Print(d[i]);
    }
    return 0;
}