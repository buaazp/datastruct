#include <stdio.h>

#define MAX 256
#define MAXCOST 99999

int cost [MAX][MAX];
int weight [MAX][MAX];
int path [MAX][MAX];

//方便起见此处写定了一个有向图，如果想要运行时输入请参考graph.c中的相关函数
void initCost()
{
    int i, j;
    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 7; j++)
        {
            if(i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = MAXCOST;
        }
    }
    cost[0][1]=13;
    cost[0][2]=8;
    cost[0][4]=30;
    cost[0][6]=32;
    cost[1][5]=9;
    cost[2][3]=5;
    cost[3][4]=6;
    cost[4][5]=2;
    cost[6][5]=17;
}


void floyd(int n)
{
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            weight[i][j] = cost[i][j];
            path[i][j] = 0;
        }
    }
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(weight[i][j] > (weight[i][k] + weight[k][j]))
                {
                    weight[i][j] = weight[i][k] + weight[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}


int main()
{
    int i, j, wt, k, n, top;
    int stack[MAX];
    n = 7;
    for(i = 0; i < n; i++)
    {
        stack[i] = -1;
    }
    initCost();
    floyd(n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            wt = weight[i][j];
            if( i != j && wt != MAXCOST)
            {
                printf("DIST(V%d,V%d)=%d\n", i+1, j+1, wt);
                //采用栈来输出最短路径所经过的顶点
                k = j;
                if(path[i][k] != 0)
                {
                    top = -1;
                    while(path[i][k] != 0)
                    {
                        stack[++top] = path[i][k];
                        k = path[i][k];
                    }
                    printf("V%d --> ", i+1);
                    while(top != -1)
                    {
                        printf("V%d", stack[top--]+1);
                        if(top != -1)
                            printf(" --> ");
                    }
                    printf(" --> V%d\n", j+1);
                }
                else
                {
                    printf("V%d --> V%d\n", i+1, j+1);
                }
            }
        }
    }
    return 0;
}










