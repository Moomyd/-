#include <stdio.h>
#include <stdlib.h>//
#define LIST_SIZE 100
#define LIST_ADD 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef char Status;//Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef char ElemType;
typedef struct
{
	ElemType *elem;//�洢�ռ�Ļ���ַ
	int length;//��ǰ����
	int listsize;//��ǰ����Ĵ洢����
}SqList;
Status InitList(SqList L)//��ʼ��һ��˳���
{
    int i,n;
    L.elem=(ElemType *)malloc(LIST_SIZE*sizeof(ElemType));
    if(!L.elem)
        return ERROR;
    L.length=0;
    L.listsize=LIST_SIZE;
    printf("�����뵥�ʣ�Сд��:");
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
        printf("B���ֵ�������ǰ��");
    else if(m<0)
        printf("A���ֵ�������ǰ��");
    return 0;
}

