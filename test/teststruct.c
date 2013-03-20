#include <stdio.h>

#define maxsize 100

typedef struct
{
    int *data;
    int length;
}slist;

void init(slist *s)
{
    s->data = (int *)malloc(maxsize*sizeof(int));
    s->length = 0;
}
int main(void)
{
    int i, n = 5;
    slist p;
    init(&p);
    for(i=0; i<n; i++)
    {
        scanf("%d", &(p.data[i]));
    }
    p.length = n;
    for(i=0; i<n; i++)
    {
        printf("%d->", p.data[i]);
    }
    printf("\n");
    return 0;
}
