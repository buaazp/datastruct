#include <stdio.h>

#define MAX 20
#define MAXCOST 99999

int miniDistance[MAX];
int cost [MAX][MAX];
int path [MAX];         //新建一个数组用于依次记录距离最短的顶点，方便显示结果

void initCost();
void dijkstra(int n, int v0)
{
    int s[MAX];
    int mindis, dis;
    int i, j, u, index;

    for(i = 0; i < n; i++)
    {
        miniDistance[i] = cost[v0][i];
        s[i] = 0;
    }
    s[v0] = 1;
    index = 0;
    for(i = 1; i < n; i++)
    {
        mindis = MAXCOST;
        for(j = 0; j < n; j++)
        {
            if(s[j] == 0 && miniDistance[j] < mindis)
            {
                u = j;
                mindis = miniDistance[j];
            }
        }
        path[index++] = u;
        s[u] = 1;
        for(j = 0; j < n; j++)
        {
            if(s[j] ==  0)
            {
                dis = miniDistance[u] + cost[u][j];
                if(miniDistance[j] > dis)
                    miniDistance[j] = dis;
            }
        }
    }
}

//方便起见此处写定了一个有向图，如果想要运行时输入请参考graph.c中的相关函数
void initCost()
{
    int i, j;
    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 7; j++)
            cost[i][j] = MAXCOST;
    }
    //cost = { MAXCOST,13,8,MAXCOST,30,MAXCOST,32,  MAXCOST,MAXCOST,MAXCOST,MAXCOST,MAXCOST,9,MAXCOST,  MAXCOST,MAXCOST,MAXCOST,5,MAXCOST,MAXCOST,MAXCOST,  MAXCOST,MAXCOST,MAXCOST,MAXCOST,6,MAXCOST,MAXCOST,  MAXCOST,MAXCOST,MAXCOST,MAXCOST,MAXCOST,2,MAXCOST,  MAXCOST,MAXCOST,MAXCOST,MAXCOST,MAXCOST,MAXCOST,MAXCOST,  MAXCOST,MAXCOST,MAXCOST,MAXCOST,MAXCOST,17,MAXCOST };
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

int main()
{
    int i, j, n, v0, v;
    n = 7;
    initCost();
    printf("Input v0(-1 for quit): ");
    scanf("%d", &v0);
    v = v0 - 1;
    while(v != -2)
    {
        for(i = 0; i < n; i++)
            path[i] = -1;
        dijkstra(n, v);
        for(i = 0; i < n; i++)
        {
            if(i != v)
            {
                if(miniDistance[i] < MAXCOST)
                {
                    printf("DIST[%d, %d]=%d\n", v0, i+1, miniDistance[i]);
                    //输出最短路径所经过的顶点
                    printf("    V%d --> ", v0);
                    for(j = 0; path[j] != i; j++)
                    {
                        printf("V%d", path[j]+1);
                        if(path[j+1] != i)
                            printf(" --> ");
                    }
                    if(path[0] == i)
                        printf("V%d", i+1);
                    else
                        printf(" --> V%d", i+1);
                    printf("\n");
                }
                else
                {
                    printf("DIST[%d, %d]=NONE!\n", v0, i+1, miniDistance[i]);
                }
            }
        }
        printf("\nInput v0(-1 for quit): ");
        scanf("%d", &v0);
        v = v0 - 1;
    }
}
