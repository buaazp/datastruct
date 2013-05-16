/*
 *
 * 汉诺塔问题
 * 以下是运行示例“
 * zippo@MacBook-Pro datastruct$ ./hanoi
 * ==========Hanoi Tower===========
 * 输入盘子数n: 4
 * Begin:
 * x -> y
 * x -> z
 * y -> z
 * x -> y
 * z -> x
 * z -> y
 * x -> y
 * x -> z
 * y -> z
 * y -> x
 * z -> x
 * y -> z
 * x -> y
 * x -> z
 * y -> z
 * End. 15 steps total used.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 256
#define datatype char

int step = 0;

int move(datatype x, datatype y)
{
    printf("%c -> %c\n", x, y);
    step++;
    return 1;
}

int hanoi(int n, datatype x, datatype y, datatype z)
{
    int ret = -1;
    if(n == 1)
        ret = move(x, z);
    else
    {
        ret = hanoi(n-1, x, z, y);
        ret = move(x, z);
        ret = hanoi(n-1, y, x, z);
    }
    return ret;
}

int main()
{
    int n, ret;
    datatype a, b, c;
    a = 'x';
    b = 'y';
    c = 'z';
    printf("==========Hanoi Tower===========\n输入盘子数n: ");
    scanf("%d", &n);
    printf("Begin:\n");
    ret = hanoi(n, a, b, c);
    printf("End. %d steps total used.\n", step);
    return 0;
}
