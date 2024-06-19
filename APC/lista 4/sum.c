#include <stdio.h>

int main()
{
    int n, comp = 0, seccomp = 0, thicomp = 0;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int j = 0; j < n; j++)
    {
        if(j == 0) comp = arr[j];
        else if(comp > arr[j]) comp = arr[j];
    }
    for(int x = 0; x < n; x++)
    {
        if(x == 0) seccomp = arr[x];
        else if(seccomp > arr[x] && arr[x] > comp)
        {
            seccomp = arr[x];
        }
    }
    for(int k = 0; k < n; k++)
    {
        if(k == 0) thicomp = arr[k];
        else if(thicomp > arr[k] && arr[k] > seccomp)
        {
            thicomp = arr[k];
        }
    }
    printf("%d\n", seccomp);
    printf("%d\n", thicomp);
    return 0;
}