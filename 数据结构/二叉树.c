/*
（1）编写创建二叉链表形式存储的二叉树程序并输出。
（2）编写递归实现二叉树的先序、中序、后序遍历、统计所有叶子结点的个数的算法。
（3）编写主函数测试以上二叉树的创建和遍历以及输出统计所有叶子结点个数等函数。
*/

#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define MAXSIZE 20

typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void InitList(BiTree *T)//初始化
{
    *T=(BiTree)malloc(sizeof(BiTNode));
    (*T)->lchild=NULL;
    (*T)->rchild=NULL;
}

void CreatBiTree(BiTree *T)//先序创建二叉树
{
    char ch;
    ch=getchar();
    if(' '==ch)
        *T=NULL;
    else
    {
        (*T)=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=ch;
        CreatBiTree(&(*T)->lchild);
        CreatBiTree(&(*T)->rchild);
    }
}

void InorderTraverse1(BiTree T)//先序遍历
{
    if(T)
    {
        printf("%c",T->data);
        InorderTraverse1(T->lchild);
        InorderTraverse1(T->rchild);
    }
}

void InorderTraverse2(BiTree T)//中序遍历
{
    if(T)
    {
        InorderTraverse2(T->lchild);
        printf("%c",T->data);
        InorderTraverse2(T->rchild);
    }
}

void InorderTraverse3(BiTree T)//后序遍历
{
    if(T)
    {
        InorderTraverse3(T->lchild);
        InorderTraverse3(T->rchild);
        printf("%c",T->data);
    }
}

int NodeCount_leaf(BiTree T)//统计叶子结点，递归
{
    int l,r;
    if(T==NULL)
        return 0;
    else if(T->lchild==NULL&&T->rchild==NULL)
        return 1;
    else
    {
        l=NodeCount_leaf(T->lchild);
        r=NodeCount_leaf(T->rchild);
        return (l+r);
    }
}

int Leaf(BiTree T,int count)//中序
{
	int top=-1;//空栈
	BiTree s[100];
	while(T!=NULL||top!=-1)
	{
		while(T!=NULL)  //该结点非空，判断是否为叶子 
		{
			if(T->lchild==NULL&&T->rchild==NULL)  //是叶子count++ 
			    count++;
			s[++top]=T;   //将该节点进栈 
			T=T->lchild;  //若左孩子为空则跳出 
		}
		if(top!=-1)  //栈非空
		{
			T=s[top--];   //左孩子出栈 
			T=T->rchild;//看右孩子 
		} 
	}
    return count; 
}
void main()
{
    BiTree T;
    InitList(&T);
    printf("请输入该树：");
    CreatBiTree(&T);
    printf("前序遍历为：");
    InorderTraverse1(T);
    printf("\n");
    printf("中序遍历为：");
    InorderTraverse2(T);
    printf("\n");
    printf("后序遍历为：");
    InorderTraverse3(T);
    printf("\n");
    printf("叶子结点个数为：%d\n",NodeCount_leaf(T));
    int count;
    printf("非递归函数叶子结点数为：%d\n",Leaf(T,count));

}
