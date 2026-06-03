#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define swap(a, b) {int temp = a; a = b; b = temp;}
#define oo 1000000000

int partition(int * xs, int l, int r)
{
    int x = xs[r];
    int i = l;

    for(int j = l; j <= r-1; j++)
    {
        if(xs[j] < x)
        {
            swap(xs[i], xs[j]);
            i++;
        }
    }

    swap(xs[i], xs[r]);
    return i;
}

void quick_sort(int * xs, int l, int r)
{
    if(l < r)
    {
        int index = partition(xs, l, r);

        quick_sort(xs, l, index-1);
        quick_sort(xs, index+1, r);
    }
}

void generate_array(int * xs, int n)
{
    for(int i = 0; i < n; i++)
    {
        xs[i] = rand() % 101;
        printf("%d ", xs[i]);
    }
    printf("\n");
}

void print_array(int * xs, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", xs[i]);
    }
    printf("\n");
}

int main()
{
    int n = 10;
    int * xs = malloc(n * sizeof(*xs));
    generate_array(xs, n);

    quick_sort(xs, 0, n - 1);

    print_array(xs, n);

    free(xs);

    return 0;
}