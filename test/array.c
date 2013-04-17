#include <stdio.h>

#define M 6
#define N 5

//int score[M][N] = {(100,90,80,70,60,50),(90,80,70,60,50),(60,60,60,60,60),(90,90,90,90,90),(80,70,80,70,70),(100,100,100,100,100)};

int stuScore(int score[], int i)
{
    int j, stuSum;
    stuSum = 0;
    for(j = 0; j < N; j++)
    {
        printf("score[%d]=%d ", i*N+j, score[i * N + j]);
        stuSum = stuSum + score[i * N + j];
    }
    printf("\n");
    return (stuSum);
}

int courseTotal(int score[], int j)
{
    int i, courseSum;
    courseSum = 0;
    for(i = 0; i < M; i++)
    {
        printf("score[%d]=%d ", i*N+j, score[i * N + j]);
        courseSum = courseSum + score[i * N + j];
    }
    printf("\n");
    return courseSum;
}

void printArray(int array[])
{
    int i, j;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("array[%d][%d] = %d ", i, j, array[i*N+j]);
        }
        printf("\n");
    }
}
int main()
{
    int score[M][N] = {{100,90,80,70,60},{90,80,70,60,50},{60,60,60,60,60},{90,90,90,90,90},{80,70,80,70,70},{100,100,100,100,100}};
    printArray(score);
    while(1)
    {
        int stuSum, courseSum;
        int *i = (int *)malloc(sizeof(int));
        printf("i = ");
        scanf("%d", i);
        stuSum = stuScore(score, *i-1);
        printf("stu[%d].score = %d.\n", *i-1, stuSum);
        int *j;
        printf("j = ");
        scanf("%d", i);
        courseSum = courseTotal(score, *i-1);
        printf("course[%d].score = %d.\n", *i-1, courseSum);
    }
    return 0;
}
