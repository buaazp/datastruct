#include <stdio.h>
#include "graph.h"

int main()
{
    int n, e;
    vertextype *graph;

    printf("\n输入图的顶点个数n和边数e:");
    scanf("%d%d", &n, &e);
    graph = createGraph(n, e);

    printGraph(graph, n);

    return 0;
}

