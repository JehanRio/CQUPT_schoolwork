/*С����������һ����ʷ���ס���Щ��ʷ�����г����˺ܶ����ڡ�С��֪����Щ���ڶ���1960��1��1����2059��12��31�ա�
��С��ͷ�۵��ǣ���Щ���ڲ��õĸ�ʽ�ǳ���ͳһ���в�����/��/�յģ��в�����/��/��ģ����в�����/��/��ġ�
�����鷳���ǣ����Ҳ��ʡ����ǰ��λ��ʹ�������ϵ�һ�����ڣ����ںܶ���ܵ����������Ӧ��
����02/03/04��������2002��03��04�ա�2004��02��03�ջ�2004��03��02�ա�
����һ�������ϵ����ڣ����ܰ���С���ж�����Щ���ܵ����ڶ����Ӧ��
����
һ�����ڣ���ʽ��"AA/BB/CC"�� (0 <= A, B, C <= 9)
���
������ɸ�����ͬ�����ڣ�ÿ������һ�У���ʽ��"yyyy-MM-dd"��������ڰ����絽�����С�
��������
02/03/04
�������
2002-03-04
2004-02-03
2004-03-02*/
#include<iostream>
#include<algorithm>
using namespace std;

//֪ʶ�㣺sort�ض�������ʽ���ṹ��Ĵ�����Ҳ�����ö�ά����ʵ�֣�


typedef struct
{
    int year,month,day;
}date;
//���¶���sort����ʽ���ж��ǲ������ꡢ��ӡ��check�����Ƿ���ȷ
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
    return ((y%4==0&&y%100!=0)||y%400==0);//���ܱ�100���������ܱ�400���� ���� �ܱ�4����
}
void Print(date &d)
{
    printf("%02d-%02d-%02d",d.year,d.month,d.day); //%2dҪ���������Ϊ��λ��������λ��ԭ�������С����λ�򲹿ո�
    //%02d:Ĭ������£��������ݿ�Ȳ���2λ���ÿո���ģ�������Ϊ2dǰ����0����ʾ�����ݿ�Ȳ���ʱ��0�������%03d��� 12����ôʵ���������Ļ����012.
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