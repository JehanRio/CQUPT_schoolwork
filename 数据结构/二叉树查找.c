//利用二叉排序树对用户输入的任意字符串统计其中的0-9数字出现的次数，并输出统计结果
#include "stdio.h"
#include "string.h"
#include"stdlib.h"
#define MAXSIZE 100


typedef struct BSTreeNode//树的一个结点
{
    char ch;
    int count;
    struct BSTreeNode *lchild,*rchild;
}BSTree,*BiTree;

void CreatTree(BiTree *T,char ch)
{
    if((*T)==NULL)//如果该结点为空
    {
        (*T)=(BiTree)malloc(sizeof(BSTree));
        (*T)->lchild=(*T)->rchild=NULL;
        (*T)->ch=ch;
        (*T)->count=1;
    }
    else if(ch==(*T)->ch)//如果该等于该结点的字符，那么该字符+1
        (*T)->count++;
    else if(ch<(*T)->ch)
        CreatTree(&(*T)->lchild,ch);
    else
        CreatTree(&(*T)->rchild,ch);
}
/*
void CreatTree(BiTree T,char ch)
{
    if((T)==NULL)//如果该结点为空
    {
        (T)=(BiTree)malloc(sizeof(BSTree));
        (T)->lchild=(T)->rchild=NULL;
        (T)->ch=ch;
        (T)->count=1;
    }
    else if(ch==(T)->ch)//如果该等于该结点的字符，那么该字符+1
        (T)->count++;
    else if(ch<(T)->ch)
        CreatTree((T)->lchild,ch);
    else
        CreatTree((T)->rchild,ch);
}
*/
void InOrderTraverse(BiTree T)
{
    if(T!=NULL)
    {
        InOrderTraverse(T->lchild);
        printf("%c->[%d]\n",T->ch,T->count);
        InOrderTraverse(T->rchild);
    }
}

void main()
{
    BiTree T=NULL;
    char str[MAXSIZE];
    int i=0;
    printf("请输入字符串：");
    scanf("%s",str);
    while(str[i]!='\0')
    {
        CreatTree(&T,str[i]);
        //CreatTree(T,str[i]);
        i++;
    }
    printf("每个字符出现的次数是：\n");
    InOrderTraverse(T);
}
