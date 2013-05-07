#include <stdio.h>
#include "graph.h"

void bfs(vertextype *graph, int v, int n)
{
    arctype *p;
    int queue[MAX], front = 0, rear = 0;
    int visited[MAX];
    int w, i;
    for(i = 0; i < n; i++)
        visited[i] = 0;
    visited[v] = 1;
    printf("%5d", graph[v].vertex);
    rear = (rear + 1) % MAX;
    queue[rear] = v;
    while(front != rear)
    {
        front = (front + 1) % MAX;
        w = queue[front];
        p = graph[w].firstarc;
        while(p != NULL)
        {
            if(visited[p->adv] == 0)
            {
                visited[p->adv] = 1;
                printf("%5d", graph[p->adv].vertex);
                rear = (rear + 1) % MAX;
                queue[rear] = p->adv;
            }
            p = p->nextarc;
        }
    }
    printf("\n");
}

int main()
{
    int n, e, i;
    vertextype *graph;

    printf("\n输入图的顶点个数n和边数e:");
    scanf("%d%d", &n, &e);
    graph = createGraph(n, e);

    printGraph(graph, n);
    printf("\n图的广度遍历顺序为:\n");
    bfs(graph, 0, n);

    return 0;
}







