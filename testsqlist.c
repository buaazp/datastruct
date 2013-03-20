#include <stdio.h>
#include "sqlist.h"

int main(void)
{
    int n = 5;
    SqList p;
    InitSqList(&p);
    CreateSqList(&p, n);
    PrintSqList(&p);

    //insert elem to sqlist
    ElemType x = 9999;
    int i = 3;
    int result = SqListInsert(&p, i, x);
    PrintSqList(&p);

    //delete elem from sqlist
    i = 3;
    result = SqListDelete(&p, i);
    PrintSqList(&p);

    //find x from sqlist
    printf("find x: ");
    scanf("%d", &x);
    result = LocateElem(&p, x);
    printf("%d's loction is: %d.\n", x, result);

    //reserve sqlist
    ReserveSqList(&p);
    PrintSqList(&p);
    //DestorySqList(&p);
    return result;
}
