#ifndef _SEQUENTIALDEFINE_H
#include "SequentialDefine.h"
#endif
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0||i<1||i>L.length)
        return ERROR;
    *e=L.data[i-1];
    return OK;
}
//GetElem时间复杂度O(1)
Status ListInsert(SqList *L,int i,ElemType e)
{
    int k;
    if(L->length==MaxSize||i<1||i>L->length+1)
        return ERROR;
    if(i<=L->length)
    {
        for(k=L->length-1;k>=i-1;k--)
        {
            L->data[k+1]=L->data[k];
        }
    }
    L->data[i-1]=e;
    L->length++;
    return OK;
}
//ListInsert时间复杂度O(1)~O(n)
Status ListDelete(SqList *L,int i,ElemType *e)
{
    int k;
    if(L->length==0||i<1||i>L->length)
        return ERROR;
    *e=L->data[i-1];
    if(i<L->length)
    {
        for(k=i;i<L->length;k++)
        {
            L->data[k-1]=L->data[k];
        }
    }
    L->length--;
    return OK;
}
//ListDelete时间复杂度O(1)~O(n)
Status InitList(SqList *L)
{
    int i;
    for(i=0;i<100;i++)
        L->data[i]=0;
    L->length=0;
    return OK;
}
//InitList时间复杂度O(1)
Status ListLength(SqList L)
{
    int i=0;
    while(L.data[i]!=0)
        i++;
    return i+1;
}
//ListLength时间复杂度O(n)
