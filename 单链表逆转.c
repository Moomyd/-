#include <stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;
List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

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
        t=L->Next;      //用t保存L的下一个节点，否则L->next就丢失了，方便L的移动
        L->Next=newlist;//L指向它的前一个节点
        newlist=L;      //newlist指向已经逆转的最后一个节点
        L=t;        //将L移动到下一个元素
     printf("%d",L);
    }
    return newlist;
}
