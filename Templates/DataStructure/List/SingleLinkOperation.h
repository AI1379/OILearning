#ifndef _SINGLELINKDEFINE_H
#include "SingleLinkDefine.h"
#endif
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList *p;
    p=L->next;
    j=1;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i)
        return ERROR;
    *e=p->data;
    return OK;
}
//GetElem时间复杂度O(n)
Status LinkInsert(LinkList *L,int i,ElemType e)
{
    int j;
    LinkList *p,*s;
    p=*L;
    j=1;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i)
        return ERROR;
    s=new node;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}
//LinkInsert时间复杂度O(n)
Status LinkDelete(LinkList *L,int i,ElemType e)
{
    int j;
    LinkList *p,*q;
    p=*L;
    j=1;
    while(p->next&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p->next||j>i)
        return ERROR;
    q=p->next;
    p->next=q->next;
    *e=q->data;
    delete q;
    return OK;
}
//LinkDelete时间复杂度O(n)
