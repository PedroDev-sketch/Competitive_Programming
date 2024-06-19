#include <stdio.h>

int main()
{
    int a, v;
    int x, y, count = 0;
    scanf("%d %d", &a, &v);
    while(a != 0 && v != 0)
    {
        count++;
        int arr[a];
        for(int i = 0; i < v; i++)
        {
            scanf("%d %d", &x, &y);
            arr[x]++;
            arr[y]++;
        }
        for(int i = 0; i < a; i++) 
        {
            printf("%d ", arr[i]);
        }
        scanf("%d %d", &a, &v);
    }
    return 0;
}