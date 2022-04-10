#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int n,a[16005],f[16005];
vector<vector<int>>map(16005,vector<int>(0));//����Ҳ���Ա�ʾһ����ά����
void dfs(int child,int dad)
{
    f[child]=a[child];//��ʼ��
    for(int i=0;i<map[child].size();i++)
    {
        int tem=map[child][i];
        if(tem!=dad)
        {
            dfs(tem,child);//�ҵ�����֦Ҷ���ܺ�
            if(f[tem]>0)
                f[child]+=f[tem];
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];//����Ȩֵ
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
       map[u].push_back(v);
       map[v].push_back(u);
    }
    dfs(1,0);//�����һ�����ĸ�����0
    int ans=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}