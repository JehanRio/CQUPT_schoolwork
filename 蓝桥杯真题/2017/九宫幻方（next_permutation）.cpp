#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a(10);
vector<int> b(10);
vector<int> ans(10);
bool check()
{
    if((a[1]+a[3]+a[2]==15)&&(a[4]+a[5]+a[6]==15)&&(a[9]+a[7]+a[8]==15)&&(a[9]+a[3]+a[6]==15)&&
    (a[1]+a[4]+a[7]==15)&&(a[2]+a[5]+a[8]==15)&&(a[1]+a[5]+a[9]==15)&&(a[3]+a[5]+a[7]==15))
    return true;
    return false;
}
int cur=0;
void dfs()
{
    if(check())
    {
    	int i;
        for(i=1;i<=9;i++)
        {
        	if(b[i]!=0&&b[i]!=a[i])
        		break;
        }
        if(i==10)
        {
        	ans=a;
        	cur++;
        }
    }
}
int main()
{
	for(int i=1;i<=9;i++)
		a[i]=i;
	for(int i=1;i<=9;i++)
		cin>>b[i];
	do
	{
		dfs();
		if(cur==2)
		{
			cout<<"Too Many";
			return 0;
		}
	}while(next_permutation(a.begin()+1,a.begin()+10));
	for(int i=1;i<=9;i++)
	{
		cout<<ans[i];
		if(i%3==0)cout<<endl;
		else cout<<" ";
	}
	return 0;
}