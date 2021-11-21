/*
2.����˳��洢�ṹ�ĺ������Ŷӹ���������
����˳��洢�ṹ���һ���������Ŷӹ�����򣬼�¼ÿ����Ա���������쵽��˳��ţ����ṩ���ݹ���Ĺ��ܡ���������н�����������״̬��
�Լ��ṩ�����ܵ����ֻ��˵��������״̬��ָ�Ŷӵ��������Լ����ڶ�����ǰ������󷽵���Ա����Ϣ�������״̬��Ҫ�����ֻ��˵�֮ǰ��ʾ��
���ܹ������û�¼�����ݵ�����Զ����¡�
���ֻ��˵������롢ɾ�������ҡ�����ʹ�ӡ�ȹ��ܼ�����һ���û�ͨ�����벻ͬ��������ִ����Ӧ�Ĳ�������Ҫʵ�ֵĹ��ܰ�����
1)	�����Ŷ���Ա�����ӵ������Լ�������Ա����Ϣ�����ڼ������롣1
2)	���ż�⡣ʹ�ô˹��ܺ����ڶ�����ǰ������Ա����Ϣɾ����1
3)	��ָ��λ��֮ǰ�����µĿ��ˣ�����ʾ���������״̬��1
4)	ɾ��ָ��λ�õ���Ա��Ϣ������ʾɾ��������״̬��1
5)	�������������۰���ң������ؿ����ڶ����е�λ��,��δ�ҵ��������Ӧ����ʾ��Ϣ��0
6)	��˳��Ž���ð������1
7)	����Ļ�����������Ա����Ϣ��1
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

void InitList(SqList *L)//˳����ʼ��
{  
    L->elem=(stu*)malloc(sizeof(stu)*MAXSIZE);
    L->length=0;
}

void output(SqList *s)//˳������
 {
    int i;
    printf("------����״̬------\n");
    printf("˳���\t����\n");
    for (i = 0; i < s->length; i++)
        printf("%d\t%s\n", s->elem[i].num, s->elem[i].name);
}

void Input(SqList *s)
{
    printf("�������������Ŷ���Ա:");
    int n;
    scanf("%d",&n);
    while(n<1||n>MAXSIZE)
	{
		printf("����������������� ");
		scanf("%d",&n);
	}
    for(int i=0;i<n;i++)
    {
        printf("��%dλ��Ա��˳���:",i+1);
        scanf("%d",&(s->elem[i].num));
        printf("��%dλ��Ա��������",i+1);
        scanf("%s",s->elem[i].name);
    }
    s->length=n;
}

void Delete1(SqList *L)
{
    printf("����һλ���к�����");
    for(int i=1;i<=L->length;i++)
    {
        L->elem[i-1]=L->elem[i];
    }
    L->length--;
}

void Delete2(SqList *L)
{
    int pos;
    printf("������ɾ����λ��:");
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
    printf("ɾ���ɹ�\n");
    output(L);
}

void Insert(SqList *L)
{
    printf("�������ӵ�λ�ã�");
    int n;
    scanf("%d",&n);
    for(int i=L->length-1;i>=n-1;i--)
    {
        L->elem[i+1]=L->elem[i];
    }
    printf("�������ӵ��˵�˳���:");
    int m;
    scanf("%d",&(L->elem[n-1].num));
    printf("��ӵ��˵�����:");
    scanf("%s",L->elem[n-1].name);
    L->length++;
    printf("��Ӻ󣬶���״̬Ϊ��");
    output(L);
}

void Sort(SqList *L)//ð������,�������
{
	char tmp_name[6];//������ʱ�ַ��������ڴ洢��ʱ����
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

SqList SORT(SqList L)//ð�����򣬸�������
{
    char tmp_name[6];//������ʱ�ַ��������ڴ洢��ʱ����
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
int Binary_Search(SqList L,char *s)//���������۰����
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
    return -1;//�����±�0
}



void main()
{
    SqList L;
    InitList(&L);
    int n;
    while (1)
    {
        printf("********************************************************************\n");
	    printf("*      1. �����Ŷ���Ա;                     \n");
	    printf("*      2. ���ż��;                    \n");
	    printf("*      3. ��ָ��λ��֮ǰ�����µĿ��ˣ�����ʾ���������״̬;                 \n");
	    printf("*      4. ɾ��ָ��λ�õ���Ա��Ϣ������ʾɾ��������״̬                                \n");
        printf("*      5. ��˳��Ž���ð������;                        \n");
        printf("*      6. �������������۰���ң������ؿ����ڶ����е�λ��      \n");
	    printf("*      7. ��ʾ��Ա��Ϣ     \n");
	    printf("*      8. �˳�      \n");
	    printf("********************************************************************\n");
        printf("\n");
        printf("��ѡ��");
    scanf("%d",&n);
    switch(n)
    {
        case 1:Input(&L);break;
        case 2:Delete1(&L);break;
        case 3:Insert(&L);break;
        case 4:Delete2(&L);break;
        case 5:Sort(&L);output(&L);break;
        case 6: printf("����������ҵ�������:");
                char s[6];
                scanf("%s",s);
                printf("����˵�λ���ǣ�%d\n",Binary_Search(L,s)+1);
                break;
        case 7:output(&L);break;
        case 8:exit(0);
    }
    }
}