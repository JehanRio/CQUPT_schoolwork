/*1.������ʽ�洢�ṹ��ѧ���������������
������ʽ�洢�ṹ���һ��ѧ�����������򣬼�¼ÿ��ѧ����ѧ�š������͵绰���룬��ͨ�����ֻ��˵�ʵ�����ݹ���Ĺ��ܡ�
���ֻ��˵������롢ɾ�������Һʹ�ӡ�ȹ��ܼ�����һ���û�ͨ�����벻ͬ��������ִ����Ӧ�Ĳ�������Ҫʵ�ֵĹ��ܰ�����
1)	¼���µ�ѧ�����ݡ����ӵ��������Լ���Ա����Ϣ�����ڼ������롣
2)	ɾ��λ������ͷ����ѧ����
3)	��ָ��λ��֮ǰ����һ��ѧ�������ݡ�
4)	ɾ��ָ��ѧ�ŵ�ѧ����
5)	���绰�������˳����ҡ�
6)	����Ļ���������ѧ������Ϣ��
���Ϲ��ܵ�ִ��û���Ⱥ�˳���ڳ�������Ҫ�Ը����������������������Գ�ֵĿ��ǡ�
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

//����һ��ֻ����ͷ���Ŀ�����
void InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;
}

//��������n��Ԫ�صĵ�����β�巨��
void CreatList(LinkList *L)
{
    LinkList p,r;//pΪ�½�㣬rʼ��ָ�����
    r=*L;
    printf("������ѧ���ĸ�����");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("�������%d��ͬѧ��ѧ�ţ�",i+1);
        p=(LinkList)malloc(sizeof(Node));
        scanf("%s",p->data.id);
        while (strlen(p->data.id)!=5)
        {
            printf("ѧ�Ŵ�������������");
            scanf("%s",p->data.id);
        }
        printf("�������%d��ͬѧ��������",i+1);
        scanf("%s",p->data.name);
        printf("�������%d��ͬѧ�ĵ绰��",i+1);
        scanf("%s",p->data.phone);
        r->next=p;
        r=p;
    }
    r->next=NULL;
}

//��������
 void Print(LinkList *L)
 {
     LinkList p;
     int i=1;
     p=(*L)->next;
     while(p)
     {
         printf("��%d��ͬѧ��idΪ��%s\n",i,p->data.id);
         printf("��%d��ͬѧ������Ϊ��%s\n",i,p->data.name);
         printf("��%d��ͬѧ�ĵ绰Ϊ��%s\n",i,p->data.phone);
         i++;
         p=p->next;
     }
 }

 //�绰����
void Search(LinkList L)
 {
     int j=1;
     char s[5];
     LinkList p=L->next;
     printf("������Ҫ���ҵĸ�ͬѧ�ĵ绰:");
     scanf("%s",s);
     while(p!=NULL)
     {
         if(strcmp(s,p->data.phone)==0)
         {
            printf("��ͬѧѧ�ţ�%s\n",p->data.id);
            printf("��ͬѧ������%s\n",p->data.name);
            printf("��ͬ־�绰��%s\n",p->data.phone);
            return;
         }
         p=p->next;
     }
     printf("δ�ҵ�");
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
 //����
 void Insert(LinkList *L)
 {
     printf("��ѡ������λ�ã�");
     int n,m;
     scanf("%d",&n);
     while(n<1||n>Length(L)+1)
     {
         printf("�����λ�ô������������룺");
         scanf("%d",&n);
     }
     printf("������Ҫ�����ͬѧ����Ϣ��");
     LinkList p=(*L),r;
     int j=0;
     while(p&&j<n-1)//�ҵ��������λ��
     {
         p=p->next;
         j++;
     }
     r=(LinkList)malloc(sizeof(Node));
     printf("��ͬѧѧ�ţ�");
     scanf("%s",r->data.id);
     printf("��ͬѧ������");
     scanf("%s",r->data.name);
     printf("��ͬѧ�绰��");
     scanf("%s",r->data.phone);
     r->next=p->next;
     p->next=r;
 }

 //ɾ��ָ��ѧ��
 void Delete(LinkList *L)
 {
     LinkList p,q;
     p=(*L);
     char s[8];
     printf("������Ҫɾ����ͬѧ��ѧ�ţ�");
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
             printf("��ɾ��!\n");
             return;
         }
     }
     printf("δ�ҵ�");
 }

 void DeleteHead(LinkList *L)
 {
     LinkList p;
     p=(*L)->next;
     (*L)->next=p->next;
     free(p);
     printf("��ɾ����һ��ͬѧ\n");
 }

void main()
{
    LinkList L;
    InitList(&L);
    int n;
    while(1)
    {
    printf("\t\t***********************************\n");
    printf("\t\t1����������\t\t2��ɾ����һ������\n");
    printf("\t\t3����������\t\t4��ɾ��ָ������\n");
    printf("\t\t5���绰����\t\t6����ʾ��Ϣ\n");
    printf("\t\t7���˳�");
    printf("\t\t***********************************\n");
    printf("��ѡ��");
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

