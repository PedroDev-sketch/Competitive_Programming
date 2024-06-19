#include <stdio.h>

int main()
{
    int n, m, i, rem;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &m);
    for(i = 0; i < m; i++)
    {
        scanf("%d", &rem);
        for(int j = 0; j < n; j++)
        {
            if(arr[j] == rem)
            {
                arr[j] = 0;
                break;
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        if(arr[i] != 0)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}