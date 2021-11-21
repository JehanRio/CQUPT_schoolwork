/*
设计一个单链表，要求编程实现如下任务：
（1）建立一个单链表（单链表数据的个数由键盘输入，一次可以完成多个数据的录入）。
（2）在第i个节点（i由键盘输入，i=0表示插入的结点作为第1个结点）之后插入一个元素为x的节点。
（3）查找指定数据的结点（指定数据的值是由键盘输入），若找到则显示查找成功并输出该节点的编号，若没有找到则显示“查找失败”等信息。
（4) 删除指定值的结点（指定值也是通过键盘输入），显示删除前后的单链表中的数据元素。
*/

#include "stdio.h"
#include<stdlib.h>
#include "time.h"
#define PF printf("\n")
typedef int ElemType;
typedef struct Node
{
    ElemType data;
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
    printf("请输入数据的个数：");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("请输入第%d个数据：",i+1);
        p=(LinkList)malloc(sizeof(Node));
        scanf("%d",&p->data);

        r->next=p;
        r=p;
    }
    r->next=NULL;
}

//单链表长度
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
//遍历链表
 void Print(LinkList *L)
 {
     LinkList p;
     int i=1;
     p=(*L)->next;
     while(p)
     {
         printf("第%d个数据为：%d\n",i++,p->data);
         p=p->next;
     }
 }

 //查找
void Search(LinkList L)
 {
     int n,j=1;
     LinkList p=L->next;
     printf("请输入查找的值:");
     scanf("%d",&n);
     while(p!=NULL)
     {
         if(p->data==n)
         {
        printf("找到了，该位置为：%d\n",j);
         }
         j++;
         p=p->next;
     }
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
     printf("请输入要插入的值：");
     scanf("%d",&m);
     LinkList p=(*L),r;
     int j=0;
     while(p&&j<n-1)//找到插入结点的位置
     {
         p=p->next;
         j++;
     }
     r=(LinkList)malloc(sizeof(Node));
     r->data=m;
     r->next=p->next;
     p->next=r;
 }

 //删除
 void Delete(LinkList *L)
 {
     LinkList p,q;
     p=(*L);
     int n;
     printf("请输入删除的数据：");
     scanf("%d",&n);
     while(p->next!=NULL)
     {
         q=p;
         p=p->next;
         if(p->data==n)
         {
             q->next=p->next;
             free(p);
             p=q;
         }
     }
     printf("已删除!\n");

 }
void main()
{
    LinkList L;
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
