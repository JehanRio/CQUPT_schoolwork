/*
X ������һ���ع����⡣�� n x m �����ӵľ���ÿ�����ӷ�һ��������ÿ���������ż�ֵ��ǩ��

�ع�����������Ͻǣ����������½ǡ�

С���������ع�����ڣ�����Ҫ����ֻ�����һ��������ߡ�

�߹�ĳ������ʱ������Ǹ������еı�����ֵ��С���������ⱦ����ֵ����С���Ϳ�������������Ȼ��Ҳ���Բ��ã���

��С���ߵ�����ʱ����������еı���ǡ����k��������Щ�����Ϳ����͸�С����

�����С����һ�㣬�ڸ����ľ����£����ж����ֲ�ͬ���ж������ܻ����k��������
����
����һ��3���������ÿո�ֿ���n m k (1< =n,m< =50, 1< =k< =12)

�������� n �����ݣ�ÿ���� m ������ Ci (0< =Ci< =12)������������ϵı���ļ�ֵ
���
Ҫ�����һ����������ʾ����ȡk���������ж��������������ֿ��ܴܺ�������� 1000000007 ȡģ�Ľ����
��������
2 3 2
1 2 3
2 1 5
�������
14
*/
#include<iostream>
#include<cstring>
using namespace std;
#define mod 1000000007
//https://blog.csdn.net/weixin_41232804/article/details/90266341?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164484367016780261967484%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164484367016780261967484&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-1-90266341.pc_search_result_cache&utm_term=%E5%9C%B0%E5%AE%AB%E5%8F%96%E5%AE%9D&spm=1018.2226.3001.4187
int dp[50][50][13][13];////����dp[3][4][5][6]�����ڣ�3��4�������ʱ����ӵ��5������,����ֵΪ6 
int mp[50][50];//������ı�����ֵ��С
int m,n,k;

int dfs(int x,int y,int sum,int max)
{
    if(dp[x][y][sum][max]!=-1)//����¼
        return dp[x][y][sum][max];
    if(x==n && y==m)//�����յ�
    {
        if(sum==k || (sum==k-1 && mp[x][y]>max))//������еı����Ѿ���k����ѡ�����յ�ı��� ���� ���еı�����k-1�� 
            return dp[x][y][sum][max+1]=1;//����ʱ�յ�ı����ֵ����max,�������յ�ı���(���յ㱦������벻��)
        else return dp[x][y][sum][max+1]=0;//�����Ͼͱ�ʾ�÷���������,����0 
    }
    long long cnt=0;
    if(x+1<=n)//�������������
    {
        if(mp[x][y]>max)
            cnt=(cnt+dfs(x+1,y,sum+1,mp[x][y]))%mod;
        cnt=(cnt+dfs(x+1,y,sum,max))%mod;
    }
    if(y+1<=m)
    {
        if(max<mp[x][y])
            cnt=(cnt+dfs(x,y+1,sum+1,mp[x][y]))%mod;
        cnt=(cnt+dfs(x,y+1,sum,max))%mod;
    }
    dp[x][y][sum][max+1]=cnt;
    return cnt;
}
int main()
{
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));//ȫ����ʼ��Ϊ-1
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mp[i][j];
    dfs(1,1,0,-1);
    cout<<dp[1][1][0][0];
    return 0;
}