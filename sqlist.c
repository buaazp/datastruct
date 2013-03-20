#include <stdio.h>
//#include "defaultVar.h"
#include "sqlist.h"

void InitSqList(SqList *L)
{
    L->elem = (ElemType *)malloc(List_Size*sizeof(ElemType));
    if(!L->elem)
        exit(OVERFLOW);
    L->length = 0;
    L->listsize = List_Size;
}

void CreateSqList(SqList *L, int n)
{
    int i;
    for(i = 0;i<n;i++)
    {
        scanf("%d", &L->elem[i]);
        L->length++;
    }
}

void PrintSqList(SqList *L)
{
    int i;
    for(i=0; i<L->length; i++)
        printf("%d ", L->elem[i]);
    printf("\n");
}

void DestroySqList(SqList *L)
{
    if(L->elem != NULL)
    {
        free(L->elem);
        L->elem = NULL;
    }
    L->length = 0;
}

int SqListInsert(SqList *L, int i, ElemType x)
{
    int j;
    ElemType *p;
    if(i<1||i>L->length+1)
        return ERROR;
    if(L->length >= L->listsize)
    {
        p = (ElemType *)realloc(L->elem, (L->listsize + ListIncrement)*sizeof(ElemType));
        if(!p)
            exit(OVERFLOW);
        L->elem = p;
        L->listsize = L->listsize + ListIncrement;
    }
    for(j = L->length; j >= i; j--)
        L->elem[j] = L->elem[j-1];
    L->elem[j] = x;
    ++L->length;
    return OK;
}

int SqListDelete(SqList *L, int i)
{
    int j;
    if(i<1 || i>L->length)
        return ERROR;
    for(j=i-1; j<L->length-1; j++)
        L->elem[j] = L->elem[j+1];
    L->length--;
    return OK;
}

int LocateElem(SqList *L, ElemType x)
{
    int i=1;
    while(i<=L->length&&L->elem[i-1]!=x){
        i++;
    }
    if(i<=L->length)
        return i;
    else
        return ERROR;
}

int ReserveSqList(SqList *L)
{
    int i, length = L->length;
    ElemType temp;
    for(i=0; i<=length/2; i++)
    {
        temp = L->elem[length-i-1];
        L->elem[length-i-1] = L->elem[i];
        L->elem[i] = temp;
    }
    return OK;
}
