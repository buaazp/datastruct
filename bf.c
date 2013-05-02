#include <stdio.h>

#define ERROR -1
#define MAX 256


int getlen(char *s)
{
    int n = 0;
    int i = 0;
    while(s[i] != '\0')
    {
        i++;
    }
    return i;
}

int bf(char *s, char *t)
{
    int n, i, j, k;
    n = getlen(t);
    k = 0;
    while(s[k] != '\0')
    {
        i = k;
        j = 0;
        while(s[i] == t[j] && s[i] != '\0' && t[j] != '\0')
        {
            i++;
            j++;
        }
        if(t[j] == '\0')
            return k;
        else
        {
            k++;
        }
    }
    if(s[k] == '\0')
        return ERROR;
}


int main()
{
    int n;
    char *s = (char *)malloc(MAX * sizeof(char));
    char *t = (char *)malloc(MAX * sizeof(char));
    printf("s:");
    scanf("%s", s);
    printf("t:");
    scanf("%s", t);
    n = bf(s, t);
    if(n < 0)
    {
        printf("String '%s' is NOT in string '%s'.\n", t, s);
    }
    else
    {
        printf("String '%s' is in string '%s'. The location is %d.\n", t, s, n);
    }
    free(s);
    free(t);
    return 0;
}
