//����Ħ˹��ĳ�ű�̽�գ���������д��һ����ֵ���ʽ��ABCDE*?=EDCBA�����Ի���˵��
//��ABCDEӦ�ô���ͬ�����֣��ʺ�Ҳ����ĳ�����֣��� ���������Ҳ�Ҳ�ǣ��������ǣ����˳�Ĭ�˺þã�����û��������ʵĽ������ 
//�������ü���������ƣ��ҵ��ƽ�Ĵ𰸣���ABCDE�����������д������
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int numArray[10]={0,1,2,3,4,5,6,7,8,9};
    while(next_permutation(numArray,numArray+10))//�������a֮������У��ͷ���true�����a�����һ������û�к�̣�����false��ÿִ��һ�Σ�a�ͱ�����ĺ��
    {
        if(numArray[0]!=0 && numArray[4]!=0)
        {
            int left=numArray[4]+numArray[3]*10+numArray[2]*100+numArray[1]*1000+numArray[0]*10000;
            int right=numArray[0]+numArray[1]*10+numArray[2]*100+numArray[3]*1000+numArray[4]*10000;
            for(int i=1;i<=9;i++)
            {
                if(left*i==right)
            {
                cout<<numArray[0]<<numArray[1]<<numArray[2]<<numArray[3]<<numArray[4]<<endl;
                cout<<i;
                return 0;
            }     
            }
            //int tem=numArray[7];
            
        }
    }
    return 0;
}