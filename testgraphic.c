/*
 * 与图相关的所有方法汇总与一个头文件中方便调用
 * 保留以前所写的单体代码
 * 以下是运行示例：
 *
 * zippo@MacBook-Pro datastruct$ ./testgraphtype
 * …………创建无向图…………
 * 请输入图G顶点和弧的个数(n e):3 2
 * 输入顶点[0]:a
 * 输入顶点[1]:b
 * 输入顶点[2]:c
 * 输入边[0]依附的顶点和权(v1 v2 w):a b 3
 * 输入边[1]依附的顶点和权(v1 v2 w):a c 2
 * 图G邻接矩阵创建成功！
 * 图G邻接表创建成功！
 * 邻接矩阵表示：
 * 10000 3 2
 * 3 10000 10000
 * 2 10000 10000
 * 邻接表表示：
 * 0->2->1->^
 * 1->0->^
 * 2->0->^
 * 广度优先遍历：
 * a->c->b->^
 * 深度优先遍历
 * a->c->b->^
 * Prim生成树：
 * (0,2)2
 * (0,1)3
 * Kruscal生成树：
 * (0,2)2
 * (0,1)3
 *
 */

#include <stdio.h>
#include "graphtype.h"

int main()
{
    algraph gra;
    MGraph_L G;
    int i, j, d, g[max][max];
    char a = 'a';
    d = creatMGraph_L(&G);
    if (d > 0)
    {
        creatadj(&gra, G);
        printf("邻接矩阵表示：\n");
        printMatrix(G);
        printf("邻接表表示：\n");
        printAlList(gra);
        printf("广度优先遍历：\n");
        bfstra(gra);
        printf("深度优先遍历\n");
        dfstra(gra);
        printf("Prim生成树：\n");
        for (i = 0; i != G.vexnum; ++i)
            for (j = 0; j != G.vexnum; ++j)
                g[i + 1][j + 1] = G.arcs[i][j].adj;
        prim(g, d);
        printf("Kruscal生成树：\n");
        kruscal_arc(G, gra);
    }
    else
        printf("图G构建失败！\n");

    return 0;
}
