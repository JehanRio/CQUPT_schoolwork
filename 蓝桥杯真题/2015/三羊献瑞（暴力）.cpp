/*观察下面的加法算式：

    祥 瑞 生 辉
  + 1  羊 献 瑞
-------------------
 1  羊 生 瑞 气
(如果有对齐问题，可以参看【图1.jpg】)其中，相同的汉字代表相同的数字，不同的汉字代表不同的数字。请你填写“三羊献瑞”所代表的4位数字（答案唯一），不要填写任何多余内容。
*/
//祥 瑞 生 辉 羊 献 气
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int num[9]={0,2,3,4,5,6,7,8,9};
    do
    {
        if(num[0]!=0)
        {
            if((num[0]*1000 + num[1]*100 + num[2]*10 + num[3]) + (1000 + num[4]*100 + num[5]*10 + num[1]) == 10000 + num[4]*1000 + num[2]*100 +num[1]*10 + num[6])
            {
                cout<<"1"<<num[4]<<num[2]<<num[1];
                break;
            }     
        }
    }while(next_permutation(num,num+9));
    return 0;
}