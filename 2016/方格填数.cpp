/*���µ�10������
�������ʾ�����⣬Ҳ���Բο���ͼ1.jpg����
����0~9�����֡�Ҫ���������������ֲ������ڡ�
�����ҡ����¡��ԽǶ������ڣ�
һ���ж����ֿ��ܵ�����������
����д��ʾ������Ŀ��������
ע�⣺���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�*/
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int vis[9];
int martix[5][6];//���䲹��5��6��,��2��3�п�ʼ �� 4��4��
////��ǰ���ӵ��������ϡ����ϡ�����
int mx[4]={0,-1,-1,-1};
int my[4]={-1,-1,0,1};
int ans=0;
//���9���� 
bool check(int i,int j)
{
    for(int m=0;m<4;m++)
    {
        
        if(abs(martix[i+mx[m]][j+my[m]]-martix[i][j])==1)//�������
            return false;
    }
    return true;
}

void dfs(int x,int y)
{
    if(x==3 && y==4)//����
    {
        ans++;
        return;
    }
    for(int i=0;i<10;i++)
    {
        if(vis[i]==0)//һ��ʼû��ʹ�ù�
        {
            martix[x][y]=i;
            if(!check(x,y))//�������������
            {
                martix[x][y]=-10;//���� ���ɳ�ʼ��Ϊ-10
                continue;
            }
            vis[i]=1;//����Ѿ����ʹ�
            if(y==4)
                dfs(x+1,1);//����
            else dfs(x,y+1);
            vis[i]=0;          //����
            martix[x][y]=-10;
        }
    }
}

void init(){       //��5x6�ĸ�������-10���� 
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			martix[i][j]=-10;
		}
	}
}
int main()
{
    memset(martix,-10,sizeof(martix));//ȫ����ʼ��Ϊ-10
    memset(vis,0,sizeof(vis));
    dfs(1,2);
    cout<<ans;
    return 0;
}