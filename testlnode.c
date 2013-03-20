#include <stdio.h>
#include "lnode.h"

int main(void)
{
	int n = 5;
	//LinkList *L = (LinkList *)malloc(sizeof(LNode));
	LinkList L;
	//InitLinkList(L);
	CreateLinkList(L, n);
	DisplayLinkList(L);
	return 0;
}
