/*话说大诗人李白，一生好饮。幸好他从不开车。
一天，他提着酒壶，从家里出来，酒壶中有酒2斗。他边走边唱：
无事街上走，提壶去打酒。
逢店加一倍，遇花喝一斗。
这一路上，他一共遇到店5次，遇到花10次，已知最后一次遇到的是花，他正好把酒喝光了。

请你计算李白遇到店和花的次序，可以把遇店记为a，遇花记为b。则：babaabbabbabbbb 就是合理的次序。像这样的答案一共有多少呢？请你计算出所有可能方案的个数（包含题目给出的）。
*/
#include<iostream>
#include<algorithm>
using namespace std;
//全排列
void test1()
{
    int num[15]={0,0,0,0,0,1,1,1,1,1,1,1,1,1,1};
    int ans=0;
    do{
    int wine=2;
    for(int i=0;i<15;i++)
    {
        if(num[i]==0)wine*=2;
        else wine--;
    }
    if(wine==0) ans++;
    }while(next_permutation(num,num+14));
    cout<<ans;
}
//回溯
int sum=0;
int ans=0;
int test2(int wine,int flower,int store)
{
    if(wine ==1 && flower==1 && store==0)//还剩下一家花店
        sum++;
    if(store>0) test2(wine*2,flower,store-1);//前往店铺
    if(flower>0) test2(wine-1,flower-1,store);//前往花店
    return sum;
}
void dfs(int wine,int flower,int store)
{
    if(store<0 || flower<0)return;
    if(wine==1 && store==0 && flower==1)
    {
        ans++;return;
    }
    dfs(wine-1,flower-1,store);
    dfs(wine*2,flower,store-1);
}
int main()
{
    test1();
    test2(2,10,5);
    dfs(2,10,5);
    cout<<sum<<endl;
    cout<<ans;
    return 0;
}