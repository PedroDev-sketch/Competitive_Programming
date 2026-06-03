#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {int temp = a; a = b; b = temp;}

void insertion_sort(int * xs, int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = xs[i];
        int j = i - 1;
        
        while(j>=0 && xs[j] > key)
        {
            swap(xs[j], xs[j + 1]);
            j--;
        }
        xs[++j] = key;
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

    insertion_sort(xs, n);

    print_array(xs, n);

    free(xs);

    return 0;
}