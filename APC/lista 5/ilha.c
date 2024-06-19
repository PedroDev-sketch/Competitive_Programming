#include <stdio.h>

int main()
{
    int n, x = 1;
    scanf("%d", &n);
    int map[n][n];

    if(n%2==0)    
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n/2; j++)
            {
                scanf(" %d", &map[i][j]);
            }
        }
    }

    else 
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n/2 + 1; j++)
            {
                scanf(" %d", &map[i][j]);
            }
        }
    }

    if(n % 2 == 0)
    {
        for(int i = 0; i < n; i++)
        {
            x = 1;
            for(int j = n/2; j < n; j++)
            {
                map[i][j] = map[i][j - x];
                x+= 2;
            }
        }
    }

    else
    {
        for(int i = 0; i < n; i++)
        {
            x = 2;
            for(int j = n/2 + 1; j < n; j++)
            {
                map[i][j] = map[i][j - x];
                x+=2;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}