#include <stdio.h>

int main()
{
    int n, count = 0;
    scanf("%d", &n);
    char gab[n+1], prova[n+1];
    scanf("%s", gab);
    scanf("%s", prova);
    for(int i = 0; i < n; i++)
    {
        if(gab[i] == prova[i]) count++;
    }
    printf("%d", count);
    return 0;
}