#include <stdio.h>
#include "lnode.h"

int main(void)
{
	int n = 5;
	//LinkList *L = (LinkList *)malloc(sizeof(LNode));
	NODE *L = createNode(n);
	printNode(L);
	return 0;
}
