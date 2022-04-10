/*足球比赛具有一定程度的偶然性，弱队也有战胜强队的可能。假设有甲、乙、丙、丁四个球队，根据他们过去比赛的成绩，得出每个队与另一个队对阵时取胜的概率表：
甲 乙 丙 丁
甲 - 0.1 0.3 0.5
乙 0.9 - 0.7 0.4
丙 0.7 0.3 - 0.2
丁 0.5 0.6 0.8 -
数据含义：甲对乙的取胜概率为0.1，丙对乙的胜率为0.3，…。现在要举行一次锦标赛，双方抽签，分两个组比，获胜的两个队再争夺冠军（参见下图）。
*/
#include<iostream>
#include<cstdlib>
//#include<stdlib.h> 与上面的都有rand
using namespace std;
//对于题干需要的十万次模拟，需要rand()产生十万个从0到2的随机数，0，1，2分别对应那三种情况甲胜的概率，把概率加起来除以100000可以得出最终答案。
//rand()：返回一个从0到最大随机数的任意整数，最大随机数的大小通常是固定的一个大整数。
//如果要产生1~100，则是这样：int num = rand() % 100 + 1;
int main()
{
    double cas[3]={0};
    double sum=0;
    cas[0]=0.1*0.2*0.3+0.1*0.8*0.5;
    cas[1]=0.3*0.4*0.1+0.3*0.6*0.5;
    cas[2]=0.5*0.3*0.3+0.5*0.7*0.1;
    for(int i=1;i<=10000;i++)
    {
        int t=rand()%3;
        if(t==0)sum+=cas[0];
        else if(t==1)sum+=cas[1];
        else sum+=cas[2];
    }
    cout<<sum/10000;
    return 0;
}