/*
2.基于顺序存储结构的核酸检测排队管理程序设计
利用顺序存储结构设计一个核酸检测排队管理程序，记录每个人员的姓名和领到的顺序号，并提供数据管理的功能。程序的运行界面包括队伍的状态，
以及提供管理功能的数字化菜单。队伍的状态是指排队的人数，以及排在队伍最前方及最后方的人员的信息。队伍的状态需要在数字化菜单之前显示，
且能够根据用户录入数据的情况自动更新。
数字化菜单将插入、删除、查找、排序和打印等功能集成在一起，用户通过输入不同的数字来执行相应的操作。需要实现的功能包括：
1)	新增排队人员。增加的人数以及新增人员的信息来自于键盘输入。1
2)	安排检测。使用此功能后，排在队伍最前方的人员的信息删除。1
3)	在指定位置之前插入新的客人，并显示插入后队伍的状态。1
4)	删除指定位置的人员信息，并显示删除后队伍的状态。1
5)	根据姓名进行折半查找，并返回客人在队伍中的位置,若未找到请输出相应的提示信息。0
6)	按顺序号进行冒泡排序。1
7)	在屏幕上输出所有人员的信息。1
*/

#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define MAXSIZE 20
typedef int ElemType;

typedef struct
{
    int num;
    char name[5];
}stu;

typedef struct
{
    stu *elem;
    int length;
}SqList;

void InitList(SqList *L)//顺序表初始化
{  
    L->elem=(stu*)malloc(sizeof(stu)*MAXSIZE);
    L->length=0;
}

void output(SqList *s)//顺序表输出
 {
    int i;
    printf("------队伍状态------\n");
    printf("顺序号\t姓名\n");
    for (i = 0; i < s->length; i++)
        printf("%d\t%s\n", s->elem[i].num, s->elem[i].name);
}

void Input(SqList *s)
{
    printf("请输入新增的排队人员:");
    int n;
    scanf("%d",&n);
    while(n<1||n>MAXSIZE)
	{
		printf("输入错误，请重新输入 ");
		scanf("%d",&n);
	}
    for(int i=0;i<n;i++)
    {
        printf("第%d位人员的顺序号:",i+1);
        scanf("%d",&(s->elem[i].num));
        printf("第%d位人员的姓名：",i+1);
        scanf("%s",s->elem[i].name);
    }
    s->length=n;
}

void Delete1(SqList *L)
{
    printf("请下一位进行核酸检测");
    for(int i=1;i<=L->length;i++)
    {
        L->elem[i-1]=L->elem[i];
    }
    L->length--;
}

void Delete2(SqList *L)
{
    int pos;
    printf("请输入删除的位置:");
    scanf("%d",&pos);
    while(pos<1||pos>L->length)
    {
        printf("ERROR");
        scanf("%d",&pos);
    }
    for(--pos;pos<L->length;pos++)
    {
        L->elem[pos]=L->elem[pos+1];
    }
    L->length--;
    printf("删除成功\n");
    output(L);
}

void Insert(SqList *L)
{
    printf("请输入插队的位置：");
    int n;
    scanf("%d",&n);
    for(int i=L->length-1;i>=n-1;i--)
    {
        L->elem[i+1]=L->elem[i];
    }
    printf("请输入插队的人的顺序号:");
    int m;
    scanf("%d",&(L->elem[n-1].num));
    printf("插队的人的姓名:");
    scanf("%s",L->elem[n-1].name);
    L->length++;
    printf("插队后，队伍状态为：");
    output(L);
}

void Sort(SqList *L)//冒泡排序,根据序号
{
	char tmp_name[6];//定义临时字符串，用于存储临时变量
	for (int i = 0; i < L->length - 1; i++)
	{
		for (int j = 0; j < L->length - i - 1; j++)
		{
			if (L->elem[j].num > L->elem[j + 1].num)
			{
				int tmp_id = L->elem[j].num;
				strcpy(tmp_name, L->elem[j].name);
				L->elem[j].num = L->elem[j+1].num;
				strcpy( L->elem[j].name,L->elem[j+1].name);
				L->elem[j+1].num = tmp_id;
				strcpy( L->elem[j+1].name, tmp_name);
			}
		}
	}
}

SqList SORT(SqList L)//冒泡排序，根据姓名
{
    char tmp_name[6];//定义临时字符串，用于存储临时变量
	for (int i = 0; i < L.length - 1; i++)
	{
		for (int j = 0; j < L.length - i - 1; j++)
		{
			if (strcmp(L.elem[j].name,L.elem[j + 1].name)>0)
			{
				int tmp_id = L.elem[j].num;
				strcpy(tmp_name, L.elem[j].name);
				L.elem[j].num = L.elem[j+1].num;
				strcpy( L.elem[j].name,L.elem[j+1].name);
				L.elem[j+1].num = tmp_id;
				strcpy( L.elem[j+1].name, tmp_name);
			}
		}
	}
    return L;
}
int Binary_Search(SqList L,char *s)//根据姓名折半查找
{
    SqList m=SORT(L);
    int i,pos;
    int low,mid,high;
    high=L.length-1;
    low=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(strcmp(L.elem[mid].name,s)<0)
            low=mid+1;
        else if(strcmp(L.elem[mid].name,s)>0)
            high=mid-1;
        else return mid;
    }
    return -1;//返回下标0
}



void main()
{
    SqList L;
    InitList(&L);
    int n;
    while (1)
    {
        printf("********************************************************************\n");
	    printf("*      1. 新增排队人员;                     \n");
	    printf("*      2. 安排检测;                    \n");
	    printf("*      3. 在指定位置之前插入新的客人，并显示插入后队伍的状态;                 \n");
	    printf("*      4. 删除指定位置的人员信息，并显示删除后队伍的状态                                \n");
        printf("*      5. 按顺序号进行冒泡排序;                        \n");
        printf("*      6. 根据姓名进行折半查找，并返回客人在队伍中的位置      \n");
	    printf("*      7. 显示人员信息     \n");
	    printf("*      8. 退出      \n");
	    printf("********************************************************************\n");
        printf("\n");
        printf("请选择：");
    scanf("%d",&n);
    switch(n)
    {
        case 1:Input(&L);break;
        case 2:Delete1(&L);break;
        case 3:Insert(&L);break;
        case 4:Delete2(&L);break;
        case 5:Sort(&L);output(&L);break;
        case 6: printf("请输入想查找的人姓名:");
                char s[6];
                scanf("%s",s);
                printf("这个人的位置是：%d\n",Binary_Search(L,s)+1);
                break;
        case 7:output(&L);break;
        case 8:exit(0);
    }
    }
}