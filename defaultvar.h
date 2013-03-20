#include <stdio.h>

#define ElemType int
#define OVERFLOW -1

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
