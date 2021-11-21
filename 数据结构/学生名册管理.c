/*1.基于链式存储结构的学生名册管理程序设计
利用链式存储结构设计一个学生名册管理程序，记录每个学生的学号、姓名和电话号码，并通过数字化菜单实现数据管理的功能。
数字化菜单将插入、删除、查找和打印等功能集成在一起，用户通过输入不同的数字来执行相应的操作。需要实现的功能包括：
1)	录入新的学生数据。增加的人数，以及人员的信息来自于键盘输入。
2)	删除位于链表头部的学生。
3)	在指定位置之前新增一个学生的数据。
4)	删除指定学号的学生。
5)	按电话号码进行顺序查找。
6)	在屏幕上输出所有学生的信息。
以上功能的执行没有先后顺序。在程序中需要对各种特殊情况（如空链表）加以充分的考虑。
*/
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

#define OK 1
#define MAXSIZE 100
#define PF printf("\n")

typedef int Status;

typedef struct
{
    char id[10];
    char name[10];
    char phone[10];
}stu;

typedef struct Node
{
    stu data;
    struct Node *next;
}Node,*LinkList;

//建立一个只含有头结点的空链表
void InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;
}

//建立含有n个元素的单链表（尾插法）
void CreatList(LinkList *L)
{
    LinkList p,r;//p为新结点，r始终指向最后
    r=*L;
    printf("请输入学生的个数：");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("请输入第%d个同学的学号：",i+1);
        p=(LinkList)malloc(sizeof(Node));
        scanf("%s",p->data.id);
        while (strlen(p->data.id)!=5)
        {
            printf("学号错误，请重新输入");
            scanf("%s",p->data.id);
        }
        printf("请输入第%d个同学的姓名：",i+1);
        scanf("%s",p->data.name);
        printf("请输入第%d个同学的电话：",i+1);
        scanf("%s",p->data.phone);
        r->next=p;
        r=p;
    }
    r->next=NULL;
}

//遍历链表
 void Print(LinkList *L)
 {
     LinkList p;
     int i=1;
     p=(*L)->next;
     while(p)
     {
         printf("第%d个同学的id为：%s\n",i,p->data.id);
         printf("第%d个同学的姓名为：%s\n",i,p->data.name);
         printf("第%d个同学的电话为：%s\n",i,p->data.phone);
         i++;
         p=p->next;
     }
 }

 //电话查找
void Search(LinkList L)
 {
     int j=1;
     char s[5];
     LinkList p=L->next;
     printf("请输入要查找的该同学的电话:");
     scanf("%s",s);
     while(p!=NULL)
     {
         if(strcmp(s,p->data.phone)==0)
         {
            printf("该同学学号：%s\n",p->data.id);
            printf("该同学姓名：%s\n",p->data.name);
            printf("该同志电话：%s\n",p->data.phone);
            return;
         }
         p=p->next;
     }
     printf("未找到");
 }

int Length(LinkList *L)
{
    int len=0;
    LinkList head;
    head=(*L)->next;
    while(head!=NULL)
    {
        len++;
        head=head->next;
    }
    return len;
}
 //插入
 void Insert(LinkList *L)
 {
     printf("请选择插入的位置：");
     int n,m;
     scanf("%d",&n);
     while(n<1||n>Length(L)+1)
     {
         printf("输入的位置错误，请重新输入：");
         scanf("%d",&n);
     }
     printf("请输入要插入的同学的信息：");
     LinkList p=(*L),r;
     int j=0;
     while(p&&j<n-1)//找到插入结点的位置
     {
         p=p->next;
         j++;
     }
     r=(LinkList)malloc(sizeof(Node));
     printf("该同学学号：");
     scanf("%s",r->data.id);
     printf("该同学姓名：");
     scanf("%s",r->data.name);
     printf("该同学电话：");
     scanf("%s",r->data.phone);
     r->next=p->next;
     p->next=r;
 }

 //删除指定学号
 void Delete(LinkList *L)
 {
     LinkList p,q;
     p=(*L);
     char s[8];
     printf("请输入要删除的同学的学号：");
     scanf("%s",s);
     while(p->next!=NULL)
     {
         q=p;
         p=p->next;
         if(strcmp(s,p->data.id)==0)
         {
             q->next=p->next;
             free(p);
             p=q;
             printf("已删除!\n");
             return;
         }
     }
     printf("未找到");
 }

 void DeleteHead(LinkList *L)
 {
     LinkList p;
     p=(*L)->next;
     (*L)->next=p->next;
     free(p);
     printf("已删除第一名同学\n");
 }

void main()
{
    LinkList L;
    InitList(&L);
    int n;
    while(1)
    {
    printf("\t\t***********************************\n");
    printf("\t\t1、建立链表\t\t2、删除第一个数据\n");
    printf("\t\t3、插入数据\t\t4、删除指定数据\n");
    printf("\t\t5、电话查找\t\t6、显示信息\n");
    printf("\t\t7、退出");
    printf("\t\t***********************************\n");
    printf("请选择：");
    scanf("%d",&n);
    switch(n)
    {
        case 1:CreatList(&L);break;
        case 2:DeleteHead(&L);break;
        case 3:Insert(&L);break;
        case 4:Delete(&L);break;
        case 5:Search(L);break;
        case 6:Print(&L);break;
        case 7:exit(0);
    }
    }
}

