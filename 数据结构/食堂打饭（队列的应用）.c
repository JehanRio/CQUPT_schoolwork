//对队列进行简单的应用（比如食堂排队，银行取排队等等）
//食堂打饭系统

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

void InitQueue(LinkQueue *q)
{
    *q=(Queue *)malloc(sizeof(Queue));
    (*q)->front=NULL;
    (*q)->rear=NULL;
    (*q)->lenth=0;
}
//入队
void Add(LinkQueue *q,int data)
{
    if((*q)==NULL)
        return;
    Node *node;
    node=(Node *)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;//插到尾部
    if((*q)->front==NULL)//如果队列为空，则队头队尾都指向该结点
    {
        (*q)->front=node;
        (*q)->rear=node;
    }
    else
    {
        (*q)->rear->next=node;
        (*q)->rear=node;
    }
    (*q)->lenth++;
}
//删除
void Delete(LinkQueue *q,int *e)
{
    if((*q)->front==NULL)
    {
        return;
    }
    Node *p;
    p=(*q)->front;
    *e=p->data;
    (*q)->front=p->next;//队头指针指向第二个结点
    free(p);
    if((*q)->front==NULL)//如果只有一个结点，那么删除这个结点后，rear需要指向NULL
        (*q)->rear=NULL;
    (*q)->lenth--;
}

//遍历队列
void Print(LinkQueue *q)
{
    if((*q)->front==NULL)
       {
            printf("当前队伍没人");
            return;
       }
    printf("当前队伍有%d人，你的号码为%d号，前面有%d个人",(*q)->lenth,(*q)->rear->data,(*q)->rear->data-(*q)->front->data);
    printf("\n");
}

void main()
{
    LinkQueue q;
    InitQueue(&q);
    int n,e;
    while(1)
    {
        printf("\t\t\t\t ******千喜鹤食堂欢迎你*******\n");
        printf("\t\t\t\t*********[1]入队排号*********\n");
        printf("\t\t\t\t*********[2]出队叫号*********\n");
        printf("\t\t\t\t*********[3]查询队伍情况*****\n");
        printf("\t\t\t\t*********[4]退出*************\n");
        printf("请输入指令：");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            Add(&q,q->lenth+1);
            printf("取号成功，您的号码为:%d号\n",q->lenth);
            break;
        case 2:
            Delete(&q,&e);
            if(q->front!=NULL)
                printf("请%d号来打饭\n",q->front->data);
            else printf("队伍已空\n");
            break;
        case 3:
            Print(&q);
            break;
        case 4:
            exit(0);

        }
    }
}
