#include <iostream>
using namespace std;
#include <algorithm> 
int main()
{
	int x,y;
	cin>>x>>y;
	long long sum = 0;
	
	if((y<x)&&(-y<=x))
	{
		sum+=x>1?(long long)(4*(2+(abs(x)-1)*(abs(x)-2))):0;//求前n个正方形周长的等差数列和	
		sum+=(long long)x>0?(4*x+(x-y)):(y-x);	
	}
	else
	{
		sum+=y>1?(long long)(4*(2+(abs(y)-1)*(abs(y)-2))):0;//求前n个正方形周长的等差数列和
		sum+=(long long)y>0?(2*y+y+x):(6*y-y-x);
	} 
	
	cout<<sum<<endl;
	return 0;
}
