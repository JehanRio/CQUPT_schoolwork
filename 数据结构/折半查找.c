//建立一张有序表，采用折半查找算法查找输入的关键字，并返回其所在的位置
#include "stdio.h"
#include "string.h"
#include"stdlib.h"
#define MAXSIZE 100
/*
typedef struct
{
    int *elem;
    int length;
}Sqlist;

void InitList(Sqlist L)
{
    L.elem=(int *)malloc(sizeof(int)*MAXSIZE);
    L.length=0;
}

void CreatList(Sqlist L)
{
    printf("请输入个数：");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("请输入第%d个数：",i+1);
        scanf("%d",&L.elem[i]);
    }
    L.length=n;
}
*/
//折半查找
int Binary_Search(int *a,int n,int key)
{
    int low,mid,high;
    high=n-1;
    low=0;//除0下标外共n个数字
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]<key)
            low=mid+1;
        else if(a[mid]>key)
            high=mid-1;
        else return mid;
    }
    return -1;//返回下标0
}



void main()
{
    int *a;
    printf("请输入数组个数：");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("请输入第%d个数：",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n");
    int key;
    printf("输入你想要查找的数字:");
    scanf("%d",&key);
    printf("该数字位置为：%d",Binary_Search(a,n,key)+1);
}

