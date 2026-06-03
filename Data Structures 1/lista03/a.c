#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int * arr, int last)
{
    for(int i = 1; i < last; i++)
    {
        int key = arr[i], j = i - 1;
        for(; j >= 0; j--)
        {
            if(arr[j] > key)
            {
                arr[j+1] = arr[j];
            }
            else break;
        }

        arr[j+1] = key;
    }
}

int main()
{
    int num, i=0;
    int * arr;
    arr = malloc(1000 * sizeof(int));
    while(scanf("%d", &num) != EOF)
    {
        arr[i] = num;
        i++;
    }

    insertion_sort(arr, i);

    for(int k = 0; k < i-1; k++) printf("%d ", arr[k]);
    printf("%d\n", arr[i-1]);

    free(arr);

    return 0;
}