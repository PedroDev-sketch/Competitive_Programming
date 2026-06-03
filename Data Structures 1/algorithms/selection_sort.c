#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {int temp = a; a = b; b = temp;}
#define oo 1000000000

void selection_sort(int * xs, int n)
{
    for(int i = 0; i < n; i++)
    {
        int small = oo;
        for(int j = i; j < n; j++)
        {
            if(xs[j] < small) {small = xs[j]; swap(xs[i], xs[j]);}
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

    selection_sort(xs, n);

    print_array(xs, n);

    free(xs);

    return 0;
}