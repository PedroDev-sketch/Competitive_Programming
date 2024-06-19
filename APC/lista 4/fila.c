#include <stdio.h>

int main()
{
    int n, m, i;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &m);
    int arr2[m];
    for(i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    for(i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[j] == arr2[i])
            {
                arr[j] = 0;
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