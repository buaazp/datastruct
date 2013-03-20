#include <stdio.h>
#include "lnode.h"

void InitLinkList(LinkList L)
{
	L = (LinkList *)malloc(sizeof(LNode));
	if(!L)
		exit(OVERFLOW);
	L->next = NULL;
}


void DisplayLinkList(LinkList L)
{
	LNode *p;
	for(p=L->next; p; p=p->next)
		printf("%d", p->data);
	printf("\n");
}


void CreateLinkList(LinkList L, int n)
{
	LNode *p;
	int i;
	InitLinkList(L);
	for(i=n; i>0; i--)
	{
		//p = new LNode;
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
}
