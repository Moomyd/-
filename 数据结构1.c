#include<stdio.h>
#include<stdlib.h>
#define LIST_SIZE 100
#define LIST_ADD 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;
SqList L;
Status InitList(SqList &L)//初始化一个顺序表
{
    int i,n;
    L.elem=(ElemType *)malloc(LIST_SIZE*sizeof(ElemType));
    if(!L.elem)
        return error;
    L.length=0;
    L.listsize=LIST_SIZE;
    printf("请输入线性表的元素个数：")
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&L.elem[i]);
    }
    L.length=n;
    return OK;
}
Status DestoryList(SqList &L)//销毁一个顺序表
{
    free(L.elem);
    L.elem=NULL;
    L.length=0;
    L.listsize=0;
}
Status ClearList(SqList &L)//清空一个顺序表
{
    L->length=0;
    return OK;

}
int ListLength_Sq(SqList L)   //判断顺序表的长度
{
    return L.length;
}
Status ListEmpty(SqList L)//判断是否为空
{
    if(L.length==0)
        return True;
    else
        return False;
}
Status GetElem(SqList L,int i,char &e)//获得线性表第i个元素
{
    if(i<1||i>L.length)
        return ERROR;
    else
        e=L.elem[i-1];
    return OK;
}
Status LocateElem(SqList L,ElemType e)//检索值为e的数据元素
{
    int i=1;
    int p=L.elem;
    while(i<=L.length&&*p++!=e)
        i++;
    if(i<=L.length)
        return i;
    else
        return 0;
}
Status PriorElem(SqList L,ElemType cur_e,ElemType pre_e) //寻找第一个元素cur_e的前继元素
{
    int i=1;
    if(L.elem[0]!=cur_e)
    {
        while(i<L.length&&L.elem[i]!=cur_e)
            i++;
            
        if(i<L.length)
        {
            pre_e=L.elem[i-1];
            return OK;
        }
    }
    return ERROR;
}
Status NextElem(SqList L,ElemType cur_e,ElemType next_e)//返回线性表中cur的后继元素
{
    int i=1;
    if(L.elem[0]!=cur_e)
    {
        while(i<L.length&&L.elem[i]!=cur_e)
            i++;
            
        if(i<L.length)
        {
            pre_e=L.elem[i+1];
            return OK;
        }
    }
    return ERROR;
}
Status ListInsert(SqList &L,int i,ElemType e)//插入元素
{
    ElemType *newbase;
    ElemType *p,*q;
    
    if(i<1||i>L.length)
        return ERROR;
    if(L.length>=L.listsize)
    {
        newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType))
        if(!newbase)
            exit(OVERFLOW);
        L.elem=newbase;
        L.listsize += LISTINCREMENT;
    }
    q=&L.elem[i-1];
    for(p=&L.elem[L.length-1];p>=q;p--)
        *(p+1)=*p;
    *q=e;
    L.length++;
    return OK;
}
Status ListDelete(SqList &L,int i, ElemType &e)//删除元素
{
    char *p,*q;
    if(i<1||i>L.length)
        return ERROR;
    p=&L.elem[i-1];
    e=*p;
    q=L.elem+L.length-1;  
    p++;
    for(;p<=q;p++)
    {
        *(p-1)=*p;
    }
    L.length--;
    return OK;
}
Status ListTrave(SqList &L)//输出每个元素
{
    int i;
    for(i=0;i<L.length;i++)
    {
        printf("%d",L.elem[i]);
    }
}
















