//https://www.luogu.com.cn/problem/P2196
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;
int num[25];//�ؽѵĵ�����
int map[25][25];
vector<int>ans;//������¼�������Ĳ�����
vector<int>anss;
int answer=0;
int k=0;
bool check(int x)
{
    for(int i=1;i<=n;i++)
        if(map[x][i])return true;
    return false;
}
void dfs(int step,int sm)//��ǰ�����͵�ǰ�ܼ�ֵ
{
    if(!check(step))
    {
        if(sm>answer)
        {
            answer=sm;//ʯͷ�ܸ���
            anss=ans;//���մ𰸵�����
        }
        return;
    }
    for(int i=1;i<=n;i++)//������һ���ÿһ�����
    {
        if(map[step][i])//�����2����ͨ
        {
            ans.push_back(i);
            dfs(i,sm+num[i]);
            ans.pop_back();//����
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
        ans.push_back(i);//�ӵ�ǰ�㿪ʼ
        dfs(i,num[i]);
        ans.clear();//������� ���¿�ʼ
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
