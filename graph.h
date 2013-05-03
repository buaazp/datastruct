#include <stdio.h>

#define datatype int
#define MAX 100

//邻接表结点
typedef struct arc
{
    int adv; //顶点序号
    struct arc *nextarc;
}arctype;

//顶点
typedef struct
{
    datatype vertex;
    arctype *firstarc;
    arctype *lastarc;
}vertextype;

int locVertex(vertextype *graph, int v);
void printGraph(vertextype *graph, int n);
vertextype* createGraph(int n, int e);

