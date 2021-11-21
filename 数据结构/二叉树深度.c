/*假设二叉树采用链式存储结构进行存储，编写程序实现求出二叉树的深度*/

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

int Depth(BiTree T)
{
    int l,r;
    if(T==NULL)
        return 0;
    else
    {
        l=Depth(T->lchild);
        r=Depth(T->rchild);
        if(l>r)return (l+1);
        else return (r+1);
    }
}

void main()
{
    BiTree T;
    InitList(&T);
    printf("请输入该树:");
    CreatBiTree(&T);
    printf("树的深度为：%d",Depth(T));
}
