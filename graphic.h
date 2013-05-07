//图的遍历和生成树求解实现
//（邻接矩阵、邻接表 —图的深度广度遍历算法的实现和最小生成树PRIM和KRUSCAL算法的实现）
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


#define int_max 10000
#define inf 99999
#define max 20

//…………………………………………邻接矩阵定义……………………
typedef struct ArcCell
{
    int adj;
    char *info;
} ArcCell, AdjMatrix[max][max];

typedef struct
{
    char vexs[max];
    AdjMatrix arcs;
    int vexnum, arcnum;
} MGraph_L;

int localvex(MGraph_L G, char v) //返回V的位置
{
    int i;
    for(i = 0; i < G.vexnum; i++)
    {
        if(G.vexs[i] == v)
            return i;
    }
    return -1;
}
//.............邻接链表定义............
typedef struct arcnode//弧结点
{
    int adjvex;//该弧指向的顶点的位置
    struct arcnode *nextarc;//弧尾相同的下一条弧
    char *info;//该弧信息
    int dut;//该弧的度
} arcnode;

typedef struct vnode//邻接链表顶点头接点
{
    char data;//结点信息
    int indgree; //入度
    arcnode *firstarc;//指向第一条依附该结点的弧的指针
} vnode, adjlist;

typedef struct//图的定义
{
    adjlist vertices[max];
    int vexnum, arcnum;
    int kind;
} algraph;

int visited[max];//访问标记

int creatGraph(MGraph_L *G, algraph *ga)//创建图用邻接矩阵表示
{
    char v1, v2, tmp;
    int i, j, k, w;
    int n, e;
    arcnode *p, *q;
    printf("…………创建无向图…………\n请输入图G顶点和弧的个数(n e):");
    // cout << "…………创建无向图…………" << endl << "请输入图G顶点和弧的个数:(4 6)不包括“()”" << endl;
    // cin >> G.vexnum >> G.arcnum;
    scanf("%d%d", &n, &e);
    G->vexnum = n;
    G->arcnum = e;
    ga->vexnum = n;
    ga->arcnum = e;
    for (i = 0; i != n; ++i)
    {
        // cout << "输入顶点" << i << endl;
        // cin >> G.vexs[i];
        printf("输入顶点[%d]:", i);
        tmp = getchar();
        while(isspace(tmp))
        {
            tmp = getchar();
        }
        G->vexs[i] = tmp;
        ga->vertices[i].data = tmp;
        ga->vertices[i].firstarc = NULL;
        while((tmp = getchar()) != '\n');
    }
    for (i = 0; i != G->vexnum; ++i)
        for (j = 0; j != G->vexnum; ++j)
        {
            G->arcs[i][j].adj = int_max;
            G->arcs[i][j].info = NULL;
        }
    for (k = 0; k != G->arcnum; ++k)
    {
        // cout << "输入一条边依附的顶点和权:(a b 3)不包括“()”" << endl;
        printf("输入边[%d]依附的顶点和权(v1 v2 w):", k);
        // cin >> v1 >> v2 >> w; //输入一条边依附的两点及权值


        tmp = getchar();
        while(isspace(tmp))
        {
            tmp = getchar();
        }
        v1 = tmp;
        tmp = getchar();
        while(isspace(tmp))
        {
            tmp = getchar();
        }
        v2 = tmp;
        scanf("%d", &w);


        i = localvex(*G, v1); //确定顶点V1和V2在图中的位置
        j = localvex(*G, v2);
        if(i != -1 && j != -1)
        {
            G->arcs[i][j].adj = w;
            G->arcs[j][i].adj = w;
            q = (arcnode *) malloc (sizeof(arcnode));
            q->adjvex = j;
            q->dut = w;
            q->nextarc = ga->vertices[i].firstarc;
            ga->vertices[i].firstarc = q;
            ga->vertices[j].indgree++;
        }
        else
        {
            printf("[%c] 或 [%c]不是图中的顶点.\n", v1, v2);
            k--;
        }
    }
    // cout << "图G邻接矩阵创建成功！" << endl;
    printf("图G邻接矩阵创建成功！\n");
    printf("图G邻接链表创建成功！\n");
    return G->vexnum;
}

void printMatrix(MGraph_L G) //邻接矩阵的输出
{
    int i, j;
    for (i = 0; i != G.vexnum; ++i)
    {
        for (j = 0; j != G.vexnum; ++j)
            // cout << G.arcs[i][j].adj << " ";
            printf("%d ", G.arcs[i][j].adj);
        // cout << endl;
        printf("\n");
    }
}

