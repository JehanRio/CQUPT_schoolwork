/*小明用字母 A对应数字 1，B对应 2，以此类推，用 Z对应 26。对于 27以上的数字，小明用两位或更长位的字符串来对应，例如 AA对应27，AB对
应28，AZ对应52，LQ对应329。
请问2019对应的字符串是什么？*/
#include<iostream>
#include<stack>
using namespace std;

//知识点：进制转换
int main()
{
    int n=2019;
    stack<char> stk;
    while(n)
    {
        stk.push('A'+n%26-1);//记得减1
        n/=26;
    }
    while(!stk.empty())
    {
        cout<<stk.top();
        stk.pop();
    }
    return 0;
}