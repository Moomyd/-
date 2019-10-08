#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
#define INCREMENTSIZE 10

typedef struct status {
	int *elem;
	int length;
	int listsize;
	int incrementsize;
}SqList;

void AuB(SqList A, SqList B, SqList C);
void AnB(SqList A, SqList B, SqList C);
void A_B(SqList A, SqList D,SqList E);
int GetElem(SqList L, int j);
int LocateElem(SqList L, int e);
//void ListDelete(SqList A, int i);

int main()
{
	SqList A, B, C, D,E;
	int i, a, b;
	printf("输入集合A的元素个数：a=");
	scanf("%d", &a);
	printf("输入集合B的元素个数：b=");
	scanf("%d", &b);
	A.elem = (int*)malloc(a * sizeof(int));
	B.elem = (int*)malloc(b * sizeof(int));
	C.elem = (int*)malloc((a > b ? a : b) * sizeof(int));
	D.elem = (int*)malloc((a <b ? a : b) * sizeof(int));
	E.elem = (int*)malloc((a < b ? a : b) * sizeof(int));
	if (!A.elem ||! B.elem ||! C.elem ||! D.elem||!E.elem)
	{
		printf("error!");
		exit(0);
	}
	else
	{
		A.length = 0;
		A.listsize = a;
		B.length = 0;
		B.listsize = b;
		C.length = 0;
		C.listsize = (a > b) ? a : b;
		D.length = 0;
		D.listsize = (a < b) ? a : b;
		E.length = 0;
		E.listsize = (a < b) ? a : b;
	}
	printf("输入集合A的元素：");
	for (i = 0; i < a; i++)
	{
		scanf("%d", (A.elem + i));
		A.length++;
	}
	printf("输入集合B的元素：");
	for (i = 0; i < b; i++)
	{
		scanf("%d", (B.elem + i));
		B.length++;
	}
	AuB(A, B, C);
	AnB(A, B, D);
	A_B(A, B,E);
	system("pause");
	return 0;
}


void AuB(SqList A, SqList B, SqList C)
{
	int i, j, k, e, *newbase;
	for (i = 0; i < A.length; i++)
	{
		C.elem[i] = A.elem[i];
		C.length++;
	}

	for (j = 0; j < B.length; j++)
	{
		e = GetElem(B, j);
		k = LocateElem(C, e);
		if (k == 0)
		{
			if (C.length >= C.listsize)
			{
				newbase = (int*)realloc(C.elem, (C.listsize + INCREMENTSIZE) * sizeof(int));
				if (!newbase)exit(0);
				C.elem = newbase;
				C.listsize += INCREMENTSIZE;
			}

			C.elem[C.length] = B.elem[j];
			C.length++;
		}
	}
	printf("AB的并集为C={");
	for (i = 0; i < C.length;i++)
		printf("%d ", *(C.elem + i));
	printf("}.\n");
}

void AnB(SqList A, SqList B, SqList D)
{
	int i, k, t,*p;
	p = D.elem;

	for (i = 0; i < A.length; i++)
	{
		t = GetElem(A, i);
		k = LocateElem(B, t);
		if (k >0)
		{
			*p= t;
			p = p + 1;
			D.length++;
		}
	}
	if (D.length == 0)
	{
		printf("AB的交集为空集。\n");
	}
	else
	{
		printf("AB的交集为D={");
		for (i = 0; i < D.length; i++)
		{
			printf("%d ", *(D.elem + i));
		}
		printf("}.\n");
	}
}

void A_B(SqList A, SqList B,SqList E)
{
	int i, j,k=0;
	for (i = 0; i < A.length; i++)
	{
		j=0;
		while(j<B.length&&B.elem[j]!=A.elem[i])
            j++;
        if(j==B.length)
            E.elem[k++]=A.elem[i];

	}
	E.length=k;
	if (E.length == 0)
	{
		printf("AB的差集为空集。\n");
	}
	else
	{
		printf("AB的差集为E={");
		for (i = 0; i < E.length; i++)
		{
			printf("%d ", *(E.elem + i));
		}
		printf("}.\n");
	}
}

int GetElem(SqList L, int j)
{


	if (j<0 || j>L.length)printf("ERROR");
	return L.elem[j];
}

int LocateElem(SqList L, int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e) return i+1;//返回值为i+1
	}
	return 0;
}

/*void ListDelete(SqList A, int i)
{
	int *p, *q;
	if (i<0 || i>A.length)
	{
		printf("error");
		exit(0);
	}
	p = A.elem+i-1;
	q = A.elem + A.length - 1;
	for (++p; p <= q; p++)
		*(p-1)  = *p;
	A.length--;

}*/
