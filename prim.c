/*
 * 最小生成树的prim算法
 * 复杂度只与顶点数有关
 * 适用于边比较多的图
 * 以下是运行示例：
 * zippo@MacBook-Pro datastruct$ ./prim
 * 输入图的顶点数n和边数e:7 10
 * 请第[1]个顶点的名称:1
 * 请第[2]个顶点的名称:2
 * 请第[3]个顶点的名称:3
 * 请第[4]个顶点的名称:4
 * 请第[5]个顶点的名称:5
 * 请第[6]个顶点的名称:6
 * 请第[7]个顶点的名称:7
 * 请输入第[1]条边及其权值(v1 v2 w):1 3 4
 * 请输入第[2]条边及其权值(v1 v2 w):1 2 2
 * 请输入第[3]条边及其权值(v1 v2 w):1 4 1
 * 请输入第[4]条边及其权值(v1 v2 w):3 4 2
 * 请输入第[5]条边及其权值(v1 v2 w):4 5 7
 * 请输入第[6]条边及其权值(v1 v2 w):2 5 10
 * 请输入第[7]条边及其权值(v1 v2 w):3 6 5
 * 请输入第[8]条边及其权值(v1 v2 w):6 7 1
 * 请输入第[9]条边及其权值(v1 v2 w):4 7 4
 * 请输入第[10]条边及其权值(v1 v2 w):7 5 6
 * <1>- 1 -<4>- 2 -<2>- 2 -<3>- 4 -<7>- 1 -<6>- 6 -<5>
 *
 */

#include <stdio.h>
#include "graph.h"

#define maxnode 256

void prim(graphtype *ga, int n, int v)
{
    int i, j, k, min;
    int pointset[maxnode];
    int lowcost[maxnode];
    for(i = 0; i < n; i++)
    {
        pointset[i] = 0;
        lowcost[i] = ga->edges[v][i].weight;
    }
    pointset[v] = 1;
    printf("<%d>", v + 1);
    for(i = 1; i < n; i++)
    {
        min = INF;
        for(j = 0; j < n; j++)
        {
            if(pointset[j] == 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
        }
        pointset[k] = 1;
        printf("- %d -", min);
        v = k;
        printf("<%d>", v + 1);
        for(j = 0; j < n; j++)
        {
            if(pointset[j] == 0 && ga->edges[v][j].weight < lowcost[j])
            {
                lowcost[j] = ga->edges[v][j].weight;
            }
        }
    }
    printf("\n", min);
}

int main()
{
    int n, e;
    printf("输入图的顶点数n和边数e:");
    scanf("%d%d", &n, &e);
    graphtype *ga = createGraphMatrix(n, e);
    prim(ga, n, 0);
    return 0;
}
