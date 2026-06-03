#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {int temp = a; a = b; b = temp;}

void bubble_sort(int * xs, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(xs[j] < xs[j-1]) swap(xs[j], xs[j-1]);
        }
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

    bubble_sort(xs, n);

    print_array(xs, n);

    free(xs);

    return 0;
}