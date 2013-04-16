#include <stdio.h>

#define MAX 256

int next[MAX];

/*第一种计算模式值的算法，效率最高，其next[n]的意义为：
 * 1.next[n]=-1 表示S[m]和T[0]间接比较过了，不相等，下一次比较 S[m+1] 和T[0]
 * 2.next[n]=0 表示比较过程中产生了不相等，下一次比较 S[m] 和T[0]
 * 3.next[n]=k>0 但k<n, 表示,S[m]的前k个字符与T中的开始k个字符已经间接比较相等了，下一次比较S[m]和T[k]是否相等
 */
void calNext(char *t)
{
    int j, k;
    k = -1;
    j = 0;
    next[0] = -1;
    while(t[j] != '\0')
    {
        if(k == -1 || t[j] == t[k])
        {
            j++;
            k++;
            if(t[j] != t[k])
                next[j] = k;
            else
                next[j] = next[k];
        }
        else
            k = next[k];
    }
}
/*
 * 第二种计算模式值的算法，便于理解，但是效率低于上面第一种，其next[n]的意义为：
 * 1.next[n]=-1 n一定是0，代表起始值，起标记作用
 * 2.next[n]=k>=0 表示下一次比较S[m]和T[k]
 */
void calNext2(char *t)
{
    int j, k;
    k = -1;
    j = 0;
    next[0] = -1;
    while(t[j] != '\0')
    {
        if(k == -1 || t[j] == t[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
}

int kmpIndex(char *s, char *t)
{
    int i, j, v, len;
    len = 0;
    //计算t串长度并显示next[]数组的值，便于对比分析
    while(t[len] != '\0')
    {
        printf("Next[%d]=%d; ", len, next[len]);
        len++;
    }
    printf("\n");

    i = 0;
    j = 0;
    while(s[i] != '\0' && j < len)
    {
        if(j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j >= len)
    {
        v = i - len;
    }
    else
        v = -1;
    return v;
}


int main()
{
    int rest;
    char *s = "ababcaababcaabc";
    char *t = "ababcaabc";

    calNext(t);
    rest = kmpIndex(s, t);
    calNext2(t);
    rest = kmpIndex(s, t);
    printf("String[%s] is index of string[%s], index = %d.\n", s, t, rest);
    return 0;
}



