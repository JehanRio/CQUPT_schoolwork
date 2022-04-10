//https://www.luogu.com.cn/problem/P1030
#include<iostream>
#include<map>
#include<string>
using namespace std;
void dfs(string in,string after)
{
    if(in.size()>0)
    {
        char ch=after[after.size()-1];
        int k=in.find(ch);
        cout<<ch;
        dfs(in.substr(0,k),after.substr(0,k));
        dfs(in.substr(k+1),after.substr(k,after.size()-k-1));
    }
    
}
int main()
{
    string inord,aftord;
    cin>>inord>>aftord;
    dfs(inord,aftord);
    return 0;
}