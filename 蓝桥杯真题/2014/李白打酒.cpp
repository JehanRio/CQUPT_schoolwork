/*��˵��ʫ����ף�һ���������Һ����Ӳ�������
һ�죬�����žƺ����Ӽ���������ƺ����о�2���������߱߳���
���½����ߣ����ȥ��ơ�
����һ����������һ����
��һ·�ϣ���һ��������5�Σ�������10�Σ���֪���һ���������ǻ��������ðѾƺȹ��ˡ�

����������������ͻ��Ĵ��򣬿��԰������Ϊa��������Ϊb����babaabbabbabbbb ���Ǻ���Ĵ����������Ĵ�һ���ж����أ������������п��ܷ����ĸ�����������Ŀ�����ģ���
*/
#include<iostream>
#include<algorithm>
using namespace std;
//ȫ����
void test1()
{
    int num[15]={0,0,0,0,0,1,1,1,1,1,1,1,1,1,1};
    int ans=0;
    do{
    int wine=2;
    for(int i=0;i<15;i++)
    {
        if(num[i]==0)wine*=2;
        else wine--;
    }
    if(wine==0) ans++;
    }while(next_permutation(num,num+14));
    cout<<ans;
}
//����
int sum=0;
int ans=0;
int test2(int wine,int flower,int store)
{
    if(wine ==1 && flower==1 && store==0)//��ʣ��һ�һ���
        sum++;
    if(store>0) test2(wine*2,flower,store-1);//ǰ������
    if(flower>0) test2(wine-1,flower-1,store);//ǰ������
    return sum;
}
void dfs(int wine,int flower,int store)
{
    if(store<0 || flower<0)return;
    if(wine==1 && store==0 && flower==1)
    {
        ans++;return;
    }
    dfs(wine-1,flower-1,store);
    dfs(wine*2,flower,store-1);
}
int main()
{
    test1();
    test2(2,10,5);
    dfs(2,10,5);
    cout<<sum<<endl;
    cout<<ans;
    return 0;
}