/*
//…………………………………………队列定义……………………
typedef struct qnode
{
    int data;
    struct qnode *next;
} qnode, *queueptr;

typedef struct
{
    queueptr front;
    queueptr rear;
} linkqueue;
*/
//………………………………………………………………………
/*
int creatadj(algraph *gra, MGraph_L G) //由已知邻接矩阵创建邻接链表表示图，需要时使用
{
    int i = 0, j = 0;
    arcnode *arc, *tem, *p;
    for (i = 0; i != G.vexnum; ++i)
    {
        gra->vertices[i].data = G.vexs[i];
        gra->vertices[i].indgree = 0;
        gra->vertices[i].firstarc = NULL;
    }
    for (i = 0; i != G.vexnum; ++i)
    {
        for (j = 0; j != G.vexnum; ++j)
        {
            if (gra->vertices[i].firstarc == NULL)
            {
                if (G.arcs[i][j].adj != int_max && j != G.vexnum)
                {
                    arc = (arcnode *)malloc(sizeof(arcnode));
                    arc->adjvex = j;
                    gra->vertices[i].firstarc = arc;
                    arc->nextarc = NULL;
                    p = arc;
                    ++j;
                    while (G.arcs[i][j].adj != int_max && j != G.vexnum)
                    {
                        tem = (arcnode *)malloc(sizeof(arcnode));
                        tem->adjvex = j;
                        gra->vertices[i].firstarc = tem;
                        tem->nextarc = arc;
                        arc = tem;
                        ++j;
                    }
                    --j;
                }
            }
            else
            {
                if (G.arcs[i][j].adj != int_max && j != G.vexnum)
                {
                    arc = (arcnode *)malloc(sizeof(arcnode));
                    arc->adjvex = j;
                    p->nextarc = arc;
                    arc->nextarc = NULL;
                    p = arc;
                }
            }
        }
    }
    gra->vexnum = G.vexnum;
    gra->arcnum = G.arcnum;
    // cout << "图G邻接表创建成功！" << endl;
    printf("图G邻接表创建成功！\n");
    return 1;
}
*/

void printAlList(algraph gra) //邻接表输出
{
    int i;
    for (i = 0; i != gra.vexnum; ++i)
    {
        arcnode *p;
        // cout << i << " ";
        printf("%d(%d)->", i, gra.vertices[i].indgree);
        p = gra.vertices[i].firstarc;
        while (p != NULL)
        {
            // cout << p->adjvex;
            printf("%d->", p->adjvex);
            p = p->nextarc;
        }
        // cout << endl;
        printf("^\n");
    }
}

/*
int firstadjvex(algraph gra, vnode v) //返回依附顶点V的第一个点
//即以V为尾的第一个结点
{
    if (v.firstarc != NULL)
        return v.firstarc->adjvex;
}

int initqueue(linkqueue *q)//初始化队列
{
    q->rear = (queueptr)malloc(sizeof(qnode));
    q->front = q->rear;
    if (!q->front)
        return 0;
    q->front->next = NULL;
    return 1;
}

int enqueue(linkqueue *q, int e) //入队
{
    queueptr p;
    p = (queueptr)malloc(sizeof(qnode));
    if (!p)
        return 0;
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    return 1;
}

int dequeue(linkqueue *q, int *e) //出队
{
    queueptr p;
    if (q->front == q->rear)
        return 0;
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if (q->rear == p)
        q->rear = q->front;
    free(p);
    return 1;
}

int queueempty(linkqueue q)//判断队为空
{
    if (q.front == q.rear) return 1;
    return 0;
}
*/

