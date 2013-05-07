#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "graph.h"

//邻接链表表示法
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

int locVertex(vertextype *graph, datatype v)
{
    int k;
    for(k = 0; k < MAX; k++)
    {
        if(graph[k].vertex == v)
            return k;
    }
    return -1;
}


//邻接矩阵表示法
//
//
//
int locPoint(graphtype *graph, nametype v)
{
    int k;
    for(k = 0; k < MAX; k++)
    {
        if(graph->points[k].name == v)
            return k;
    }
    return -1;
}


graphtype * createGraphMatrix(int n, int e)
{
    graphtype *ga = (graphtype *) malloc (sizeof(graphtype));
    //graphtype *ga;
    int i, j, k, w;
    char tmp;
    for(i = 0; i < n; i++)
    {
        /* 两种去除标准输入流中的空格示例，可忽略 
        while ((tmp = getchar()) == ' ');
        for(;(tmp = getchar()) == ' ';);
        */
        //scanf("%c", &ga->points[i].name);
        printf("请第[%d]个顶点的名称:", i + 1);
        while(isspace(tmp = getchar()));
        ga->points[i].name = tmp;
        //printf("%c\n", ga->points[i].name);
        while((tmp = getchar()) != '\n');
    }
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            ga->edges[i][j].weight = INF;
    for(k = 0; k < e; k++)
    {
        printf("请输入第[%d]条边及其权值(v1 v2 w):", k + 1);
        scanf("%d%d%d", &i, &j, &w);
        ga->edges[i-1][j-1].weight = w;
        ga->edges[j-1][i-1].weight = w;
    }
    return ga;
}

//生成一个固定邻接矩阵用于测试
graphtype * createGraphMatrix2(int n, int e)
{
    int i, j;
    graphtype *ga = (graphtype *) malloc (sizeof(graphtype));
    for(i = 0; i < n; i++)
        ga->points[i].name = i + 1;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            ga->edges[i][j].weight = INF;
        }
    }
    genEdge(ga,1,3,4 );
    genEdge(ga,1,2,2 );
    genEdge(ga,1,4,1 );
    genEdge(ga,3,4,2 );
    genEdge(ga,4,5,7 );
    genEdge(ga,2,5,10 );
    genEdge(ga,3,6,5 );
    genEdge(ga,6,7,1 );
    genEdge(ga,4,7,4 );
    genEdge(ga,7,5,6 );
    return ga;
}

void genEdge(graphtype *ga, int i, int j, int w)
{
    ga->edges[i-1][j-1].weight = w;
    ga->edges[j-1][i-1].weight = w;
}

