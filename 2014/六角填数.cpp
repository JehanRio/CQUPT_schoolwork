/*所示六角形中，填入1~12的数字。
使得每条直线上的数字之和都相同。
图中，已经替你填好了3个数字，请你计算星号位置所代表的数字是多少？*/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
//每条线26
int num[9]={2,4,5,6,7,9,10,11,12};
bool check()
{
    bool check1=(1+num[0]+num[3]+num[5]==26);
    bool check2=(1+num[1]+num[4]+num[8]==26);
    bool check3=(8+num[0]+num[1]+num[2]==26);
    bool check4=(8+num[3]+num[6]+3==26);
    bool check5=(3+num[2]+num[4]+num[7]==26);
    bool check6=(num[5]+num[6]+num[7]+num[8]==26);
    return check1 && check2 && check3 && check4 && check5 && check6;
}
int main() 
{
    do
    {
        if(check())
        {
            cout<<num[3]<<endl;
            return 0;
        }
    }while(next_permutation(num,num+9));
}