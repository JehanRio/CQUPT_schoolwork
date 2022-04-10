//https://www.lanqiao.cn/problems/524/learning/?contest_id=55
#include <iostream>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
//first表示次数
//second表示插入的位置
bool compare(pair<int,int>&a1,pair<int,int>&a2)
{
  return a1.first>a2.first;
}
int main()
{
  int m,n,k,l,d;
  cin>>m>>n>>k>>l>>d;
  pair<int,int> row[10005],col[10005];
  for(int i=1;i<=m;i++)row[i].second=i;
  for(int i=1;i<=n;i++)col[i].second=i;
  for(int i=0;i<d;i++)
  {
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2)col[min(y1,y2)].first++;
    else row[min(x1,x2)].first++;
  }
//   sort(row+1,row+1+n,compare);
//   for(int i=1;i<=k;i++)
//     cout<<row[i].second<<" ";
//   cout<<endl;
//   sort(col+1,col+1+n,compare);
//   for(int i=1;i<=l;i++)
//     cout<<col[i].second<<" ";
//   return 0;
//要按顺序输出
 sort(row+1,row+n+1,compare);
    multiset<int>ans;
    for(int i=1; i<=k; i++)
        ans.insert(row[i].second);
    for(auto v:ans) {
        printf("%d ",v);
    }
    printf("\n");
    ans.clear();
    sort(col+1,col+m+1,compare);
    for(int i=1; i<=l; i++)
        ans.insert(col[i].second);
    for(auto v:ans) {
        printf("%d ",v);
    }
    printf("\n");
}