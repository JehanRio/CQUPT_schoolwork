/*2020�괺���ڼ䣬��һ����������������˴�ҵ�ע�⣺2020��2��2�ա���Ϊ�����������ڰ���yyyymmdd���ĸ�ʽд��һ��8λ����20200202��ǡ����һ�������������ǳ������������ǻ������ڡ����˱�ʾ20200202�ǡ�ǧ��һ�������������ӡ��Դ�С���ܲ���ͬ����Ϊ����2��֮�������һ���������ڣ�20211202��2021��12��2�ա�Ҳ���˱�ʾ20200202����������һ���������ڣ�����һ��ABABBABA�͵Ļ������ڡ��Դ�С��Ҳ����ͬ����Ϊ��Լ100������������һ��ABABBABA�͵Ļ������ڣ�21211212��2121��12��12�ա��㲻�ϡ�ǧ��һ�����������㡰ǧ��������������һ��8λ�������ڣ�������������֮����һ���������ں���һ��ABABBABA�͵Ļ������ڸ�����һ�졣
�������ʽ��
�������һ����λ����N����ʾ���ڡ�
�������ʽ��
������У�ÿ��1����λ������һ�б�ʾ��һ���������ڣ��ڶ��б�ʾ��һ��ABABBABA�͵Ļ������ڡ�
���������롿
20200202
�����������
20211202
21211212
������������ģ��Լ����
������������������10000101 <= N <= 89991231����֤N��һ���Ϸ����ڵ�8λ����ʾ��*/
#include<iostream>
using namespace std;
//����int���� ����ӷ�̫����
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
    int ab=n/1000000;//ǰ2������
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