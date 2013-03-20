#include <stdio.h>

#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define List_Size 100
#define ListIncrement 10

typedef int ElemType;

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
}sqlist;

void Initsqlist(sqlist *L)
{
    L->elem = (ElemType *)malloc(List_Size*sizeof(ElemType));
    if(!L->elem)
        exit(OVERFLOW);
    L->length = 0;
    L->listsize = List_Size;
}

void Createsqlist(sqlist *L, int n)
{
    int i;
    for(i = 0;i<n;i++)
    {
        scanf("%d", &(L->elem[i]));
        L->length++;
    }
}


void Destroysqlist(sqlist *L)
{
    if(L->elem != NULL)
        free(L->elem);
    L->elem = NULL;
    L->length = 0;
}

int sqlistInsert(sqlist *L, int i, ElemType x)
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
}

int main(void)
{
    int n = 5;
    sqlist p; 
    Initsqlist(&p);
    Createsqlist(&p, n); 
    ElemType x = 9999;
    int i = 3;
    int result = sqlistInsert(&p, i, x); 
    //Destorysqlist(p);
    return result;
}
