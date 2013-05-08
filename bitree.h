#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define keytype int
#define MAX 10000

typedef struct bitnode
{
    keytype key;
    struct bitnode *lchild, *rchild;
}*bitree;

int createBitree(bitree *T)
{
    int i, n, ins, ret;
    ret = 1;
    keytype key;
    printf("请输入BiTree结点数n: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("输入T[%d]的key值: ", i);
        scanf("%d", &key);
        ins = insertBitree(T, key);
        if(ins < 0)
        {
            ret = -1;
            return ret;
        }
        else if(ins == 0)
        {
            printf("%d 已存在，请重新输入。\n", key);
            i--;
        }
    }
    return ret;
}

int searchBitree(bitree T, keytype key, bitree f, bitree *p)
{
    if(!T)
    {
        *p = f;
        return -1;
    }
    else if(key == T->key)
    {
        *p = T;
        return 1;
    }
    else if(key < T->key)
    {
        return (searchBitree(T->lchild, key, T, p));
    }
    else
    {
        return (searchBitree(T->rchild, key, T, p));
    }
}


int insertBitree(bitree *T, keytype key)
{
    bitree s, p;
    int se = searchBitree(*T, key, NULL, &p) ;
    if(se < 0)
    {
        s = (bitree) malloc (sizeof(struct bitnode));
        if(!s)
            return -1;
        s->key = key;
        s->lchild = s->rchild = NULL;
        if(!p)
            *T = s;
        else if(key < p->key)
            p->lchild = s;
        else
            p->rchild = s;
        return 1;
    }
    else
        return 0;
}


int delB(bitree *p)
{
    bitree q, s;
    if(!((*p)->rchild))
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else if(!((*p)->lchild))
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else
    {
        q = *p;
        s = (*p)->lchild;
        while(s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        (*p)->key = s->key;
        if(q != *p)
            q->rchild = s->lchild;
        else
            q->lchild = s->lchild;
    }
    return 1;
}

int delBitree(bitree *T, keytype key)
{
    if(!(*T))
        return -1;
    else
    {
        if(key == (*T)->key)
            delB(T);
        else if(key < (*T)->key)
            delBitree(&((*T)->lchild), key);
        else
            delBitree(&((*T)->rchild), key);
        return 1;
    }
}








