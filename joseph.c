/*
 * 约瑟夫问题
 * 输入三个数n s m
 * 代表一桌子坐了n个人，从第s个人开始报数，报到m的人出列
 * 采用有头结点的循环链表来处理
 * 头结点的data区存放链表长度，即还剩下的人数
 * p是当前节点，q是p的上一个节点
 * 以下是运行结果示例：
 * zippo@MacBook-Pro datastruct$ ./joseph
 * input(n s m):10 5 3
 * 7 --> 10 --> 3 --> 6 --> 1 --> 5 --> 2 --> 9 --> 4 --> 8
*/

#include <stdio.h>

#define datatype int
#define MAX 100
#define ERROR -1

typedef struct lnode
{
    datatype data;
    struct lnode *next;
}linklist;


linklist * create(int n)
{
    if(n < 1)
        return NULL;
    int i;
    linklist *lk = (linklist *)malloc(sizeof(linklist));
    if(lk == NULL)
        return NULL;
    lk->data = n;
    lk->next = lk;
    for(i = 0; i < n; i++)
    {
        linklist *p = (linklist *)malloc(sizeof(linklist));
        p->data = n - i;
        p->next = lk->next;
        lk->next = p;
    }
    return lk;
}

void joseph(int n, int s, int m)
{
    if(n < s)
        return ERROR;
    int i, j, k;
    linklist *lk = create(n);
    linklist *p, *q, *t;
    p = lk;
    for(i = 0; i < s - 1; i++)
        p = p->next;
    //q记录p的前一个节点
    q = p;
    p = p->next;
    while(lk->data > 1)
    {
        for(i = 1; i < m; i++)
        {
            if(p->next != lk)
                p = p->next;
            else
                p = lk->next;
            if(q->next != lk)
                q = q->next;
            else
                q = lk->next;
        }
        printf("%d", p->data);
        printf(" --> ");
        //delete the node
        t = p;
        q->next = p->next;
        p = p->next;
        if(p == lk)
            p = p->next;
        free(t);
        lk->data--;
    }
    printf("%d\n", p->data);
}


int main()
{
    int n, s, m;
    printf("input(n s m):");
    scanf("%d%d%d", &n, &s, &m);
    joseph(n, s, m);
    return 0;
}
