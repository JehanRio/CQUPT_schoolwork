//https://www.luogu.com.cn/problem/P2196
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;
int num[25];//地窖的地雷数
int map[25][25];
vector<int>ans;//用来记录经历过的层数答案
vector<int>anss;
int answer=0;
int k=0;
bool check(int x)
{
    for(int i=1;i<=n;i++)
        if(map[x][i])return true;
    return false;
}
void dfs(int step,int sm)//当前层数和当前总价值
{
    if(!check(step))
    {
        if(sm>answer)
        {
            answer=sm;//石头总个数
            anss=ans;//最终答案的数组
        }
        return;
    }
    for(int i=1;i<=n;i++)//遍历这一层的每一个入口
    {
        if(map[step][i])//如果这2层连通
        {
            ans.push_back(i);
            dfs(i,sm+num[i]);
            ans.pop_back();//回溯
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
            cin>>map[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        ans.push_back(i);//从当前层开始
        dfs(i,num[i]);
        ans.clear();//清空数组 重新开始
    }
    
    for(int i=0;i<anss.size();i++)
        cout<<anss[i]<<" ";
    cout<<endl;
    cout<<answer;
    return 0;
}

// 2
// 20

// 3
// 10 20 5
// 0 1
// 0
