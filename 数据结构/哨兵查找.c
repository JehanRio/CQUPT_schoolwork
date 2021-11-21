//建立一张顺序表，利用改进的顺序查找算法对输入的关键字进行查找，并返回所在的位置#include "stdio.h"
#include "string.h"
#include"stdlib.h"
#include "stdio.h"
#define MAXSIZE 100
//有哨兵查找顺序
int Sequential_Search(int *a,int n,int key)
{
    int i=n;//循环从数组尾部开始
    a[0]=key;//设置a[0]为关键字值
    while(a[i]!=key)
        i--;
    return i;//返回0则说明查找失败,说明a[1]~a[n]中没有
}

void main()
{
    int *a;
    printf("请输入数组个数：");
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)//将数组第一个元素空出来
    {
        printf("请输入第%d个数：",i);
        scanf("%d",&a[i]);
    }
    printf("\n");
    int key;
    printf("输入你想要查找的数字:");
    scanf("%d",&key);
    int m=Sequential_Search(a,n,key);
    if(m==0)
        printf("查找失败！");
    else
        printf("该数字的位置为：%d",m);

}
