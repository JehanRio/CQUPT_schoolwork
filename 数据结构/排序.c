//1、输入一组关键字序列分别实现下列排序，并将上述几种排序的算法编写成菜单，根据输入的数字不同执行对应的排序算法
//①直接插入排序。
//②选择排序。
//③冒泡排序。
//④快速排序。

#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define MAXSIZE 20

typedef struct
{
    int r[MAXSIZE+1];
    int length;
}SqList;

void Creat(SqList *L)
{
    printf("请输入该序列的长度：");
    scanf("%d",&(L->length));
    for(int i=1;i<=L->length;i++)
    {
        printf("请输入第%d个数：",i);
        scanf("%d",&(L->r[i]));
    }
}

//冒泡排序
void Buddlf_sort(SqList *L)
{
    int tem;
    for(int i=1;i<=L->length;i++)
    {
        for(int j=i+1;j<=L->length;j++)
        {
            if(L->r[i]>L->r[j])
            {
                tem=L->r[i];
                L->r[i]=L->r[j];
                L->r[j]=tem;
            }
        }
    }
}

//快速排序
void Quick_Sort(int *arr,int begin,int end)
{
    if(begin>end)
        return;
    int tem=arr[begin];
    int i=begin;
    int j=end;
    while(i!=j)
    {
        while(arr[j]>=tem && j>i)
            j--;
        while(arr[i]<=tem && j>i)
            i++;
        if(j>i)
        {
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
    arr[begin]=arr[i];
    arr[i]=tem;
    Quick_Sort(arr,begin,i-1);
    Quick_Sort(arr,i+1,end);
}

//直接插入排序
void ShellInsert(SqList *L)
{
    int j;
    for(int i=2;i<=L->length;i++)
    {
        if(L->r[i] < L->r[i-1])
        {
            L->r[0]=L->r[i];
            for(j=i-1;L->r[j] > L->r[0];j--)
                L->r[j+1]=L->r[j];
            L->r[j+1]=L->r[0];
        }
    }
}

//选择排序
void SelectSort(SqList *L)
{
    for(int i=1;i<=L->length;i++)
    {
        int minkey=i;
        for(int j=i+1;j<=L->length;j++)
        {
            if(L->r[minkey]>L->r[j])
                minkey=j;
        }
        int temp=L->r[i];
        L->r[i]=L->r[minkey];
        L->r[minkey]=temp;
    }
}
//输出
void Output(SqList L)
{
    for(int i=1;i<=L.length;i++)
        printf("%-4d",L.r[i]);
    printf("\n");
}
void main()
{
    int n;
    while(1)
    {
    SqList L;
    Creat(&L);
    printf("\t\t\t\t ******请选择排序算法*******\n");
    printf("\t\t\t\t*********[1]直接插入排序*********\n");
    printf("\t\t\t\t*********[2]选择排序*********\n");
    printf("\t\t\t\t*********[3]冒泡排序*****\n");
    printf("\t\t\t\t*********[4]快速排序*************\n");
    printf("\t\t\t\t*********[5]退出*************\n");
    printf("请选择：");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        ShellInsert(&L);
        printf("直接插入排序为：");
        Output(L);
        break;
    case 2:
        SelectSort(&L);
        printf("选择排序为：");
        Output(L);
        break;
    case 3:
        Buddlf_sort(&L);
        printf("冒泡排序为：");
        Output(L);
        break;
    case 4:
        Quick_Sort(L.r,1,L.length);
        printf("快速排序为：");
        Output(L);
        break;
    case 5:
        exit(0);
    }
    }

//    Output(L);
//    SelectSort(&L);
//    //Quick_Sort(L.r,1,L.length);
//    //ShellInsert(&L);
//    //Buddlf_sort(&L);
//    Output(L);
}
