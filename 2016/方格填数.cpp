/*如下的10个格子
（如果显示有问题，也可以参看【图1.jpg】）
填入0~9的数字。要求：连续的两个数字不能相邻。
（左右、上下、对角都算相邻）
一共有多少种可能的填数方案？
请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。*/
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int vis[9];
int martix[5][6];//将其补成5行6列,从2行3列开始 到 4行4列
////当前格子的正左、左上、正上、右上
int mx[4]={0,-1,-1,-1};
int my[4]={-1,-1,0,1};
int ans=0;
//检查9宫格 
bool check(int i,int j)
{
    for(int m=0;m<4;m++)
    {
        
        if(abs(martix[i+mx[m]][j+my[m]]-martix[i][j])==1)//如果相邻
            return false;
    }
    return true;
}

void dfs(int x,int y)
{
    if(x==3 && y==4)//出口
    {
        ans++;
        return;
    }
    for(int i=0;i<10;i++)
    {
        if(vis[i]==0)//一开始没有使用过
        {
            martix[x][y]=i;
            if(!check(x,y))//如果不满足条件
            {
                martix[x][y]=-10;//撤回 依旧初始化为-10
                continue;
            }
            vis[i]=1;//标记已经访问过
            if(y==4)
                dfs(x+1,1);//换行
            else dfs(x,y+1);
            vis[i]=0;          //回溯
            martix[x][y]=-10;
        }
    }
}

void init(){       //将5x6的格子先用-10填满 
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			martix[i][j]=-10;
		}
	}
}
int main()
{
    memset(martix,-10,sizeof(martix));//全部初始化为-10
    memset(vis,0,sizeof(vis));
    dfs(1,2);
    cout<<ans;
    return 0;
}