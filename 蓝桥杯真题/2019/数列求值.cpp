/*给定数列1,1,1,3,5,9,17,…，从第4项开始，每项都是前3项的和。求第20190324项的最后4位数字。*/
#include<iostream>
using namespace std;

//知识点：用数组保存三项值，通过对3取余依次将数字加上去。应为保留最后四位数字，所以每次计算过后需要用10000取余，不然会溢出
int main()
{
    int n1=1,n2=1,n3=1;
    int ans;
    for(int i=4;i<=20190324;i++)
    {
        ans=n1+n2+n3;
        ans%=10000;
        n1=n2;
        n2=n3;
        n3=ans;
    }
    cout<<ans;
    return 0;
}