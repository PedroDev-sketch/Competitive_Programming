#include <stdio.h>
#include <stdlib.h>

void insert(int * v, int start, int key)
{
    if(start <= 0 || v[start-1] <= key)
    {
        v[start] = key;
        return;
    }
    v[start] = v[start-1];
    insert(v, start-1, key);
}

void insertion_sort(int *v, int start, int n)
{
    if(start >= n) return;
    int key = v[start];

    insert(v, start, key);
    insertion_sort(v, start+1, n);
}

void ordena(int *v, int n)
{
    insertion_sort(v, 1, n);
}

/* int main()
{
    int num, i=0;
    int * arr;
    arr = malloc(1000 * sizeof(int));
    while(scanf("%d", &num) != EOF)
    {
        arr[i] = num;
        i++;
    }

    ordena(arr, i);

    for(int k = 0; k < i-1; k++) printf("%d ", arr[k]);
    printf("%d\n", arr[i-1]);

    free(arr);

    return 0;
} */