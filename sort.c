/*
 * 常见排序算法合集
 * 包括插入排序、二分插入排序等
 * 以下是运行示例：
 * zippo@localhost datastruct$ ./sort
 * 输入数组长度n: 5
 * 输入数组元素data[0]: 1
 * 输入数组元素data[1]: 10
 * 输入数组元素data[2]: 5
 * 输入数组元素data[3]: 9
 * 输入数组元素data[4]: 3
 * 数组元素为:
 *     1   10    5    9    3
 * 对数据进行插入排序...
 * 数组元素为:
 *     1    3    5    9   10
 * 数组元素为:
 *     1   10    5    9    3
 * 对数据进行二分插入排序...
 * 数组元素为:
 *     1    3    5    9   10
 */

#include <stdio.h>
#include <ctype.h>

#define INF 99999
#define MAX 256
#define datatype int

int insertSort(datatype data[], int n)
{
    printf("对数据进行插入排序...\n");
    int i, j;
    datatype tmp;
    for(i = 1; i < n; i++)
    {
        if(data[i] < data[i-1])
        {
            tmp = data[i];
            j = i - 1;
            while(tmp < data[j] && j >= 0)
            {
                data[j+1] = data[j];
                j--;
            }
            data[j+1] = tmp;
        }
    }
    return 1;
}

int binsertSort(datatype data[], int n)
{
    printf("对数据进行二分插入排序...\n");
    int i, j, low, high, mid;
    datatype tmp;
    for(i = 1; i < n; i++)
    {
        tmp = data[i];
        low = 0;
        high = i - 1;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(tmp < data[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for(j = i; j > high+1; j--)
        {
            data[j] = data[j-1];
        }
        data[high+1] = tmp;
    }
    return 1;
}

int createData(datatype data[])
{
    int i, n;
    printf("输入数组长度n: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("输入数组元素data[%d]: ", i);
        scanf("%d", &data[i]);
    }
    return n;
}

int printData(datatype data[], int n)
{
    int i;
    printf("数组元素为:\n");
    for(i = 0; i < n; i++)
    {
        printf("%5d", data[i]);
    }
    printf("\n");
    return 1;
}

int copyData(datatype orig[], datatype new[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        new[i] = orig[i];
    return 1;
}

int main()
{
    int n, ret;
    datatype orig[MAX], data[MAX];
    n = createData(orig);
    copyData(orig, data, n);
    printData(data, n);
    ret = insertSort(data, n);
    printData(data, n);
    copyData(orig, data, n);
    printData(data, n);
    ret = binsertSort(data, n);
    printData(data, n);
    return 0;
}
