#include <stdio.h>

int main()
{
    int n, m, maior = 0, sum = 0;
    scanf("%d %d", &n, &m);
    int campo[n][m];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &campo[i][j]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            sum += campo[i][j];
        }
        if(i == 0) maior = sum;
        else if(sum > maior) maior = sum;
        sum = 0;
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum += campo[j][i];
        }
        if(sum > maior) maior = sum;
        sum = 0;
    }

    printf("%d\n", maior);
    return 0;
}