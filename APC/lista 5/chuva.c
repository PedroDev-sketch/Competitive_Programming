#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int mapa1[n][n];
    int mapa2[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &mapa1[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &mapa2[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%d ", mapa1[i][j] + mapa2[i][j]);
        }
        printf("\n");
    }
    return 0;
}