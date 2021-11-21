/*
使用循环链表实现一个通信录的管理程序，
通信录中的每个联系人的信息包括姓名、电话和单位三项（如果还需要其他项目请自己增加）。
要求实现数字化的菜单管理数据的添加、删除、查找和显示等功能（参照实验一）。
*/

#include"stdio.h"
#include"stdlib.h"
#include"string.h"

#define OK 1
#define MAXSIZE 100
#define PF printf("\n")

typedef int Status;

typedef struct student
{
    char name[6];
    char phone[12];
    char firm[40];
    struct student *next;
}list,*List;

//初始化链表，让尾指向头
void InitList(List *L)
{
    *L=(List)malloc(sizeof(list));
    (*L)->next=*L;
}

//创建循环链表
void CreatList(List *L)
{
    List r,p;
    int n;
    r=*L;
    r->next=*L;//让尾指向头
    printf("请输入数据的个数：");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        p=(List)malloc(sizeof(list));
        printf("第%d个同志姓名：",i+1);
        scanf("%s",p->name);
        printf("第%d个同志手机：",i+1);
        scanf("%s",p->phone);
        int tag1=0,tag2=0;
        if(strlen(p->phone)==11)
            tag1=1;
        for(int i=0;i<strlen(p->phone);i++)
        {
            if(p->phone[i]>='0'&&p->phone[i]<='9')tag2=1;
            else
            {
                tag2=0;
                break;
            }
        }
        while(tag1==0||tag2==0)
        {
            printf("输入有误，请重新输入\n");
            printf("第%d个同志手机：",i+1);
            scanf("%s",p->phone);
            if(strlen(p->phone)==11)
            tag1=1;
        for(int i=0;i<strlen(p->phone);i++)
        {
            if(p->phone[i]>='0'&&p->phone[i]<='9')tag2=1;
            else
            {
                tag2=0;
                break;
            }
        }
        }

        printf("第%d个同志单位：",i+1);
        scanf("%s",p->firm);
        r->next=p;
        r=p;
    }
    p->next=*L;
}
//求长度
int Length(List L)
{
    List p=L->next;
    int len=0;
    while(p!=L)
    {
        p=p->next;
        len++;
    }
    return len;
}
//输出
void Print(List *L)
{
    List p;
    int i=1;
    p=(*L)->next;
    while(p!=(*L))
    {
        printf("第%d个同志姓名：%s\n",i,p->name);
        printf("第%d个同志手机：%s\n",i,p->phone);
        printf("第%d个同志单位：%s\n",i,p->firm);
        i++;
        p=p->next;
    }
}

//插入
void Insert(List *L)
{
    List p=(*L),r;
    printf("请选择插入的位置：");
    int n,i=0;
    scanf("%d",&n);
    while(n<1||n>Length(*L)+1)
     {
         printf("输入的位置错误，请重新输入：");
         scanf("%d",&n);
     }
     r=(List)malloc(sizeof(list));
     printf("请输入该同志的姓名：");
     scanf("%s",r->name);
     printf("请输入该同志的电话：");
     scanf("%s",r->phone);
     printf("请输入该同志的单位：");
     scanf("%s",r->firm);
     while(i<n-1)//找到结点的位置
     {
         p=p->next;
         i++;
     }
     r->next=p->next;
     p->next=r;
}

//查找
void Search(List L)
{
    List p=L->next;
    int flag=1;
    char s[5];
    printf("请输入你要查找的姓名：");
    scanf("%s",s);
    while(p!=L)
    {
        if(strcmp(s,p->name)==0)
        {
                flag=0;
                printf("该同志姓名：%s\n",p->name);
                printf("该同志电话：%s\n",p->phone);
                printf("该同志单位：%s\n",p->firm);
        }
        p=p->next;
    }
    if(flag)
        printf("未找到!");
}

//删除
void Delete(List *L)
{
    int n;
    List p=(*L),r;
    printf("请输入要删除的位置：");
    scanf("%d",&n);
    while(n<1||n>Length(*L))
    {
        printf("位置错误，重新输入");
        scanf("%d",&n);
    }
    for(int i=0;i<n-1;i++)
        p=p->next;
    r=p->next;
    p->next=r->next;
    free(r);


}

void main()
{
    List L;
    InitList(&L);
    int n;
    while(1)
    {
    printf("\t\t***********************************\n");
    printf("\t\t1、建立链表\t\t2、插入数据\n");
    printf("\t\t3、查找数据\t\t4、删除数据\n");
    printf("\t\t5、显示链表\t\t6、退出\n");
    printf("\t\t***********************************\n");
    printf("请选择：");
    scanf("%d",&n);
    switch(n)
    {
        case 1:CreatList(&L);break;
        case 2:Insert(&L);break;
        case 3:Search(L);break;
        case 4:Delete(&L);break;
        case 5:Print(&L);break;
        case 6:exit(0);
    }
    }
}



