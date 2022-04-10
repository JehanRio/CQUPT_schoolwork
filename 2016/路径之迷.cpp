#include <iostream>
#include<vector>
using namespace std;
int west[21],north[21];
int n;
const int v[4][2] = {0, 1, 0, -1, 1, 0, -1, 0}; 
vector<int>cur;
int vis[21][21];
bool check()//确认是不是每个靶子都满足
{
    for(int i=0;i<n;i++)
    {
        if(west[i]!=0)return false;
        if(north[i]!=0)return false;
    }
    return true;
}
void dfs(int x,int y)
{
    
    if(x==n-1&&y==n-1)
    {
        if(check())
        {
            for(int i=0;i<cur.size();i++)
                cout<<cur[i]<<" ";
        }
        return;
    }
    for(int i=0;i<4;i++)
    {
        int dx=x+v[i][0],dy=y+v[i][1];
        if(dx>=n||dy>=n||dx<0||dy<0||vis[dx][dy]==1)continue;
        if(west[dx]<=0||north[dy]<=0)continue;
        west[dx]--;
        north[dy]--;
        vis[dx][dy]=1;
        cur.push_back(dx*4+dy);
        dfs(dx,dy);
        west[dx]++;
        north[dy]++;
        vis[dx][dy]=0;
        cur.pop_back();
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>north[i];
    for(int i=0;i<n;i++)
        cin>>west[i];
    cur.push_back(0);
    vis[0][0]=1;
    west[0]--;
    north[0]--;
    dfs(0,0);
    return 0;
}