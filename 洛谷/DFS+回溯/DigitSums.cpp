//https://www.luogu.com.cn/problem/P1118
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> n1,n2;
int n,sum;
void test1()
{
    cin>>n>>sum;
    for(int i=0;i<n;i++)
    {
        n1.push_back(i+1);
    }
    do
    {
        n2=n1;
        int i=n-1;
        while(i)
        {
            int k=i;
            int j=0;
            while(k--)
            {
                n2[j]=n2[j]+n2[j+1];
                if(n2[j]>sum)break;
                j++;
            }
            i--;
        }
        if(n2[0]==sum)
        {
            for(int i=0;i<n1.size();i++)
            {
                cout<<n1[i]<<" ";
            }
            break;
        }
    }while(next_permutation(n1.begin(),n1.end()));//ÈÝÆ÷ÒªÓÃµü´úÆ÷
}
int main()
{
    test1();
    return 0;
}