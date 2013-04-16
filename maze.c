/*
迷宫问题
提供两种绘制迷宫的函数：
drawMaze()为手工输入方式；
drawMaze2()为固定迷宫方式
找到出路后会用2来标记路径
@招牌疯子
2012.4.15
*/

#include <stdio.h>

#define MAX 10
#define STEP MAX*MAX

typedef struct
{
    int vert;
    int horiz;
}offset;
offset move[4];

typedef struct
{
    int top;
    int d1[STEP];
    int d2[STEP];
    int dir[STEP];
}stack;

void drawMaze(int *p, int row, int col)
{
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(i==0 || i==row-1 || j==0 || j==col-1)
            {
                p[i*col+j]=1;
            }
            else
            {
                int tmp=0;
                scanf("%d", &tmp);
                p[i*col+j]=tmp;
            }
        }
    }
}

void drawMaze2(int *p, int row, int col)
{
    int i, j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(i==0 || i==row-1 || j==0 || j==col-1)
                p[i*col+j]=1;
        }
    }
    addMaze(p,col,1,1,0);
    addMaze(p,col,1,2,1);
    addMaze(p,col,1,3,0);
    addMaze(p,col,1,4,0);
    addMaze(p,col,1,5,0);
    addMaze(p,col,2,1,0);
    addMaze(p,col,2,2,1);
    addMaze(p,col,2,3,0);
    addMaze(p,col,2,4,1);
    addMaze(p,col,2,5,1);
    addMaze(p,col,3,1,0);
    addMaze(p,col,3,2,0);
    addMaze(p,col,3,3,0);
    addMaze(p,col,3,4,1);
    addMaze(p,col,3,5,0);
    addMaze(p,col,4,1,0);
    addMaze(p,col,4,2,1);
    addMaze(p,col,4,3,0);
    addMaze(p,col,4,4,0);
    addMaze(p,col,4,5,0);
    addMaze(p,col,5,1,0);
    addMaze(p,col,5,2,1);
    addMaze(p,col,5,3,0);
    addMaze(p,col,5,4,1);
    addMaze(p,col,5,5,0);
}

void addMaze(int *p, int col, int i, int j, int var)
{
    p[i*col+j] = var;
}

void printMaze(int *p, int row, int col)
{
    int i,j;
    printf("=============Maze(%d,%d)==============\n", row-2, col-2);
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(i==0 || i==row-1 || j==0 || j==col-1)
            {
                continue;
            }
            else
                printf("%d ", p[i*col+j]);
        }
        printf("\n");
    }
}

void pop(stack *s, int *x, int *y, int *d)
{
    if(s->top<0)
    {
        printf("UNDERFLOW!\n");
        exit(1);
    }
    else
    {
        *x=s->d1[s->top];
        *y=s->d2[s->top];
        *d=s->dir[s->top];
        s->top--;
    }
}

void push(stack *s, int x, int y, int d)
{
    if(s->top>STEP-1)
    {
        printf("OVERFLOW!\n");
        exit(1);
    }
    else
    {
        s->top++;
        s->d1[s->top]=x;
        s->d2[s->top]=y;
        s->dir[s->top]=d;
    }
}

void path(int *maze, int row, int col)
{
    stack *s = (stack *)malloc(sizeof(stack));
    int i, j, m, n, d, k;
    k=0;
    maze[8]=2;
    s->top = -1;
    push(s, 1, 1, 0);
    while(s->top > -1)
    {
        pop(s, &i, &j, &d);
        while(d<4)
        {
            m=i+move[d].vert;
            n=j+move[d].horiz;
            if(maze[m*col+n] == 0)
            {
                //printMaze(maze, row, col);
                maze[m*col+n]=2;
                if(m == row-2 && n == col-2)
                {
                    k++;
                    printf("===========After Calculate==========\n");
                    printMaze(maze, row, col);
                    d=9;
                    return;
                }
                else
                {
                    push(s, i, j, d+1);
                    i=m;
                    j=n;
                    d=0;
                }
            }
            else
            {
                d++;
            }
        }
        maze[i*col+j]=0;
    }
    printf("Result: %d ways found to out of this maze.\n", k);
}

int main()
{
    //定义上下左右的游标，由于规定入口为左上角(1,1)，出口(5,5)，故设定移动优先级为左-下-右-上
    move[0].vert=0;
    move[1].vert=1;
    move[2].vert=0;
    move[3].vert=-1;
    move[0].horiz=1;
    move[1].horiz=0;
    move[2].horiz=-1;
    move[3].horiz=0;
    int row, col;
    row=col=7;
    int maze[MAX][MAX];
    int *p=&maze[0][0];
    //drawMaze(p, row, col); //手动输入方式绘制
    drawMaze2(p, row, col); //固定迷宫方式绘制
    printMaze(p, row, col);
    path(p, row, col);
    //printMaze(p, row, col);
    return 0;
}











