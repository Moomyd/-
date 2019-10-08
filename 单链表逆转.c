#include <stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;
List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲��� */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}
List Read()
{
  int len = 0;
  int num = 0;
  PtrToNode list = NULL;
  PtrToNode last = NULL;

  scanf( "%d",&len );
  if(  len == 0  )
    return NULL;
  while(  len ){
    scanf( "%d",&num );
    PtrToNode node = ( PtrToNode )malloc( sizeof( struct Node ) );
    node->Data = num;
    node->Next = NULL;
    last->Next = node;
    last = node;
    len--;
  }
  return list;
}
void Print( List L )
{
    if(L==NULL)
    return ;
    while(L!=NULL){
        printf("%d ",L->Data);
        L=L->Next;
    }
    putchar('\n');
}
List Reverse( List L ){
    PtrToNode t=NULL;
    PtrToNode newlist=NULL;
    while(L!=NULL){
        t=L->Next;      //��t����L����һ���ڵ㣬����L->next�Ͷ�ʧ�ˣ�����L���ƶ�
        L->Next=newlist;//Lָ������ǰһ���ڵ�
        newlist=L;      //newlistָ���Ѿ���ת�����һ���ڵ�
        L=t;        //��L�ƶ�����һ��Ԫ��
     printf("%d",L);
    }
    return newlist;
}
