/*数学老师给小明出了一道等差数列求和的题目。但是粗心的小明忘记了一
部分的数列，只记得其中 N 个整数。
现在给出这 N 个整数，小明想知道包含这 N 个整数的最短的等差数列有
几项？
【输入格式】
输入的第一行包含一个整数 N。
第二行包含 N 个整数 A 1 ,A 2 ,··· ,A N 。(注意 A 1 ?6?5 A N 并不一定是按等差数
列中的顺序给出)
【输出格式】
输出一个整数表示答案。
【样例输入】
5
2 6 4 10 20
【样例输出】
10
【样例说明】
包含 2、6、4、10、20 的最短的等差数列是 2、4、6、8、10、12、14、16、
18、20。*/
#include<iostream>
#include<algorithm>
using namespace std;

//知识点：等差数列 两项之差除以公差余数为0
int num[100000];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    sort(num+1,num+n+1);
    if(num[n]-num[1]==n-1)
    {
        cout<<n;
        return 0;
    }
    int k=num[2]-num[1];
    for(;k>=0;k--)//差值减一
    {
        int tag=1;
        for(int j=3;j<=n;j++)//从第三项开始
        {
            if((num[j]-num[1])%k!=0)//k不是公差
            {
                tag=0;break;
            }
        }
        if(tag==1)//如果每一项都满足,那么k是公差
            break;
    }
    cout<<(num[n]-num[1])/2+1;
    return 0;
}