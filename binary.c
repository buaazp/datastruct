#include <stdio.h>

#define MAX 10000
#define keytype int

typedef struct table
{
    keytype key[MAX];
    int length;
}table;

int binarySearch(table t, keytype k)
{
    int i, low, mid, high;
    low = 0;
    high = t.length - 1;
    mid = (low + high) / 2;
    while(low <= high)
    {
        if(t.key[mid] == k)
            return mid;
        else if(t.key[mid] > k)
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
        else
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
    }
    return -1;
}

int main()
{
    table t;
    int i, k, n, ret;
    ret = -1;
    n = 20;
    t.length = n;
    for(i = 0; i < n; i++)
        t.key[i] = i * 2 + 1;
    printf("输入要查询的k值:");
    scanf("%d", &k);
    ret = binarySearch(t, k);
    if(ret < 0)
    {
        printf("%d 未找到！\n", k);
    }
    else
    {
        printf("%d位于表中的第%d位置.\n", k, ret);
    }
    return 0;
}











