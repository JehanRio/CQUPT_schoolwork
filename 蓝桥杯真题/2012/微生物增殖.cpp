//假设有两种微生物X和Y，X出生后每隔3分钟分裂一次（数目加倍），Y出生后每隔2分钟分裂一次（数目加倍）。
//一个新出生的X，半分钟之后吃掉1个Y，且从此开始每隔1分钟吃掉1个Y。已知新出生的X=10，Y=89，求60分钟后Y的数目。若X=10，Y=90呢？

#include <iostream>
using namespace std;

int main()
{
    long long x=10,y=89;
    for(int i=1;i<=120;i++)
    {
        if(i%2==1)y=y-x;
        if(i%6==0)x=x*2;
        if(i%4==0)y=y*2;
    }
    cout<<"x="<<x<<endl;
    cout<<"Y的个数为："<<y;
    return 0;
}