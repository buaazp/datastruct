/**
* 回溯法解N皇后问题
* 使用一个一维数组表示皇后的位置
* 其中数组的下标表示皇后所在的行
* 数组元素的值表示皇后所在的列
* 这样设计的棋盘，所有皇后必定不在同一行，于是行冲突就不存在了
* date  : 2011-08-03 
* author: liuzhiwei
* 以下是运行示例(以4皇后为例)：
* zippo@MacBook-Pro datastruct$ ./eightQueen
* Solution 1 :
* . # . .
* . . . #
* # . . .
* . . # .
* (0, 1) (1, 3) (2, 0) (3, 2)
* --------------------------------
*  Solution 2 :
*  . . # .
*  # . . .
*  . . . #
*  . # . .
*  (0, 2) (1, 0) (2, 3) (3, 1)
*  --------------------------------
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QUEEN 8     //皇后的数目
#define INITIAL -10000   //棋盘的初始值

int a[QUEEN];    //一维数组表示棋盘

void init()  //对棋盘进行初始化
{
    int *p;
    for (p = a; p < a + QUEEN; ++p) 
    {
        *p = INITIAL;
    }
} 

int valid(int row, int col)    //判断第row行第col列是否可以放置皇后
{
    int i;
    for (i = 0; i < QUEEN; ++i)   //对棋盘进行扫描
    {
        if (a[i] == col || abs(i - row) == abs(a[i] - col))   //判断列冲突与斜线上的冲突
            return 0;
    }
    return 1;
} 

void print()    //打印输出N皇后的一组解
{
    int i, j;
    for (i = 0; i < QUEEN; ++i)
    {
        for (j = 0; j < QUEEN; ++j)
        {
            if (a[i] != j)      //a[i]为初始值
                printf("%c ", '.');
            else                //a[i]表示在第i行的第a[i]列可以放置皇后
                printf("%c ", '#');
        }
        printf("\n");
    }
    for (i = 0; i < QUEEN; ++i)
        printf("(%d, %d) ", i, a[i]);
    printf("\n");
    printf("--------------------------------\n");
}

void queen()      //N皇后程序
{
    int n = 0;
    int i = 0, j = 0;
    while (i < QUEEN)
    {
        while (j < QUEEN)        //对i行的每一列进行探测，看是否可以放置皇后
        {
            if(valid(i, j))      //该位置可以放置皇后
            {
                a[i] = j;        //第i行放置皇后
                j = 0;           //第i行放置皇后以后，需要继续探测下一行的皇后位置，所以此处将j清零，从下一行的第0列开始逐列探测
                break;
            }
            else
            {
                ++j;             //继续探测下一列
            }
        }
        if(a[i] == INITIAL)         //第i行没有找到可以放置皇后的位置
        {
            if (i == 0)             //回溯到第一行，仍然无法找到可以放置皇后的位置，则说明已经找到所有的解，程序终止
                break;
            else                    //没有找到可以放置皇后的列，此时就应该回溯
            {
                --i;
                j = a[i] + 1;        //把上一行皇后的位置往后移一列
                a[i] = INITIAL;      //把上一行皇后的位置清除，重新探测
                continue;
            }
        }
        if (i == QUEEN - 1)          //最后一行找到了一个皇后位置，说明找到一个结果，打印出来
        {
            printf("Solution %d : \n", ++n);
            print();
            //不能在此处结束程序，因为我们要找的是N皇后问题的所有解，此时应该清除该行的皇后，从当前放置皇后列数的下一列继续探测。
            //_sleep(600);
            j = a[i] + 1;             //从最后一行放置皇后列数的下一列继续探测
            a[i] = INITIAL;           //清除最后一行的皇后位置
            continue;
        }
        ++i;              //继续探测下一行的皇后位置
    }
}

int main(void)
{
    init();
    queen();
    return 0;
}
