//啤酒每罐2.3元，饮料每罐1.9元。小明买了若干啤酒和饮料，一共花了82.3元。我们还知道他买的啤酒比饮料的数量少，请你计算他买了几罐啤酒。
#include<iostream>
#include<cmath>
using namespace std;
int main() 
{
    int x=1,y;
    for(;x<82.3/2.3;x++)
    {
        for(y=x+1;y<82.3/1.9;y++)
        {
            if(fabs(x*2.3 + y*1.9-82.3)<1e-5)   cout<<x;//整型乘以小数（浮点数） 变为浮点数，浮点数比较大小 需要用fabs <= 1e-5
        }
    }
    return 0;
}