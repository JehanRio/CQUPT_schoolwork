//福尔摩斯到某古堡探险，看到门上写着一个奇怪的算式：ABCDE*?=EDCBA。他对华生说：
//“ABCDE应该代表不同的数字，问号也代表某个数字！” 华生：“我猜也是！”，于是，两人沉默了好久，还是没有算出合适的结果来。 
//请你利用计算机的优势，找到破解的答案，把ABCDE所代表的数字写出来。
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int numArray[10]={0,1,2,3,4,5,6,7,8,9};
    while(next_permutation(numArray,numArray+10))//如果存在a之后的排列，就返回true。如果a是最后一个排列没有后继，返回false，每执行一次，a就变成它的后继
    {
        if(numArray[0]!=0 && numArray[4]!=0)
        {
            int left=numArray[4]+numArray[3]*10+numArray[2]*100+numArray[1]*1000+numArray[0]*10000;
            int right=numArray[0]+numArray[1]*10+numArray[2]*100+numArray[3]*1000+numArray[4]*10000;
            for(int i=1;i<=9;i++)
            {
                if(left*i==right)
            {
                cout<<numArray[0]<<numArray[1]<<numArray[2]<<numArray[3]<<numArray[4]<<endl;
                cout<<i;
                return 0;
            }     
            }
            //int tem=numArray[7];
            
        }
    }
    return 0;
}