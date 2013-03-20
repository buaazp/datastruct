#include <stdio.h>

int main(void)
{
    int i, n;
    n = 5;
    int *p = (int*)malloc(n*sizeof(int));
    for (i=0; i<n; i++)
    {
        scanf("%d",&p[i]);
    }
    printf("success!\n");
    return 0;
}
