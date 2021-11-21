/*
1、循环队列的基本操作。要求：
设计一个主函数对循环队列进行测试。主要功能有：入队操作、出队操作、取对头元素
*/

#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define MAXSIZE 20
typedef int ElemType;

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
typedef struct
{
    int front;
    int rear;
    ElemType data[MAXSIZE];
}SqQueue;

//初始化
void InitQueue(SqQueue *q)
{
    q->front=0;
    q->rear=0;
}

int QueueLength(SqQueue q)
{
    return (q.rear-q.front+MAXSIZE)%MAXSIZE;
}

//入队
void EnQueue(SqQueue *q,ElemType e)
{
    if((q->rear+1)%MAXSIZE==q->front)//判断是否队满
        return;
    q->data[q->rear]=e;
    q->rear=(q->rear+1)%MAXSIZE;
}

//出队
void DeQueue(SqQueue *q,ElemType *e)
{
    if(q->front==q->rear)//队空
        return;
    *e=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;
}

//取对头元素
void GetFront(SqQueue *q,ElemType *e)
{
    if(q->front==q->rear)
        return;
    *e=q->data[q->front];

}

void Print(SqQueue q)
{
    if(q.front==q.rear)
    {
        printf("队空");
        return;
    }
    int begin=q.front;
    int beyond=q.rear;
    for(int i=begin;i!=beyond;i=(i+1)%MAXSIZE)
        printf("%-4d",q.data[i]);
    printf("\n");
}

void main()
{
    ElemType e;
    SqQueue q;
    InitQueue(&q);
    int n,j;
    printf("输入数据的个数：");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {
            printf("请输入第%d个数:",i+1);
            j=PD();
            EnQueue(&q,j);
        }
    printf("当前队列数据为：\n");
    Print(q);
    int x;
    GetFront(&q,&x);
    printf("队头元素：%d\n",x);
    printf("出队1个后数据为：");
    DeQueue(&q,&x);
    Print(q);
    printf("出队的数据为：%d",x);

}
