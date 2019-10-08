#include <stdio.h>
#include <stdlib.h>//
#define LIST_SIZE 100
#define LIST_ADD 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef char Status;//Status是函数的类型,其值是函数结果状态代码，如OK等
typedef char ElemType;
typedef struct
{
	ElemType *elem;//存储空间的基地址
	int length;//当前长度
	int listsize;//当前分配的存储容量
}SqList;
Status InitList(SqList L)//初始化一个顺序表
{
    int i,n;
    L.elem=(ElemType *)malloc(LIST_SIZE*sizeof(ElemType));
    if(!L.elem)
        return ERROR;
    L.length=0;
    L.listsize=LIST_SIZE;
    printf("请输入单词（小写）:");
    gets(L.elem);
    L.length=strlen(L.elem);
}

int main()
{
	SqList A,B;
	int i,m;
	InitList(A);
	InitList(B);
	m=strcmp(A.elem,B.elem);
	if(m>0)
        printf("B在字典中排在前面");
    else if(m<0)
        printf("A在字典中排在前面");
    return 0;
}

