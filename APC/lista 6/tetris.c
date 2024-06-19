#include <stdio.h>

void down(int n, int arr[n][n])
{
    int moved;
    do
    {
        moved = 0;
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = 0; j < n; j++)
            {
                if(arr[i][j] == 1 && arr[i+1][j] == 0)
                {
                    arr[i][j] = 0;
                    arr[i+1][j] = 1;
                    moved = 1;
                }
            }
        }
    } while(moved);
}


void empty(int n, int arr[n][n])
{
    int count;
    for(int i = 0; i < n; i++)
    {

        count = 0;

        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == 1) count++;
        }

        if(count == n) 
        {
            for(int j = 0; j < n; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
}

int main()
{
    int n, count;
    scanf("%d", &n);
    int arr[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    empty(n, arr);
    printf("\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    down(n, arr);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++)
    {
        count = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == 1) count++;
        }
        if(count == n) 
        {
            empty(n, arr);
            printf("\n");

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    printf("%d ", arr[i][j]);
                }
                printf("\n");
            }
            printf("\n");

            down(n, arr);

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    printf("%d ", arr[i][j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}