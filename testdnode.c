#include <stdio.h>
#include "dnode.h"

int main(void)
{
	int n = 5, k = 3, x = 9999;
	dNode *L = createdNode(n);
	printdNode(L);
	printf("Which position you want to insert x: ");
	scanf("%d", &k);
	ElemType elem = getElem(L, k);
	printf("L[%d] = %d\n", k, elem);
	int result = insertdNode(L, k, x);
	printdNode(L);
	return 0;
}
