/*ĳ����ĳ�꿪ʼÿ�궼�ٰ�һ������party������ÿ�ζ�Ҫ��Ϩ��������ͬ����������
��������������һ����Ϩ��236������
���ʣ����Ӷ����꿪ʼ������party�ģ�
����д����ʼ������party����������
ע�⣺���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�*/
#include<iostream>
using namespace std;
int main()
{
    int age=0;
    while(1)
    {
        age++;
        int num=0;
        int firstage=age;
        int cur=age;
        while(num<236)
        {
            num+=cur;
            cur++;
        }
        if(num==236)
        {
            cout<<firstage;
            return 0;
        }
    }
}