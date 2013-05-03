#include <stdio.h>
#include "graph.h"

vertextype* createGraph(int n, int e)
{
    int k, i, j;
    datatype c, v1, v2;
    arctype *p, *q;
    
    vertextype *graph = (vertextype *) malloc (MAX * sizeof(vertextype));
    printf("\n输入图的%d个顶点数据:\n", n);
    for(k = 0; k < n; k++)
    {
        printf("Vertext[%d]:", k);
        scanf("%d", &c);
        graph[k].vertex = c;
        graph[k].firstarc = NULL;
        graph[k].lastarc = NULL;
    }
    printf("\n输入图中%d条边(弧尾编号，弧头编号):\n", e);
    for(k = 0; k < e; k++)
    {
        printf("Edge[%d]:", k);
        scanf("%d%d", &v1, &v2);
        i = locVertex(graph, v1);
        j = locVertex(graph, v2);
        if(i != -1 && j != -1)
        {
            q = (arctype *) malloc (sizeof(arctype));
            q -> adv = j;
            q -> nextarc = graph[i].firstarc;
            graph[i].firstarc = q;
            p = (arctype *) malloc (sizeof(arctype));
            p -> adv = i;
            p -> nextarc = graph[j].lastarc;
            graph[j].lastarc = p;
        }
        else
        {
            printf("[%d] 或 [%d] 不是图的顶点.\n", v1, v2);
            k--;
        }
    }
    return &graph[0];
}


void printGraph(vertextype *graph, int n)
{
    int i, v1, v2;
    arctype *p;
    printf("\n图的邻接表结构为:\n");
    for(i = 0; i < n; i++)
    {
        v1 = graph[i].vertex;
        printf("Vertex:%d-->", v1);
        p = graph[i].firstarc;
        if(!p)
            printf("^");
        while(p != NULL)
        {
            v2 = p -> adv + 1;
            printf("%d", v2);
            p = p -> nextarc;
            if(p)
                printf("-->");
        }
        printf("\n");
    }
    printf("\n图的逆序邻接表结构为:\n");
    for(i = 0; i < n; i++)
    {
        v1 = graph[i].vertex;
        printf("Vertex:%d-->", v1);
        p = graph[i].lastarc;
        if(!p)
            printf("^");
        while(p != NULL)
        {
            v2 = p -> adv + 1;
            printf("%d", v2);
            p = p -> nextarc;
            if(p)
                printf("-->");
        }
        printf("\n");
    }
}

int locVertex(vertextype *graph, int v)
{
    int k;
    for(k = 0; k < MAX; k++)
    {
        if(graph[k].vertex == v)
            return k;
    }
    return -1;
}










