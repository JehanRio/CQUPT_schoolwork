/*100���Ա�ʾΪ����������ʽ��100=3+69258/714�������Ա�ʾΪ��100=82+3546/197��ע��������
�������У�����1~9�ֱ������ֻ����һ�Σ�������0�������������Ĵ�������100��11�ֱ�ʾ����
��ĿҪ�󣺴ӱ�׼�������һ��������N��N<1000*1000���������������������1~9���ظ�����©����ɴ�������ʾ��ȫ��������ע�⣺��Ҫ�����ÿ����ʾ��ֻͳ���ж��ٱ�ʾ����
���磬�û����룺100
���������11
�����磬�û����룺105
���������6
*/
#include<iostream>
#include<algorithm>
using namespace std;
int num[9]={1,2,3,4,5,6,7,8,9};
int change(int a,int b)
{
    int sum=0;
    for(int i=a;i<=b;i++)
    sum=sum*10+num[i];
    return sum;
}
int main()
{
    int ans=0;
    int n;cin>>n;//��������
    long long a,b,c;
    do
    {
        for(int i=0;i<7;i++)
        {
            for(int j=i+1;j<8;j++)
            {
                a=change(0,i);
                b=change(i+1,j);
                c=change(j+1,8);
                if(c*n==a*c+b)
                    ans++;
            }
        }
    }while(next_permutation(num,num+9));
    cout<<ans;
    return 0;
}
