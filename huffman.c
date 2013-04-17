#include <stdio.h>

#define MAX 256

typedef struct
{
    unsigned int weight;
    unsigned int parent;
    unsigned int lchild;
    unsigned int rchild;
}huffmTree;

typedef char **huffmCode;

typedef struct
{
    unsigned ch;
    unsigned long fr;
}wd;

void select(huffmTree *HT, int i, int *s1, int *s2);
void displayHuffm(huffmCode HC, int n);

huffmCode huffmanCoding(huffmTree *HT, huffmCode HC, wd w[MAX], int n)
{
    int m,i,j,s1,s2,l,k,start,f,cdlen;
    char *cd;
    if(n <= 1)
        return;
    m = 2 * n - 1;
    HT = (huffmTree *) malloc ((m + 1) * sizeof(huffmTree));
    for(i = 1; i <= n; i++)
    {
        HT[i].weight = w[i-1].fr;
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for(;i<=m;i++)
    {
        HT[i].weight = 0;
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for(i = n+1; i <= m; i++)
    {
        select(HT, i-1, &s1, &s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    HC = (huffmCode) malloc ((n + 1) * sizeof(char *));
    cd = (char *) malloc (n * sizeof(char));
    cd[n - 1] = '\0';
    for(i = 1; i <= n; i++)
    {
        start = n - 1;
        k = i;
        f = HT[k].parent;
        do
        {
            if(HT[f].lchild == k)
                cd[--start] = '0';
            else
                cd[--start] = '1';
            k = f;
            f = HT[f].parent;
        }while(f != 0);
        for(j = start - 1; j >= 0; j--)
        {
            cd[j] = ' ';
        }
        HC[i] = (char *) malloc ((n - start) * sizeof(char));
        m = 0;
        for(j = 0; j < n; j++)
        {
            if((cd[j] == '0') || (cd[j] == '1') || (cd[j] == '\0'))
            {
                HC[i][m] = cd[j];
                m++;
            }
            else
                continue;
        }
    }
    free(cd);
    return HC;
}

void select(huffmTree *HT, int n, int *s1, int *s2)
{
    int j;
    unsigned long min1, min2;
    min1 = 65535;

    for(j = 1; j <= n; j++)
    {
        if((min1 > HT[j].weight) && (HT[j].parent == 0))
        {
            min1 = HT[j].weight;
            *s1 = j;
        }
    }
    min2 = 65535;
    for(j = 1; j <= n; j++)
    {
        if((min2 > HT[j].weight) && (j != *s1) && (HT[j].parent == 0))
        {
            min2 = HT[j].weight;
            *s2 = j;
        }
    }
}

void displayHuffm(huffmCode HC, int n)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        printf("%s\n", HC[i]);
    }
}


int main()
{
    int n = 5;
    //wd w[5] = (wd *) malloc (n * sizeof(wd));
    wd w[5];
    w[0].ch = 'a';
    w[0].fr = 5;
    w[1].ch = 'b';
    w[1].fr = 4;
    w[2].ch = 'c';
    w[2].fr = 3;
    w[3].ch = 'd';
    w[3].fr = 2;
    w[4].ch = 'e';
    w[4].fr = 1;
    huffmTree *HT;
    huffmCode HC;
    HC = huffmanCoding(HT, HC, w, n);
    displayHuffm(HC, n);
    return 0;
}