void bfs(algraph graph, int v)
{
    int n = graph.vexnum;
    arcnode *p;
    int queue[max], front = 0, rear = 0;
    int w, i;
    for(i = 0; i < n; i++)
        visited[i] = 0;
    visited[v] = 1;
    printf("%c->", graph.vertices[v].data);
    rear = (rear + 1) % max;
    queue[rear] = v;
    while(front != rear)
    {
        front = (front + 1) % max;
        w = queue[front];
        p = graph.vertices[w].firstarc;
        while(p != NULL)
        {
            if(visited[p->adjvex] == 0)
            {
                visited[p->adjvex] = 1;
                printf("%c->", graph.vertices[p->adjvex].data);
                rear = (rear + 1) % max;
                queue[rear] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
    printf("^\n");
}

void dfs(algraph graph, int v)
{
    arcnode *p;
    int w;
    visited[v] = 1;
    printf("%c->", graph.vertices[v].data);
    p = graph.vertices[v].firstarc;
    while(p != NULL)
    {
        w = p->adjvex;
        if(visited[w] == 0)
            dfs(graph, w);
        p = p->nextarc;
    }
}

void dfstra(algraph graph)
{
    int v;
    int n = graph.vexnum;
    for(v = 0; v < n; v++)
        visited[v] = 0;
    for(v = 0; v < n; v++)
    {
        if(visited[v] == 0)
            dfs(graph, v);
    }
    printf("^\n");
}

int bfstra_fen(algraph gra)//求连通分量
{
    int i, j;
    for (i = 0; i != gra.vexnum; ++i)
        visited[i] = 0;
    for (j = 0; j != gra.vexnum; ++j)
    {
        if (visited[j] == 0)
        {
            dfs(gra, j);
            // cout << endl;
            printf("\n");
        }
    }
    return 0;
}

int prim(int g[][max], int n) //最小生成树PRIM算法
{
    int lowcost[max], prevex[max]; //LOWCOST[]存储当前集合U分别到剩余结点的最短路径
    //prevex[]存储最短路径在U中的结点
    int i, j, k, min;
    for (i = 2; i <= n; i++) //n个顶点，n-1条边
    {
        lowcost[i] = g[1][i]; //初始化
        prevex[i] = 1; //顶点未加入到最小生成树中
    }
    lowcost[1] = 0; //标志顶点1加入U集合
    for (i = 2; i <= n; i++) //形成n-1条边的生成树
    {
        min = inf;
        k = 0;
        for (j = 2; j <= n; j++) //寻找满足边的一个顶点在U,另一个顶点在V的最小边
            if ((lowcost[j] < min) && (lowcost[j] != 0))
            {
                min = lowcost[j];
                k = j;
            }
        printf("(%d,%d)%d\t", prevex[k] - 1, k - 1, min);
        lowcost[k] = 0; //顶点k加入U
        for (j = 2; j <= n; j++) //修改由顶点k到其他顶点边的权值
            if (g[k][j] < lowcost[j])
            {
                lowcost[j] = g[k][j];
                prevex[j] = k;
            }
        printf("\n");
    }
    return 0;
}

int acrvisited[100];//kruscal弧标记数组
typedef struct acr
{
    int pre;//弧的一结点
    int bak;//弧另一结点
    int weight;//弧的权
}edg;

int find(int acrvisited[], int f)
{
    while (acrvisited[f] > 0)
        f = acrvisited[f];
    return f;
}

void kruscal_arc(MGraph_L G, algraph gra)
{
    edg edgs[max];
    int i, j, k = 0;
    for (i = 0; i != G.vexnum; ++i)
        for (j = i; j != G.vexnum; ++j)
        {
            if (G.arcs[i][j].adj != int_max)
            {
                edgs[k].pre = i;
                edgs[k].bak = j;
                edgs[k].weight = G.arcs[i][j].adj;
                ++k;
            }
        }
    int x, y, m, n;
    int buf, edf;
    for (i = 0; i != gra.arcnum; ++i)
        acrvisited[i] = 0;
    for (j = 0; j != G.arcnum; ++j)
    {
        m = int_max;
        for (i = 0; i != G.arcnum; ++i)
        {
            if (edgs[i].weight < m)
            {
                m = edgs[i].weight;
                x = edgs[i].pre;
                y = edgs[i].bak;
                n = i;
            }

        }
        buf = find(acrvisited, x);
        edf = find(acrvisited, y);
        edgs[n].weight = int_max;
        if (buf != edf)
        {
            acrvisited[buf] = edf;
            // cout << "(" << x << "," << y << ")" << m;
            // cout << endl;
            printf("(%d,%d)%d\n", x, y, m);
        }
    }
}

void toposort(algraph ga)
{
    int i, j, k, m, n, top;
    n = ga.vexnum;
    arcnode *p;
    m = 0;
    top = -1;
    for(i = 0; i < n; i++)
    {
        if(ga.vertices[i].indgree == 0)
        {
            ga.vertices[i].indgree = top; //入度为零的顶点如栈，栈没有实体数组而是用indgree这个成员量来存储，简直屌爆了！
            top = i;
        }
    }
    while(top != -1)
    {
        j = top;
        top = ga.vertices[top].indgree; //出栈，输出第一个入度为零的顶点
        printf("%c->", ga.vertices[j].data);
        m++;
        p = ga.vertices[j].firstarc;
        while(p)
        {
            k = p->adjvex;
            ga.vertices[k].indgree--;
            if(ga.vertices[k].indgree == 0)
            {
                ga.vertices[k].indgree = top;
                top = k;
            }
            p = p->nextarc;
        }
    }
    if(m < n)
        printf("\n该图中存在环!\n");
    else
        printf("^\n");
}






