#include <stdio.h>
#include "lnode.h"


NODE* createNode (int n)
{
    NODE *head, *p, *last;
    int i;
    for (i = 0; i<n; i++)
    {
        p = (NODE*)malloc(sizeof(NODE));
        if (p == NULL)
            exit(0);
        scanf("%d", &(p->data));
        //p->data = i+1;
        p->next = NULL;
        if(i == 0)
        {
            head = p;
            last = head;
        }
        else
            last->next = p;
        last = p;
    }
    return head;
}


int deleteNode(NODE *head, int i)
{
    if(i <= 0)
        return -1;
    NODE *p, *q;
    int j;
    for(j=1,q=head; j<i-1 && q->next != NULL; j++)
    {
        q = q->next;
        printNode(q);
    }
    if(q->next != NULL)
    {
        p = q->next;
        q->next = p->next;
        free(p);
    }
    return 1;
}


int insertNode(NODE *head, NODE *p, int k)
{
    if (k < 0)
        return -1;
    NODE *q;
    int i;
    for(i=1, q=head; i<k-1 && q->next != NULL; i++)
    {
        q = q->next;
    }
    //if (q->next != NULL)
    {
        p->next = q->next;
        q->next = p;
    }
    return 1;
}

void printNode(NODE *head)
{
    NODE *p;
    p = head;
    if (head != NULL)
        do
        {
            printf("%d", p->data);
            if (p->next != NULL)
            {
                printf(" -> ");
            }
            else
                printf("\n");
            p = p->next;
        }while(p != NULL);
    else
        printf("null node!\n");
}

