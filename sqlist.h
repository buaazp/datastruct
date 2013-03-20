#include <stdio.h>
#include "defaultvar.h"

void InitSqList(SqList *L);
void CreateSqList(SqList *L, int n);
void PrintSqList(SqList *L);
void DestroySqList(SqList *L);
int SqListInsert(SqList *L, int i, ElemType x);
int SqListDelete(SqList *L, int i);
int LocateElem(SqList *L, ElemType x);
int ReserveSqList(SqList *L);
