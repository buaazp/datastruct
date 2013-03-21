#include <stdio.h>

#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int ElemType;

#define List_Size 100
#define ListIncrement 10
typedef struct{
    ElemType *elem;
    int length;
    int listsize;
}SqList;

typedef struct node
{
    int data;
    struct node *next;
}NODE;
