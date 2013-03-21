#include <stdio.h>
#include "dnode.h"

dNode *createdNode(int n)
{
	if(n<1)
		return ERROR;
	int i;
	dNode *head;
	dNode *recent;

	for(i=0; i<n; i++)
	{
		dNode *p = (dNode *)malloc(sizeof(dNode));
		if(!p)
			exit(OVERFLOW);
		if(i == 0)
		{
			p->next = NULL;
			p->prior = NULL;
			head = p;
		}
		else
		{
			p->next = recent->next;
			p->prior = recent;
			recent->next = p;
		}
		//scanf("%d", &(p->data));
		p->data = i+1;

		recent = p;
	}
	return head;
}

dNode *getNode(dNode *L, int i)
{
	if(i<1)
		return ERROR;
	int k;
	dNode *p = (dNode *)malloc(sizeof(dNode));
	p = L;
	if(!p)
		exit(OVERFLOW);
	for(k=0; k<i-1 && p!=NULL; k++)
	{
		p = p->next;
	}
	if(p)
		return p;
	else
		return ERROR;
}

ElemType getElem(dNode *L, int i)
{
	if(i<1)
		return ERROR;
	int k;
	//dNode *p = (dNode *)malloc(sizeof(dNode));
	dNode *p = L;
	if(!p)
		exit(OVERFLOW);
	for(k=0; k<i-1 && p!=NULL; k++)
	{
		p = p->next;
	}
	if(p != NULL)
		return p->data;
	else
		return ERROR;
}
void printdNode(dNode *L)
{
	dNode *p = L;
	for(; p!=NULL; p=p->next)
	{
		if(p->next!=NULL)
		{
			printf("%d -> ", p->data);
		}
		else
		{
			printf("%d\n", p->data);
		}
	}
}

int insertdNode(dNode *L, int i, ElemType x)
{
	if(i<1)
		return ERROR;
	dNode *p = (dNode *)malloc(sizeof(dNode));
	if(!p)
		exit(OVERFLOW);
	p->data = x;
	int j;
	if(i>1)
	{
		dNode *q = getNode(L, i-1);
		//printf("L[%d]: ", i-1);
		//printdNode(q);
		if(q != NULL)
		{
			if(q->next != NULL)
			{
				p->next = q->next;
				p->prior = q;
				p->next->prior = p;
				q->next = p;
			}
			else
			{
				p->next = q->next;
				p->prior = q;
				q->next = p;
			}
		}
		else
		{
			return ERROR;
		}
	}
	else
	{
		ElemType tmp = L->data;
		L->data = x;
		p->data = tmp;

		p->next = L->next;
		p->prior = L;
		L->next->prior = p;
		L->next = p;
	}
	return OK;
}
