#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int a[20];//0ΪO��1ΪX
bool vis[1<<16];
int ans[1<<16][20];
void print()
{
    for(int i=1;i<=1<<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<(ans[i][j]?'X':'O');
        }
        cout<<endl;
    }
}
int calc()//�����Ʊ�Ϊ10���ƣ������λ��ʼ
{
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=ans*2+a[i];
    return ans;
}
void dfs(int pos)
{
    if(pos==1<<n)
    {
        print();
        exit(0);
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=!a[i];//1λ���
        if(vis[calc()])//���ʹ���
        {//����
            a[i]=!a[i];
            continue;
        }
        vis[calc()]=1;
        for(int j=1;j<=n;j++)
            ans[pos][j]=a[j];//��¼��
            dfs(pos+1);
            //����
            vis[calc()]=0;
            a[i]=!a[i];
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cout<<'O';
    cout<<endl;
    vis[0]=true;//000 000��������
    dfs(1);
    return 0;

}