/*
运行结果实例：


zippo@MacBook-Pro datastruct$ ./crucialpath
输入网的顶点个数n和边数e:7 9

输入图的7个顶点数据:
Vertext[0]:1
Vertext[1]:2
Vertext[2]:3
Vertext[3]:4
Vertext[4]:5
Vertext[5]:6
Vertext[6]:7

输入图中9条边(弧尾编号，弧头编号，权值):
Edge[0]:1 2 5
Edge[1]:1 3 7
Edge[2]:2 4 3
Edge[3]:3 4 6
Edge[4]:3 5 3
Edge[5]:4 5 4
Edge[6]:4 6 4
Edge[7]:4 7 4
Edge[8]:5 7 2

Edge        E[i]    L[i]    L-E Is Crucial
--------------------------------------------------------
V1 --> V3   0   0   0   Crucial Activity
V1 --> V2   0   5   5
V2 --> V4   5   10  5
V3 --> V5   7   14  7
V3 --> V4   7   7   0   Crucial Activity
V4 --> V7   13  15  2
V4 --> V6   13  15  2
V4 --> V5   13  13  0   Crucial Activity
V5 --> V7   17  17  0   Crucial Activity
*/


#include <stdio.h>

#define MAX 256

typedef int vextype;

typedef struct node
{
    int adv;
    int dut;
    struct node *next;
}edgenode;

typedef struct
{
    vextype vertex;
    int indgree;
    edgenode *link;
}vexnode;

int locVertex(vexnode *graph, int v);
vexnode * createGraph(int n, int e);
void crucialPath(vexnode *dig, int n);

int main()
{
    int n, e;
    printf("输入网的顶点个数n和边数e:");
    scanf("%d%d", &n, &e);
    vexnode *graph = createGraph(n, e);
    crucialPath(graph, n);
    return 0;
}


int locVertex(vexnode *graph, int v)
{
    int k;
    for(k = 0; k < MAX; k++)
    {
        if(graph[k].vertex == v)
            return k;
    }
    return -1;
}

vexnode * createGraph(int n, int e)
{
    int k, i, j, du;
    vextype c, v1, v2;
    edgenode *p, *q;

    vexnode *graph = (vexnode *) malloc (n * sizeof(vexnode));
    printf("\n输入图的%d个顶点数据:\n", n);
    for(k = 0; k < n; k++)
    {
        printf("Vertext[%d]:", k);
        scanf("%d", &c);
        graph[k].vertex = c;
        graph[k].link = NULL;
    }
    printf("\n输入图中%d条边(弧尾编号，弧头编号，权值):\n", e);
    for(k = 0; k < e; k++)
    {
        printf("Edge[%d]:", k);
        scanf("%d%d%d", &v1, &v2, &du);
        i = locVertex(graph, v1);
        j = locVertex(graph, v2);
        if(i != -1 && j != -1)
        {
            q = (edgenode *) malloc (sizeof(edgenode));
            q -> adv = j;
            q -> dut = du;
            q -> next = graph[i].link;
            graph[i].link = q;
        }
        else
        {
            printf("[%d] 或 [%d] 不是图的顶点.\n", v1, v2);
            k--;
        }
    }
    return graph;
}

void crucialPath(vexnode *dig, int n)
{
    int i, j, m, k;
    int front, rear;
    int tpord[10], VL[10], VE[10];
    int L[MAX], E[MAX];
    edgenode *p;

    front = -1;
    rear = -1;

    for(i = 0; i < n; i++)
    {
        VE[i] = 0;
    }
    for(i = 0; i < n; i++)
    {
        if(dig[i].indgree == 0)
            tpord[++rear] = i;
    }
    m = 0;

    while(front != rear)
    {
        front++;
        j = tpord[front];
        m++;
        p = dig[j].link;

        while(p)
        {
            k = p->adv;
            dig[k].indgree--;
            if(VE[j] + p->dut > VE[k])
                VE[k] = VE[j] + p->dut;
            if(dig[k].indgree == 0)
            {
                tpord[++rear] = k;
            }
            p = p->next;
        }
    }

    if(m < n)
    {
        printf("\nThe network has a cycle!\n");
        exit(1);
    }
    for(i = 0; i < n; i++)
        VL[i] = VE[n-1];

    for(i = n - 2; i >= 0; i--)
    {
        j = tpord[i];
        p = dig[j].link;
        while(p)
        {
            k = p->adv;
            if(VL[k] - p->dut < VL[j])
                VL[j] = VL[k] - p->dut;
            p = p->next;
        }
    }
    i = 0;
    printf("\nEdge\t\tE[i]\tL[i]\tL-E\tIs Crucial\n");
    printf("--------------------------------------------------------\n");
    for(j = 0; j < n; j++)
    {
        p = dig[j].link;
        while(p)
        {
            k = p->adv;
            E[++i] = VE[j];
            L[i] = VL[k] - p->dut;
            printf("V%d --> V%d\t%d\t%d\t%d\t", dig[j].vertex, dig[k].vertex, E[i], L[i], L[i] - E[i]);
            if(L[i] == E[i])
                printf("Crucial Activity");
            printf("\n");
            p = p->next;
        }
    }
}



