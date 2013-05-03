#include <stdio.h>
#include "graph.h"

void depthTraver(vertextype *graph, int n)
{
    int v;
    int visited[MAX];
    for(v = 0; v < n; v++)
        visited[v] = 0;
    for(v = 0; v < n; v++)
    {
        if(visited[v] == 0)
            dfs(graph, v, visited);
    }
}

void dfs(vertextype *graph, int v, int visited[])
{
    arctype *p;
    int w;
    visited[v] = 1;
    printf("%5d", graph[v].vertex);
    p = graph[v].firstarc;
    //w = p->adv;
    while(p != NULL)
    {
        w = p->adv;
        if(visited[w] == 0)
            dfs(graph, w, visited);
        p = p->nextarc;
    }
}

int main()
{
    int n, e;
    vertextype *graph;

    printf("\n输入图的顶点个数n和边数e:");
    scanf("%d%d", &n, &e);
    graph = createGraph(n, e);

    printGraph(graph, n);
    printf("\n图的深度遍历顺序为:\n");
    depthTraver(graph, n);
    printf("\n");

    return 0;
}







