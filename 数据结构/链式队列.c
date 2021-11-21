/*
设计一个主函数对链队列进行测试。主要功能有：链队列的初始化、求队列的长度、入队列操作、出队列操作、取对头元素
*/

#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define MAXSIZE 20

typedef struct Node
{
    int data;
    struct Node *next;
}Node,*pNode;

typedef struct
{
    pNode front;
    pNode rear;
    int lenth;
}Queue,*LinkQueue;

//初始化
void InitQueue(LinkQueue *q)
{
    *q=(Queue *)malloc(sizeof(Queue));
    (*q)->front=NULL;
    (*q)->rear=NULL;
    (*q)->lenth=0;
}

//入队
void Add(LinkQueue q,int data)
{
    if((q)==NULL)
        return;
    Node *node;
    node=(Node *)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;//插到尾部
    if((q)->front==NULL)//如果队列为空，则队头队尾都指向该结点
    {
        (q)->front=node;
        (q)->rear=node;
    }
    else
    {
        (q)->rear->next=node;
        (q)->rear=node;
    }
    (q)->lenth++;
}

//删除
void Delete(LinkQueue *q,int *e)
{
    Node *p;
    p=(*q)->front;
    *e=p->data;
    (*q)->front=p->next;//队头指针指向第二个结点
    free(p);
    if((*q)->front==NULL)//如果只有一个结点，那么删除这个结点后，rear需要指向NULL
        (*q)->rear=NULL;
}

//遍历队列
void Print(LinkQueue *q)
{
    if((*q)->front==NULL)
       {
            printf("该队列为空");
            return;
       }
    Node *p=(*q)->front;
    printf("该队列为:");
    while(p)
    {
        printf("%-4d",p->data);
        p=p->next;
    }
    printf("\n");
}

//取队头
void GetFront(LinkQueue *q,int *e)
{
    if((*q)->front==NULL)
        return;
    *e=(*q)->front->data;
}

int PD()
{
    int n,m;
    m=scanf("%d",&n);
    while(m!=1)
    {
        while(getchar()!='\n');
        printf("输入错误，请重新输入:");
        m=scanf("%d",&n);
    }
    return n;
}

void main()
{
    LinkQueue q;
    int e;
    InitQueue(&q);
    printf("请输入队列数据个数：");
    int n,j;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {
            printf("请输入第%d个数:",i+1);
            j=PD();
            Add(q,j);
        }
    Print(&q);
    printf("该队列长度为：%d\n",q->lenth);
    GetFront(&q,&e);
    printf("该队头为：%d\n",e);
    Delete(&q,&e);
    printf("删除队头后，");
    Print(&q);
}
