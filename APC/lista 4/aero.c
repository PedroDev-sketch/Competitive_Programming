#include <stdio.h>

int main()
{
    int a = 0, v = 0, x = 1, y = 1, count = 0, answer = 0;
    while(1)
    {
        count++;
        scanf("%d %d", &a, &v);
        int arr[a];
        for(int i = 0; i < v; i++)
        {
            scanf("%d %d", &x, &y);
            if(x == 0 && y == 0)
            {
                break;
            }
        }
        /*for(int i = 0; i < v; i++)
        {
            if(i == 0) answer = arr[i];
            else if(answer > arr[i]) arr[i] = 0;
        }
        printf("Teste %d\n", count);
        for(int i = 0; i < a; i++)
        {
            printf("%d ", arr[i]);
        }*/
        
    }

    return 0;
}