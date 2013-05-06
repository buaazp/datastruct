#include <stdio.h>

#define datatype int
#define nametype char
#define MAX 100
#define INF 999999

//邻接链表表示法
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

int locVertex(vertextype *ga, datatype v);
void printGraph(vertextype *ga, int n);
vertextype* createGraph(int n, int e);

//邻接矩阵表示法
typedef struct
{
    nametype name;
}pointype;

typedef struct
{
    int weight;
}edgetype;

typedef struct
{
    pointype points[MAX];
    edgetype edges[MAX][MAX];
}graphtype;

graphtype* createGraphMatrix(int n, int e);
int locPoint(graphtype *graph, nametype v);

graphtype * createGraphMatrix2(int n, int e);
void genEdge(graphtype *ga, int i, int j, int w);





