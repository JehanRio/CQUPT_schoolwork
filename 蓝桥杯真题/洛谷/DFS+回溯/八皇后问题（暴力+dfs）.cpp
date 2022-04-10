//https://www.luogu.com.cn/problem/P1219
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int record[14];
int total=0;
int k=0;
bool isvalid(int i,int j)//��Ҫ��[0,i-1]��
{
    for(int k=0;k<i;k++)
    {
        if(j==record[k] || abs(j-record[k])==abs(i-k))
            return false;
    }
    return true;
}
int process(int i,int n)//��ǰ��i��
{
    if(i==n)//��ֹ��
    {
        if(total<=2)//ǰ�����𰸾����ֵ���ǰ��������
        {
            for(int j=0;j<n;j++)
                cout<<record[j]+1<<" ";
            cout<<endl;
        }
        total++;
        return 1;
    }
    int res=0;
    for(int j=0;j<n;j++)
    {
        if(isvalid(i,j))
        {
            record[i]=j;//��i���ڵ�j��
            res+=process(i+1,n);
        }
    }
    return res;
}
int main()
{
    int n;cin>>n;
    cout<<process(0,n);
    return 0;
}