/*
 * 常见排序算法合集
 * 包括插入排序、二分插入排序、希尔排序、冒泡排序、快速排序、直接选择排序、堆排序、归并排序等
 * 部分排序输出每轮排序结束后数组元素的顺序，便于理解
 * 以下是部分排序的运行示例：
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
    printf("===========================\n");
    printf("对数据进行【插入排序】...\n");
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
        printf("[%d]", i);
        printData(data, n);
    }
    printf("【插入排序】完成！\n");
    printf("===========================\n");
    return 1;
}

int binsertSort(datatype data[], int n)
{
    printf("===========================\n");
    printf("对数据进行【二分插入排序】...\n");
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
        printf("[%d]", i);
        printData(data, n);
    }
    printf("【二分插入排序】完成！\n");
    printf("===========================\n");
    return 1;
}

int shellSort(datatype data[], int n)
{
    printf("===========================\n");
    printf("对数据进行【希尔排序】...\n");
    int i, j, d;
    datatype tmp;
    for(d = n/2; d > 0; d/=2)
        for(i = d; i < n; i++)
            for(j = i-d; j >= 0 && data[j] > data[j+d]; j-=d)
            {
                tmp = data[j];
                data[j] = data[j+d];
                data[j+d] = tmp;
            }
    printf("【希尔排序】完成！\n");
    printf("===========================\n");
    return 1;
}

int bubbleSort(datatype data[], int n)
{
    printf("===========================\n");
    printf("对数据进行【冒泡排序】...\n");
    int i, j, flag;
    datatype tmp;
    flag = 1;
    for(i = 0; i < n && flag == 1; i++)
    {
        flag = 0;
        for(j = 0; j < n - i - 1; j++)
        {
            if(data[j] > data[j+1])
            {
                flag = 1;
                tmp = data[j+1];
                data[j+1] = data[j];
                data[j] = tmp;
            }
            //printf("Debug: n-i=%d, data[j]=%d, data[j+1]=%d\n", n-i, data[j], data[j+1]);
        }
        printf("[%d]", i+1);
        printData(data, n);
    }
    printf("【冒泡排序】完成！\n");
    printf("===========================\n");
    return 1;
}

int quickSort(datatype data[], int n)
{
    printf("===========================\n");
    printf("对数据进行【快速排序】...\n");
    int ret = quickSortR(data, 0, n);
    if(ret > 0)
    {
        printf("【快速排序】完成！\n");
        printf("===========================\n");
        return 1;
    }
    else
        return -1;
}

int quickSortR(datatype data[], int l, int h)
{
    if(l < h)
    {
        int i, j;
        datatype x;
        i = l;
        j = h;
        x = data[i];
        while(i < j)
        {
            while(i<j && data[j]>=x)
                j--;
            if(i < j)
            {
                data[i] = data[j];
                i++;
            }
            while(i<j && data[i]<=x)
                i++;
            if(i < j)
            {
                data[j] = data[i];
                j--;
            }
        }
        data[i] = x;
        quickSortR(data, l, i-1);
        quickSortR(data, i+1, h);
    }
    return 1;
}

int selectSort(datatype data[], int n)
{
    printf("===========================\n");
    printf("对数据进行【直接选择排序】...\n");
    int i, j, k;
    datatype tmp;
    for(i = 0; i < n - 1; i++)
    {
        k = i;
        for(j = i+1; j < n; j++)
        {
            if(data[j] < data[k])
            {
                k = j;
            }
        }
        tmp = data[i];
        data[i] = data[k];
        data[k] = tmp;
        printf("[%d]", i+1);
        printData(data, n);
    }
    printf("【直接选择排序】完成！\n");
    printf("===========================\n");
    return 1;
}

int heapSort(datatype data[], int n)
{
    printf("===========================\n");
    printf("对数据进行【堆排序】...\n");
    int i, j;
    for(i = n; i > 0; i--)
        data[i] = data[i-1];

    for(i = n/2; i > 0; i--)
        heapSift(data, i, n);
    for(i = n; i > 0; i--)
        heapDelete(data, i);

    for(i = 0; i < n; i++)
        data[i] = data[i+1];
    printf("【堆排序】完成！\n");
    printf("===========================\n");
    return 1;
}

int heapDelete(datatype data[], int n)
{
    datatype tmp = data[1];
    data[1] = data[n];
    data[n] = tmp;
    heapSift(data, 1, n-1);
    return 1;
}

int heapSift(datatype data[], int l, int h)
{
    int i, j;
    datatype tmp;
    i = l;
    j = 2 * i;
    tmp = data[i];
    while(j <= h)
    {
        if(j < h && data[j] < data[j+1])
            j++;
        if(tmp < data[j])
        {
            data[i] = data[j];
            i = j;
            j = 2 * i;
        }
        else
            j = h + 1;
    }
    data[i] = tmp;
    return 1;
}

int mergeSort(datatype data[], int n)
{
    printf("===========================\n");
    printf("对数据进行【归并排序】...\n");
    int d, i, start, m, end, ret;
    int c = 1;
    for(d = 2; d <= n; d *= 2)
    {
        start = 0;
        for(i = 1; i <= n / d; i++)
        {
            end = start + d -1;
            m = (start + end) / 2;
            ret = mergeR(data, start, m, end);
            start += d;
            printf("[%d]", c++);
            printData(data, n);
        }
    }
    if(end < n)
        mergeR(data, 0, end, n-1);
    printf("[%d]", c++);
    printData(data, n);
    if(ret > 0)
    {
        printf("【归并排序】完成！\n");
        printf("===========================\n");
        return 1;
    }
    else
        return -1;
}

int mergeR(datatype r[], int l, int m, int h)
{
    datatype s[MAX];
    int i, j, k;
    i = l;
    j = m + 1;
    k = 0;
    while(i <= m && j <= h)
    {
        if(r[i] <= r[j])
        {
            s[k++] = r[i++];
        }
        else
            s[k++] = r[j++];
    }
    if(i <= m)
    {
        while(i <= m)
        {
            s[k++] = r[i++];
        }
    }
    else
    {
        while(j <= h)
        {
            s[k++] = r[j++];
        }
    }
    //printf("Debug Info (l=%d m=%d h=%d) s[MAX]: \n", l, m, h);
    k = 0;
    for(i = l; i <= h; i++)
    {
        r[i] = s[k++];
        //printf("%d    ", r[i]);
    }
    //printf("\n");
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
    printf("\n");
    copyData(orig, data, n);
    printData(data, n);
    ret = binsertSort(data, n);
    printData(data, n);
    printf("\n");
    copyData(orig, data, n);
    printData(data, n);
    ret = shellSort(data, n);
    printData(data, n);
    printf("\n");
    copyData(orig, data, n);
    printData(data, n);
    ret = bubbleSort(data, n);
    printData(data, n);
    printf("\n");
    copyData(orig, data, n);
    printData(data, n);
    ret = quickSort(data, n);
    printData(data, n);
    printf("\n");
    copyData(orig, data, n);
    printData(data, n);
    ret = selectSort(data, n);
    printData(data, n);
    printf("\n");
    copyData(orig, data, n);
    printData(data, n);
    ret = heapSort(data, n);
    printData(data, n);
    printf("\n");
    copyData(orig, data, n);
    printData(data, n);
    ret = mergeSort(data, n);
    printData(data, n);
    return 0;
}
